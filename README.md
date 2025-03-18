# Line Follower Robot

An autonomous line follower robot that uses IR sensors and PID control to follow a black line on a white surface. This project is implemented using an **Arduino Uno** (basic version) or **ESP32** (advanced version) and an **L298N motor driver**.

---

## Table of Contents
1. [Introduction](#introduction)
2. [Features](#features)
3. [Components](#components)
4. [Circuit Diagram](#circuit-diagram)
5. [Installation](#installation)
6. [Usage](#usage)
7. [Code Explanation](#code-explanation)
8. [Results](#results)
9. [Future Improvements](#future-improvements)
10. [Contributing](#contributing)
11. [License](#license)
12. [Acknowledgments](#acknowledgments)

---

## Introduction
The Line Follower Robot is an autonomous robot designed to follow a black line on a white surface using **IR sensors** and **PID control**. It is a great project for learning robotics, embedded systems, and control algorithms. The robot can be built in two versions:
- **Basic Version:** Uses an Arduino Uno and simple components.
- **Advanced Version:** Uses an ESP32, high-speed motors, and additional features like data logging and wireless communication.

---

## Features
- **Basic Version:**
  - Follows a black line on a white surface.
  - Uses 2 IR sensors for line detection.
  - PID control for smooth and accurate movement.
  - Powered by a lithium-ion battery.

- **Advanced Version:**
  - All features of the basic version.
  - High-speed motors with encoders for better performance.
  - SD card module for data logging.
  - ESP32 for Wi-Fi and Bluetooth connectivity.
  - Ultrasonic sensor for obstacle detection.
  - ML analysis and path prediciton for advanced PID controls enhancement 

---

## Components
### Basic Version
- Arduino Uno
- L298N Motor Driver
- 2 IR Sensors
- 2 Geared DC Motors (80-100 RPM)
- Lithium-Ion Battery (7.4V)
- Robot Chassis and Wheels
- Jumper Wires

### Advanced Version
- ESP32
- L298N Motor Driver (or BTS7960/VNH5019)
- 2 IR Sensors
- 2 High-Speed Geared DC Motors (>100 RPM) 
- Lithium-Ion Battery (11.1V)
- SD Card Module
- Ultrasonic Sensor (Optional)
- Robot Chassis and Wheels
- Jumper Wires

---

## Circuit Diagram
![Circuit Diagram](https://via.placeholder.com/800x600.png?text=Circuit+Diagram) <https://www.tinkercad.com/things/aCTpkUEMh1X-pid-control-line-follower-robot-/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard>

---

## Installation
1. **Hardware Setup:**
   - Assemble the robot chassis (a wooden case) and mount the motors, sensors, and microcontroller.
   - Connect the components as per the circuit diagram.

2. **Software Setup:**
   - Install the Arduino IDE from [arduino.cc](https://www.arduino.cc/).
   - For the ESP32, add the ESP32 board package to the Arduino IDE:
     ```
     https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_index.json
     ```
   - Upload the code to the microcontroller.

---

## Usage
1. Power on the robot using the lithium-ion battery.
2. Place the robot on a black line on a white surface.
3. The robot will autonomously follow the line using the IR sensors and PID control.

---

## Code Explanation
The code for the Line Follower Robot is divided into the following sections:
- **Setup:** Initializes the motor and sensor pins.
- **Loop:** Reads sensor data, calculates the error, and adjusts motor speeds using PID control.
- **PID Control:** Implements the Proportional-Integral-Derivative algorithm for smooth movement.

---

## Results
The robot successfully follows the black line on a white surface with smooth and accurate movements. The PID control ensures minimal oscillations and quick corrections.

---

## Future Improvements
- Add obstacle detection using an ultrasonic sensor.
- Implement wireless control using the ESP32's Wi-Fi/Bluetooth.
- Use a camera for advanced line detection and navigation.
- Add a display for real-time data visualization.

---

## Contributing
Contributions are welcome! If you'd like to contribute, please follow these steps:
1. Fork the repository.
2. Create a new branch for your feature/bugfix.
3. Commit your changes.
4. Submit a pull request.

---


## Acknowledgments
- Thanks to [Arduino](https://www.arduino.cc/) for providing an excellent platform for learning.
- Inspired by various robotics tutorials and projects available online.
- Thanks to [pcbway](https://www.pcbway.com/blog/Activities/Make_Arduino_Line_Follower_Robot_Car_with_Arduino_UNO__L298N_Motor_Driver__IR_Sensor.html) for giving an accurate model to follow for this project 

---
