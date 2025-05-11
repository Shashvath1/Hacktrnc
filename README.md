# 🔌 Smart Automation System - Arduino & ESP32 Based

This project is a collection of Arduino and ESP32 scripts designed to automate and monitor a smart environment. It includes **motion detection**, **motor and LED control**, **simulated AC control**, **ESP32-based communication**, and **multi-microcontroller integration**.

---

## 📁 Repository Contents

| File                        | Description                                                                 |
|-----------------------------|-----------------------------------------------------------------------------|
| `ESP32.ino`                 | ESP32 control logic (possibly WiFi/Bluetooth-enabled control or data transfer) |
| `arduino_uno.ino`           | Arduino UNO main control script – handles core logic or sensor interfacing |
| `controlunit.ino`           | A central unit code possibly coordinating between modules or devices       |
| `motion detection and count.ino` | Detects motion via PIR sensor and counts events                    |
| `motorled_dec14a.ino`       | Controls a DC motor and LEDs – used for visual indicators or movement |
| `simulate AC.ino`           | Simulates Air Conditioner behavior (on/off, timing, sensor trigger, etc.)  |

---

## 🧠 Core Features

- 🧍‍♂️ **Motion Detection**: Uses sensors to detect presence and count events (for automation or security).
- 🔄 **Motor + LED Control**: Motor-driven actions (e.g. door opening, fans) with LED status indicators.
- 🌬️ **Simulated Air Conditioning**: Demonstrates basic AC control logic using Arduino.
- 📡 **ESP32 Integration**: Enables wireless communication (via WiFi or Bluetooth) to interface with web/dashboard.
- 🔁 **Modular Design**: Each `.ino` file represents a module that can function independently or as part of a larger system.

---

## 🔌 Hardware Requirements

- ESP32 Dev Module
- Arduino UNO
- L298N Motor Driver
- PIR Motion Sensor
- Relay Module (for AC simulation)
- DC Motor
- LEDs
- Jumper Wires, Breadboard

---

## 🧪 How to Use

### 1. Upload code to respective boards:
- `ESP32.ino` → Upload using **Arduino IDE**, board: **ESP32 Dev Module**
- `arduino_uno.ino`, `controlunit.ino`, etc. → Upload to **Arduino UNO**

### 2. Connect hardware as per each sketch’s logic:
- For motion detection: connect PIR sensor to Arduino
- For motor control: use L298N with PWM pins
- For simulate AC: connect relay and control using logic from sketch

### 3. Power boards via USB or external adapter and observe behavior.

---

## 🧾 Notes

- Make sure the correct board and COM port are selected in the Arduino IDE.
- If using ESP32 WiFi features, update `SSID` and `PASSWORD` in the sketch.
- Each file is modular. You can combine multiple functionalities under `controlunit.ino`.

---

## 📌 Possible Enhancements

- Add MQTT for remote monitoring
- Integrate with Blynk or custom web app for mobile control
- Add real-time clock (RTC) for scheduling

---

## 👨‍💻 Authors

- SHASHVATH R
  
- Contributors and testers
- MEGHANA H S

---

