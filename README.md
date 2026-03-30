# 🌱 Smart Irrigation System using ESP8266 & Blynk

## 📌 Overview
This project is an IoT-based Smart Irrigation System that monitors soil moisture levels and sends real-time notifications when the soil becomes dry. The system allows users to manually control a water pump using the Blynk mobile application.

---

## 🚀 Features
- 🌱 Real-time soil moisture monitoring
- 📲 Instant mobile notification alerts (via Blynk)
- 🔘 Manual motor ON/OFF control from mobile app
- 📊 Live data display on dashboard
- 🔄 Reliable WiFi-based communication
- 🧠 Spam-protected notification system

---

## 🧰 Components Used
- ESP8266 (NodeMCU)
- Soil Moisture Sensor
- Relay Module (5V)
- Water Pump (DC)
- Battery / Power Supply
- Jumper Wires

---

## 🔌 Circuit Connections

### 🌱 Soil Moisture Sensor → ESP8266
| Sensor Pin | ESP8266 Pin |
|-----------|------------|
| VCC       | 3.3V       |
| GND       | GND        |
| AO        | A0         |

---

### 🔌 Relay Module → ESP8266
| Relay Pin | ESP8266 Pin |
|----------|------------|
| VCC      | Vin        |
| GND      | GND        |
| IN       | D1         |

---

### 💧 Pump + Battery + Relay
| Connection | Description |
|----------|------------|
| Battery (+) → COM | Power input |
| NO → Pump (+)     | Controlled output |
| Pump (-) → Battery (-) | Complete circuit |

---

## ⚙️ Working Principle
1. The soil moisture sensor continuously reads soil conditions.
2. If the soil becomes dry (value above threshold):
   - A notification is sent to the Blynk app.
3. The user receives the alert and can:
   - Turn ON the water pump using the app button.
4. Once watering is complete, the user can turn OFF the pump.

---

## 📱 Blynk Setup Guide (Step-by-Step)

Follow these steps to configure the Blynk IoT platform for this project:

---

### 🔧 Step 1: Install Blynk App

Download and install the Blynk IoT app from Play Store or App Store.

---

### 🧩 Step 2: Create Template

1. Open Blynk Console (web dashboard)
2. Click on **"New Template"**
3. Fill details:

   * Template Name: `Soil Monitor`
   * Hardware: `ESP8266`
   * Connection Type: `WiFi`
4. Click **Create**

---

### 🔌 Step 3: Create Datastreams

Go to **Datastreams → New Datastream → Virtual Pin**

#### 1. Soil Moisture Value

* Name: `Soil Value`
* Virtual Pin: `V0`
* Data Type: Integer
* Min: 0
* Max: 1023

#### 2. Motor Control

* Name: `Motor Control`
* Virtual Pin: `V1`
* Data Type: Integer
* Min: 0
* Max: 1

---

### 🔔 Step 4: Create Event (Notification)

Go to **Events → New Event**

* Event Name: `soil_low`
* Description: `Soil moisture is LOW`
* Enable:

  * ✔ Send Push Notification
  * ✔ Send to Device Owner

---

### 📱 Step 5: Setup Mobile Dashboard

1. Open Blynk mobile app
2. Login using same account
3. Open your device

Add widgets:

* 🔘 Button → Assign to `V1` (Switch mode)
* 📊 Value Display / Gauge → Assign to `V0`

---

### 🔑 Step 6: Get Auth Token

1. Go to **Devices**
2. Select your device
3. Copy **Auth Token**
4. Paste it in your Arduino code

---

### 🚀 Step 7: Run the Project

1. Upload code to ESP8266
2. Power the device
3. Open Blynk app

✔ Soil dry → Notification received
✔ Button ON → Motor starts
✔ Button OFF → Motor stops

---

### ⚠️ Important Notes

* Make sure WiFi credentials are correct
* Ensure event name in code matches exactly: `soil_low`
* Enable mobile notification permission
* Keep app logged in

---


## 📷 Circuit Diagram
![Circuit Diagram](your-image-file-name.jpg)

> Replace `your-image-file-name.jpg` with your uploaded image file name.

---

## 🧪 Testing
- Dry soil → Notification received
- Button ON → Pump starts
- Button OFF → Pump stops

---

## ⚠️ Safety Notes
- Do not connect AC pump directly without proper isolation
- Use proper power supply for relay and pump
- Avoid keeping sensor in water continuously (prevents corrosion)

---

## 🔮 Future Improvements
- Automatic irrigation mode
- Water level monitoring
- LCD display integration
- Data logging and analytics

---

## 👨‍💻 Author
**Anirudhdha Poriya**  
IoT Developer | Kre8IoT

---

## ⭐ Support
If you like this project, please ⭐ star the repository!
