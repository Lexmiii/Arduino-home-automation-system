# Arduino Home Automation System

This project is an **Arduino-based home automation system** that brings together multiple sensors and a Bluetooth module to detect smoke, flame, and rain. It also allows you to control certain outputs from your smartphone.  

The idea behind this project was to learn how sensors interact with microcontrollers and how Bluetooth can be used for simple wireless control. Along the way, I explored how to combine hardware and software into a small but useful system.

---

## Components Used
- Arduino Uno  
- MQ-2 Smoke Sensor  
- Flame Sensor  
- Rain Sensor  
- HC-05 Bluetooth Module  
- LEDs (Green and Red)  
- Buzzer  
- Jumper wires and breadboard  

---

## Features
- Detects smoke, flame, and rain in real time.  
- Alerts the user through a buzzer and LEDs.  
- Sends messages to a paired smartphone over Bluetooth.  
- Simple commands (`G`, `0`, `B`) let the user control the LED and mute the buzzer.  
- Sensor readings are also printed in the Arduino IDE Serial Monitor.  

---

## Project Setup

### Circuit Diagram
![Circuit Diagram](https://github.com/Lexmiii/Arduino-home-automation-system/blob/main/circuit%20diagram.jpeg?raw=true)

### Hardware Build
![Hardware Setup](project.jpg)

### Demo
![Demo](demo.gif)

---

## Code
The full Arduino sketch is available here: [home_automation.ino](home_automation.ino)  

### Bluetooth Commands
| Command | Action |
|---------|--------|
| `G`     | Turn **Green LED ON** |
| `0`     | Turn **Green LED OFF** |
| `B`     | Mute the buzzer |

---

## How to Run
1. Connect the sensors and modules as shown in the circuit diagram.  
2. Open `home_automation.ino` in the Arduino IDE and upload it to the Arduino Uno.  
3. Pair your phone with the HC-05 module (default PIN is `1234` or `0000`).  
4. Open a Bluetooth terminal app (I used *Serial Bluetooth Terminal*).  
5. Send the commands `G`, `0`, or `B` to interact with the system.  
6. Monitor sensor values in the Serial Monitor at 9600 baud.  

---

## Future Improvements
- Add relays to control real appliances.  
- Move to ESP32 or NodeMCU for IoT and Wi-Fi connectivity.  
- Create a simple mobile app instead of relying on a terminal.  
- Store readings in the cloud for data logging and analysis.  

---

## Author
Created by **[Your Name]** as a learning project in Arduino, sensors, and basic IoT concepts.  

---

## Support
If you found this project helpful, please ⭐ the repository and share it with others.  
