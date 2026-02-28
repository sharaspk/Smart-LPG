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
