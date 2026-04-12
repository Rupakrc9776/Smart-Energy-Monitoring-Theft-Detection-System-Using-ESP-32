# ⚡ Smart Energy Monitoring & Theft Detection System

## 📌 Overview
[AICTE IDE](https://bootcamp.mic.gov.in/)  Bootcamp (Innovation, Design & Entrepreneurship), conducted from 06/04/2026 to 10/04/2026 under the Ministry of Education’s Innovation Cell (MIC)

At Dr. B. C. Roy Engineering College, Durgapur

Developed an ESP32-based system for real-time monitoring of voltage, current, and power, incorporating detection of abnormal energy usage (energy theft). The project was successfully completed and submitted with a fully functional working prototype.

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
- Rupak Chatterjee ([@Rupakrc9776](https://github.com/Rupakrc9776))
- Surjendu Mukherjee ([@surjendu02](https://github.com/surjendu02))
- Tirtha Mondal ([@Tirtha212](https://github.com/Tirtha212))
- Debayan Laha ([@debayan2005-prog](https://github.com/debayan2005-prog))
- Abir Kumar Laha ([@abirkumarlaha421-ai](https://github.com/abirkumarlaha421-ai))
- Chanchal Bhattacharjee ([@chanchal9641](https://github.com/chanchal9641))
- Akash Mukherjee ([@Skyfall-007-akash](https://github.com/Skyfall-007-akash))
- Marzanur Zaman ([@MARZANUR-ZAMAN](https://github.com/MARZANUR-ZAMAN))
- Subha Sarkar ([@suryagaming145](https://github.com/suryagaming145))

---

## 🎓 Mentor
- [Kingsuk Majumdar, Ph.D. (Engg)](https://github.com/KingsukMajumdar) 

---

## 🔒 Note on Circuit Design

The detailed circuit diagram of this project is not publicly disclosed due to intellectual property considerations.  
However, the system architecture and working principle are explained for academic purposes.

---

⭐ If you like this project, give it a star!
