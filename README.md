# Smart Home Automation System with Arduino (Small-Scale Version)



##  Project Objective
The goal of this project is to design a compact smart home system using an Arduino microcontroller that automates basic household functions: temperature and ventilation control, automatic lighting based on presence and light intensity, NFC-based access security, and window blind control. The system serves as a functional prototype for educational and experimental purposes, demonstrating home automation principles in a modular, expandable format.

##  System Features
* **Temperature and Ventilation Control:** Measures room temperature and humidity with a DHT11/DHT22 sensor. Automatically activates a fan when temperature exceeds a threshold and turns it off once cooled. The threshold is adjustable in code or via interface.
* **Lighting Control (Presence & Brightness):** Detects motion via a PIR sensor; turns the lamp ON/OFF automatically based on ambient light (LDR). Turns off the lamp after inactivity (e.g., 5 minutes). Optional manual override is available via a button or command.
* **Security & NFC Access System:** Provides door access using NFC cards via an RC522 reader. Grants/denies access with LEDs and a buzzer. Includes a magnetic door sensor; triggers an alarm if there is unauthorized entry.
* **Blind and Window Automation:** Controls a blind motor based on light intensity (LDR). Manual up/down control via buttons is also supported.
* **System Monitoring and Display:** Displays temperature, humidity, and states on an LCD/OLED. Optionally sends data via Wi-Fi to a mobile app.

##  Feature Priority Levels
| Priority | Function | Description |
| :--- | :--- | :--- |
| Level 1 (Essential) | Lighting + motion detection  | Demonstrates basic automation and energy saving. |
| Level 1 (Essential) | Temperature + ventilation  | Core comfort and climate control. |
| Level 1 (Essential) | NFC access control  | Provides basic smart security[cite: 30]. |
| Level 2 (Important) | Blind/window automation  | Enhances usability and realism. |
| Level 3 (Optional) | Data monitoring/display  | Adds visual feedback and IoT extension. |



##  Hardware Overview & Circuit Assembly
* **Central Unit:** Arduino Uno/Mega 2560, USB cable, breadboard, jumper wires(5-10m), 10 kΩ resistors, 5 V power supply.
* **Sensors & Actuators:** DHT11/DHT22, PIR, LDR, RC522, magnetic sensor, servo/DC motor, relays (x4), LEDs, buzzer, LCD/OLED.
* **Assembly:** All components are mounted on a breadboard. Sensors connect to Arduino digital/analog pins; relays connect to outputs. High-power devices (motors/fans) use a 12 V supply with a shared ground. LEDs and a buzzer provide feedback; the display shows live data.

### Current Pin Mapping (Based on codebase)
| Component | Arduino Pin | Notes |
| :--- | :--- | :--- |
| **PIR Sensor** | Digital 5 | Input |
| **DHT11 Sensor** | Digital 4 | Input |
| **Push Button** | Digital 6 | `INPUT_PULLUP` |
| **Buzzer** | Digital 3 | Output |
| **LED** | Digital 2 | Output |
| **Relay 1 (Light)** | Digital 8 | Active Low |
| **Relay 2 (Window)**| Digital 9 | Active Low |
| **RFID RST** | Digital 7 | |
| **RFID SDA (SS)** | Digital 53 | SPI SS Pin (Mega) |
| **LCD I2C** | SDA/SCL | Address: `0x3F` (or `0x24`) |

##  System Operation
Startup initializes sensors and thresholds.Lighting and climate respond automatically. NFC ensures security, blinds adjust with light, and the display shows status. Subsystems work autonomously but coordinate via the Arduino loop.

##  Extension Possibilities
The modular design allows: Wi-Fi control via ESP8266, voice-command integration, gas detection (MQ-2), and multi-room expansion.

---
**Conclusion**
The Smart Home Automation System is a compact Arduino-based prototype combining energy efficiency, comfort, and security. It’s suitable for education or demonstrations, with potential for IoT, wireless monitoring, and multi-room expansion.




*(Note: Minor timing/logic optimizations assisted by Gemini AI)*





# Author : Zahaleanu Ioan David
