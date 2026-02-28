# LPG Gas Leakage Detection with Load Monitoring System

## Aim
To detect LPG gas leakage and monitor the weight of gas cylinder using MQ2 gas sensor and Load Cell.

## Components Used
- MQ2 Gas Sensor
- Load Cell
- HX711 Amplifier Module
- ESP8266 NodeMCU
- Jumper Wires
- Blynk IoT Platform

## Working Principle
The MQ2 gas sensor detects LPG gas concentration in ppm.
The Load Cell measures the weight of the LPG cylinder.
HX711 module amplifies the load cell signal.
ESP8266 processes sensor data and sends it to Blynk IoT dashboard.
If gas concentration exceeds threshold value (100 ppm), buzzer is activated.

## Output
- Gas leakage alert generated when ppm > 100
- Cylinder weight displayed in Blynk IoT dashboard
- Buzzer activated during gas leak detection

## Application
- Home LPG safety monitoring
- Industrial gas leakage detection
- Smart kitchen safety system
## Blynk IoT Dashboard

Blynk IoT platform is used for real-time monitoring of LPG gas leakage and cylinder weight.

### Dashboard Features
- Real-time Gas Level (PPM) Display
- Cylinder Weight Monitoring
- Gas Leakage Alert LED Indicator
- Buzzer Notification
- Remote Monitoring using Mobile App

ESP8266 NodeMCU sends sensor data to Blynk cloud for live visualization.

Virtual Pins Used:

V0 - Gas Level (PPM) Display
V1 - Leak Detection Message Label
V2 - Gas Leak Alert LED Indicator
V3 - System ON/OFF Button
V4 - Cylinder Weight Display
V5 - Low Gas Level Warning Message
