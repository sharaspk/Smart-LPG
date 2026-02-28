#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "Gas Monitoring"
#define BLYNK_AUTH_TOKEN "YOUR_AUTH_TOKEN"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "HX711.h"

char ssid[] = "YOUR_WIFI";
char pass[] = "YOUR_PASSWORD";

#define MQ2 A0

#define DT D5
#define SCK D6

HX711 scale;

BlynkTimer timer;

int gasThreshold = 400;
bool systemON = true;
bool leakAlertSent = false;
bool lowAlertSent = false;

float calibration_factor = -7050; // Change after calibration

BLYNK_WRITE(V3)
{
  systemON = param.asInt();
}

void checkSensors()
{
  if (!systemON) return;

  // MQ2 Reading
  int gasValue = analogRead(MQ2);
  Blynk.virtualWrite(V0, gasValue);

  if (gasValue > gasThreshold)
  {
    Blynk.virtualWrite(V1, "⚠️ GAS LEAK DETECTED");
    Blynk.virtualWrite(V2, 255);

    if (!leakAlertSent)
    {
      Blynk.logEvent("gas_alert", "Gas Leak Detected!");
      leakAlertSent = true;
    }
  }
  else
  {
    Blynk.virtualWrite(V1, "Gas Normal");
    Blynk.virtualWrite(V2, 0);
    leakAlertSent = false;
  }

  // Load Cell Reading
  float weight = scale.get_units(5);
  if (weight < 0) weight = 0;

  Blynk.virtualWrite(V4, weight);

  if (weight <= 100)
  {
    Blynk.virtualWrite(V5, "⚠️ LOW GAS LEVEL");
    if (!lowAlertSent)
    {
      Blynk.logEvent("low_gas", "Cylinder Low Level!");
      lowAlertSent = true;
    }
  }
  else
  {
    Blynk.virtualWrite(V5, "Gas Level OK");
    lowAlertSent = false;
  }
}

void setup()
{
  Serial.begin(9600);
  
  scale.begin(DT, SCK);
  scale.set_scale(calibration_factor);
  scale.tare();

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  timer.setInterval(2000L, checkSensors);
}

void loop()
{
  Blynk.run();
  timer.run();
}
