# Smart Pressure Alert System (Arduino & Tinkercad)

## 📋 Project Overview
This project is an **Embedded System** designed to monitor physical pressure in real-time and provide immediate multi-sensory feedback (visual, auditory, and haptic) when a specific threshold is exceeded. The system was simulated and built using **Tinkercad** and programmed in **C++** for the Arduino microcontroller.

It can be applied in various real-world scenarios, such as weight-limit alerts for industrial machinery, posture correction devices, or interactive smart-home interfaces.

---

## 🛠 Hardware Architecture & Components
The circuit is built around an **Arduino Uno** and utilizes several key electronic components to read environmental data and trigger outputs:

* **Force Sensitive Resistor (FSR):** Acts as the primary input sensor. Its physical resistance decreases as pressure is applied to its surface. Connected in a voltage divider configuration with a pull-down resistor, it sends an analog voltage signal to the Arduino's `A0` pin.
* **RGB LED:** Provides visual status indication. It is connected to PWM-enabled pins (`8`, `9`, `10`) with current-limiting resistors to protect the LED from burning out.
* **Piezo Buzzer:** Connected to digital pin `12`, it provides auditory feedback (an alarm) when the pressure limit is breached.
* **DC Vibration Motor & NPN Transistor:** Connected to pin `3`. Since a vibration motor draws more current than a standard Arduino digital pin can safely supply, an **NPN Transistor** is used as an electronic switch. The Arduino sends a low-current signal to the transistor's base, which then allows a higher current to flow from the power source to the motor.

---

## 💻 Software Logic
The logic is written in C++ and continuously monitors the analog input from the FSR. The analog read maps the voltage to a value between 0 and 1023.

**Operational States:**
1. **Safe State (Pressure $\le$ 750):** 
   * The RGB LED displays a **Purple** color by mixing the Red (PWM 128) and Blue (PWM 128) channels.
   * The Piezo Buzzer remains silent.
   * The Vibration motor is off.
3. **Alert State (Pressure > 750):**
   * The system detects an overload.
   * The RGB LED switches to a solid, bright **Red** (PWM 255).
   * The Buzzer is activated (`HIGH`) to sound an alarm.
   * The Vibration Motor is activated (`HIGH`) to provide strong haptic feedback.

---

## 🚀 How to Run the Simulation
1. Visit the live Tinkercad simulation here: `https://www.tinkercad.com/things/jiWnB9ApNUs-panagiwtkz`
2. Click on **Start Simulation**.
3. Click on the **Force Sensitive Resistor (FSR)** and adjust the pressure slider.
4. Observe the system's reaction as the pressure crosses the coded threshold.

---

## 📂 Repository Contents
* `pressure_alert_system.ino` - The complete Arduino C++ source code.
* `circuit_diagram.png` - Visual representation of the breadboard wiring.
