## Introduction

Factories and industrial workplaces often overlook the health risks associated with harsh working environments. Lack of attention to these issues can lead to serious health problems for workers and compromise their overall well-being. This project aims to develop an IoT-based monitoring system that tracks various environmental factors, detects potential hazards, and alerts supervisors in real-time, ensuring better workplace conditions and improving worker health and safety.

## Problem Statement

With the rise in industrial growth, there are increasing concerns over the health of workers and the environmental impact of industrial workplaces. Without adequate monitoring, dangerous situations such as gas leaks, temperature fluctuations, or fire hazards may go unnoticed, endangering employees' health and safety. This project seeks to address these challenges and create a safer working environment through continuous monitoring.

## Objectives

- Ensure consistent and reliable data transmission for real-time monitoring.
- Create an intuitive web interface for accessible and easy-to-understand real-time data tracking.
- Implement security measures for the web interface to safeguard sensitive information.
- Enable immediate detection of gas leaks and fire hazards.
- Send instant email alerts for gas leakage and fire detection to prevent accidents.
- Improve overall workplace safety, health, and productivity by minimizing risks.

## Tools and Technologies

- **NodeMCU (ESP8266)**: A microcontroller used to control and manage the entire monitoring system.
- **DHT11 Sensor**: Measures temperature and humidity levels in the environment.
- **MQ135 Sensor**: Detects hazardous gases like Carbon Monoxide (CO) and Carbon Dioxide (CO2).
- **MQ2 Gas Sensor**: Detects flammable gases, including LPG, methane, and smoke.
- **IR Sensor**: Flame detection sensor used to monitor fire hazards.
- **Arduino IDE**: The development platform used to program the NodeMCU microcontroller.
- **HTML/CSS**: Frontend web development languages for creating the user interface.
- **ThingSpeak**: An IoT platform to store and visualize the data in real-time.
- **SMTP Mail Server**: Used to send email alerts for detected gas leaks or fire hazards.

## Features

- **Real-time Data Monitoring**: The system constantly monitors environmental conditions (temperature, humidity, gas levels, and fire hazards) and updates the data in real-time.
- **Gas Leak Detection**: The system detects dangerous gas leaks such as CO, CO2, and flammable gases and sends an instant email alert to designated recipients.
- **Fire Detection**: The system is equipped with flame sensors to detect fires. If a fire is detected, an immediate alert is sent via email.
- **Web Interface**: An accessible and secure web interface allows users to view real-time data and monitor system status.
- **Email Alerts**: Automated email notifications for gas leakage and fire detection to ensure prompt actions can be taken.
  
## Result and Discussion

- **Improved Safety**: By continuously monitoring environmental factors, the system prevents potential hazards and improves worker safety.
- **Real-time Alerts**: Instant email notifications for gas leakage or fire events allow for quick intervention and response, preventing major accidents.
- **Enhanced Work Conditions**: The system helps ensure that workplaces remain within safe operational conditions, reducing the risk of health issues.
- **Increased Productivity**: By minimizing risks, the system contributes to a healthier, safer work environment, which ultimately boosts overall productivity.

## How to Run the Project

1. **Hardware Setup**:
   - Connect the sensors (DHT11, MQ135, MQ2, IR sensor) to the NodeMCU microcontroller according to the wiring diagram.
   - Ensure that the NodeMCU is properly connected to your Wi-Fi network for remote monitoring.

2. **Software Setup**:
   - Download and install the [Arduino IDE](https://www.arduino.cc/en/software).
   - Install the necessary libraries for the sensors and NodeMCU.
   - Upload the code to the NodeMCU using the Arduino IDE.

3. **Web Interface**:
   - Create a web page using HTML and CSS to display the real-time data from ThingSpeak.
   - Use the ThingSpeak API to retrieve data from the sensors and display it on the web interface.

4. **SMTP Email Configuration**:
   - Set up the SMTP mail server with your email credentials.
   - The system will send email alerts for gas leaks or fire detection.

5. **Run the Project**:
   - After setting up the hardware and software, power up the system.
   - Access the web interface to monitor real-time data.
   - The system will automatically detect any gas leak or fire and send email alerts as needed.
