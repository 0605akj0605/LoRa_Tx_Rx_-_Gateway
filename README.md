
# 🌱 Prototype of a Multi-Node LoRa IoT System with Cloud-Connected Dashboard for Real-Time Monitoring

> **Author:** Aditya Krishna Jaiswal
> **Institution:** Indian Institute of Information Technology Guwahati 
> **Mentor:** Dr. Anjan Debnath, Scientist-F, North Eastern Space Applications Centre, Department of Space, Government of India

---

## 📌 Overview

This project explores the design and implementation of a **multi-node IoT sensor network** using LoRa technology, paired with a **cloud-based PostgreSQL database** and an **interactive real-time dashboard**.
It demonstrates how long-range, low-power wireless communication (LoRa) can be combined with modern cloud tools to create scalable, cost-effective environmental monitoring systems.

---

## ⚙️ Key Features

* 📡 **Multi-node LoRa network** with temperature, humidity, and landslide alert sensors
* 🛠 **Hardware**: Wio-E5 development boards (STM32WLE5JC), DHT11 sensors, ESP8266 Wi-Fi modules
* ☁️ **Cloud integration**: Real-time data upload to Supabase PostgreSQL database
* 📊 **Dashboard**: Live visualization with maps and charts (built using Next.js, Leaflet.js, Chart.js)
* 🔧 **AT command-based LoRa communication** for rapid prototyping with Wio E-5 Development report.
* 🧪 **Simulated landslide detection** using push-button events

---

## 📦 Project Structure

```plaintext
.
├── /docs                  # Schematics, wiring diagrams, and report
├── /firmware
│   ├── transmitter/       # Arduino Nano code for sensor nodes
│   └── receiver/          # ESP8266 code for cloud upload
├── /dashboard             # Frontend: Next.js app
└── README.md
```

---

## 🛠 Hardware Used

* **LoRa AI Thinker 2** (based on SX127X) modules
* **Wio-E5 Development Boards (STM32WLE5JC SoC)**
* **DHT11**: Temperature & humidity sensor
* **ESP8266**: Adds Wi-Fi capability to the receiver for cloud integration
* **Arduino Nano**: Reads sensors and formats LoRa packets
* Push-button: Simulates landslide alerts

---

## 📡 Network Architecture

* Star topology with multiple transmitter nodes sending data to a central LoRa receiver.
* Receiver forwards parsed data to the cloud database.

Each LoRa packet has a fixed format:
`{II, TT, HH, L}`
Where:

* `II`: Node ID
* `TT`: Temperature
* `HH`: Humidity
* `L`: Landslide alert (0 or 1)

Example: `0125600`

---

## ☁️ Cloud & Dashboard

* **Supabase**: Stores sensor data in a managed PostgreSQL database
* **Frontend**: Built with Next.js, Leaflet.js (map), Chart.js (charts)
* **Backend**: Serverless API using Node.js & Vercel
* **Real-time**: Supabase subscriptions + WebSocket updates

---

## 📊 Example Dashboard Features

* Live geospatial visualization of sensor nodes
* Real-time temperature and humidity graphs
* Landslide alert status
* Interactive, single-page design

---

## 🧪 Key Learnings

* Importance of integrated RF hardware (Wio-E5 outperformed bare Ai-Thinker modules)
* Benefit of using BaaS (Supabase) to simplify backend work
* Incremental, modular project development aids troubleshooting

---

## 🚀 Future Enhancements

* Migrate to full **LoRaWAN** with Network Server (e.g., The Things Stack)
* Deploy in real-world environments (farmland, hilly areas)
* Power optimization: deep sleep modes for end-nodes
* Add more sensors: soil moisture, air quality, accelerometers

---

## 📚 References

* [Semtech - What is LoRa?](https://www.semtech.com/lora/what-is-lora)
* [LoRa Alliance](https://lora-alliance.org/)
* [Wio-E5 Development Board Wiki](https://wiki.seeedstudio.com/LoRa_E5_Dev_Board/)
* [Supabase](https://supabase.com/)
* [STM32WLE5JC SoC](https://www.st.com/en/microcontrollers-microprocessors/stm32wle5jc.html)

Full list in [report bibliography](https://github.com/0605akj0605/LoRa_Tx_Rx_-_Gateway).

---

## 📥 Source Code & Report

🔗 [GitHub Repository](https://github.com/0605akj0605/LoRa_Tx_Rx_-_Gateway)

---

## 🙏 Acknowledgement

Special thanks to:

* Dr. Anjan Debnath (NE-SAC)
* Pratham Agarwal (friend & collaborator)
* Team Antriksha: Krish Kahnani, Keshav Jindal

---


