# HealthSense: ESP32-AI Health Monitoring System

---

Welcome to the HealthSense project! This intelligent monitoring system leverages affordable hardware and cloud-based AI to provide real-time health data analysis, prediction, and anomaly detection. Designed for proactive health insights, it collects vital environmental and physiological data, processes it with machine learning, and alerts users to potential issues.

## Features

Our HealthSense system offers comprehensive monitoring and alerting capabilities:

* **Multi-Sensor Data Collection:** Real-time acquisition of data from:
    * **Gas Sensors:** Monitor ambient air quality or specific gas levels (e.g., MQ series sensors for CO, Methane, LPG).
    * **Heart Rate Sensor:** Track physiological heart rate data (e.g., Pulse Sensor, MAX30102).
* **Cloud-based Machine Learning:** Data is securely sent to a powerful Google Colab server for advanced analysis.
* **Predictive Modeling:** ML models forecast future trends or health states based on the collected data.
* **Outlier Detection:** Intelligent algorithms identify unusual or anomalous readings that could indicate a deviation from normal patterns.
* **Real-time Alerting:** Upon detection of significant predictions or outliers, an immediate alert is triggered via a buzzer on the ESP32 client, ensuring timely notification.

## How It Works

The HealthSense system operates on a robust **client-server architecture**:

* **Server (Cloud-based):** The AI heavy lifting is performed on a powerful server running on **Google Colab**. This server utilizes **Flask** for its web framework and **Ngrok** to create a secure, publicly accessible tunnel to the client. This setup allows for scalable and efficient processing of complex AI models, including predictive and outlier detection algorithms.
* **Client (Edge Device):** An **ESP32** microcontroller serves as the compact and portable client. It's connected to various sensors (gas, heart rate) that collect data. The ESP32 client transmits this sensor data to the server, receives the AI-processed results (predictions, outlier flags), and activates a buzzer for alerts.

```mermaid
graph TD
    A[Gas Sensors] --> B(ESP32 Client);
    C[Heart Sensor] --> B;
    B -- Sensor Data --> D{Internet / Ngrok Tunnel};
    D --> E[Google Colab Server];
    E --> F(Flask ML Backend);
    F -- Predictions / Outliers --> E;
    E --> D;
    D --> B;
    B --> G[Buzzer Alert];
