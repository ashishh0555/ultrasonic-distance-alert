# Smart Multi-Level Distance Alert System using Arduino

## 📌 Description

This project measures distance using an ultrasonic sensor and provides real-time alerts using LEDs and a buzzer.
It implements **multi-level proximity detection with time-based validation**, making the system more reliable and resistant to false triggers.

---

## 🧰 Components Used

* Arduino Uno
* HC-SR04 Ultrasonic Sensor
* Buzzer
* 2 LEDs (Red + Green)
* Resistors
* Jumper wires

---

## ⚙️ Working Logic

The system behaves based on object distance:

### 🔴 Distance < 10 cm (Danger Zone)

* Red LED ON
* Continuous buzzer
* Indicates immediate proximity (high risk)

---

### ⚠️ Distance between 10–30 cm (Warning Zone)

* Red LED BLINKS
* Buzzer beeps intermittently
* Indicates moderate proximity

---

### 🟢 Distance > 30 cm (Safe Zone)

* Green LED ON
* No buzzer
* Indicates safe condition

---

## ⏱️ Time-Based Validation (Key Feature)

The system triggers alerts **only if an object remains within 30 cm for more than 3 seconds**.

### Why this matters:

* Reduces false triggers
* Filters out momentary noise
* Improves system stability and reliability

---

## 🔄 Non-Blocking Design

The system uses `millis()` instead of `delay()` for:

* LED blinking
* buzzer control
* timing logic

This ensures smooth and efficient real-time operation.

---

## 🔌 Pin Configuration

| Component | Arduino Pin |
| --------- | ----------- |
| TRIG      | 9           |
| ECHO      | 10          |
| Buzzer    | 8           |
| Red LED   | 7           |
| Green LED | 13          |

---

## 📷 Project Setup

![Setup](setup.jpg)

---

## 🎥 Demo Video

[Watch Video](https://youtube.com/shorts/I22JAEUiMpQ?feature=share)

---

## 💻 Code

The complete Arduino code is available in:
`ultrasonic_alert.ino`

---

## 🚀 Features

* Real-time distance measurement
* Multi-level alert system
* Time-based filtering for stability
* Non-blocking execution using `millis()`
* Visual + audio feedback

---

## 🧠 System Design

**Input → Processing → Output**

* Input: Ultrasonic Sensor
* Processing: Distance calculation + time validation + threshold logic
* Output: LED indicators + buzzer alerts

This demonstrates a basic **embedded system with multi-level decision making**.

---

## 📊 Design Decisions

* Thresholds (10 cm, 30 cm) chosen for practical alert ranges
* 3-second delay improves reliability by avoiding false alarms
* Red LED indicates danger/warning, Green LED indicates safe state
* Non-blocking logic ensures efficient execution

---

## 💡 Learning Outcomes

* Sensor integration (HC-SR04)
* Real-time embedded logic design
* Time-based event handling using `millis()`
* Multi-level decision systems
* Hardware-software interaction

---

## 🔧 Future Improvements

* Add LCD display for live distance
* Add adjustable threshold using potentiometer
* Integrate IoT for remote monitoring
* Build enclosure for real-world deployment

---
