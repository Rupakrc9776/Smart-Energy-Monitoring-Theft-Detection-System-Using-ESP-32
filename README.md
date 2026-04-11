# ⚡ Smart Energy Monitoring & Theft Detection System

## 📌 Overview
This project is based on ESP32 for real-time monitoring of voltage, current, and power. It also detects abnormal energy usage (theft).

## 🔧 Components Used
- ESP32 Development Board
- SCT-013 Current Sensor
- ZMPT101B Voltage Sensor
- SSD1306 OLED Display
- LED Indicators
- Buzzer
- Resistors

## 🚀 Features
- Real-time voltage, current, power monitoring
- OLED display output
- Blynk IoT integration
- Theft detection using threshold
- Alert via LED, buzzer & mobile

## ⚙️ Working Principle
1. Sensors measure voltage and current
2. ESP32 processes data and calculates power
3. Data is displayed on OLED screen
4. Data is sent to Blynk app via WiFi
5. If current exceeds threshold → Theft alert triggered
6. Buzzer and LED indicate alert condition

## ▶️ How to Run
1. Install Arduino IDE
2. Install ESP32 board package
3. Install required libraries:
   - Blynk
   - Adafruit SSD1306
   - Adafruit GFX
4. Upload code to ESP32
5. Connect hardware as per circuit
6. Open Serial Monitor / Blynk app

## 🔮 Future Improvements/Scope
- Smart meter integration  
- Cloud data storage  
- AI-based anomaly detection  
- Mobile notification system upgrade

## 📱 Blynk Datastreams
- V0 → Voltage
- V1 → Current
- V2 → Power
- V3 → Theft Alert

---

## 📸 Project Images

### 🙏 Our TeamName Animation
<p align="center">
  <img src="https://github.com/user-attachments/assets/ee65aa96-484f-446b-af04-1aea3bdfe42d" width="300"/>
</p>

---

### 🔌 Hardware Setup
<p align="center">
  <img src="https://github.com/user-attachments/assets/21c0804d-04ab-47a6-8174-03ebdd5b4453" width="300"/>
</p>
<p align="center"><b>Fig 2:</b> Complete hardware setup of the system</p>

---

### 🖥 OLED Output (Normal Condition)
<p align="center">
  <img src="https://github.com/user-attachments/assets/cbbb57cf-ac07-4d64-b226-347d5932c80c" width="300"/>
</p>
<p align="center"><b>Fig 3:</b> OLED displaying voltage, current and power values</p>

---

### 🚨 Theft Detection Alert
<p align="center">
  <img src="https://github.com/user-attachments/assets/157b6d3f-d00f-40d1-895d-7fb74a53854c" width="300"/>
</p>
<p align="center"><b>Fig 4:</b> Theft condition showing alert with buzzer and LED</p>

---

### ☠️ Circuit Connetions
<p align="center">
  <img src="https://github.com/user-attachments/assets/997618c6-c60c-450f-ac46-798e08e3b565" width="300"/>
</p>
<p align="center"><b>Fig 5:</b> Circuit Connections under real Working Condition</p>

---

## 👨‍💻 Team Members
- Rupak Chatterjee
- Surjendu Mukherjee ([@surjendu02](https://github.com/surjendu02))
- Tirtha Mondal
- Debayan Laha
- Abir Kumar Laha
- Chanchal Bhattacharjee ([@chanchal9641](https://github.com/chanchal9641))
- Akash Mukherjee
- Marzanur Zaman
- Subha Sarkar ([@suryagaming145](https://github.com/suryagaming145))

---

## 🎓 Mentor
- Kingsuk Majumdar,Ph.D (Engg)

---

## 🔒 Note on Circuit Design

The detailed circuit diagram of this project is not publicly disclosed due to intellectual property considerations.  
However, the system architecture and working principle are explained for academic purposes.

---

⭐ If you like this project, give it a star!
