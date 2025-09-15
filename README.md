# Fan_Control_using_NTC

This project demonstrates how to control a DC fan (simulated with an LED) using an Arduino Uno and a 10k NTC thermistor.  
The fan speed is adjusted based on temperature:

- **Temperature < 25°C → Fan OFF**  
- **25°C ≤ Temperature < 30°C → Fan at 50% speed (PWM)**  
- **Temperature ≥ 30°C → Fan at 100% speed**  

Temperature and fan state are printed live on the Serial Monitor.

---

## Hardware Used
- Arduino Uno
- 10kΩ NTC Thermistor
- 10kΩ Resistor (voltage divider)
- LED + 220Ω Resistor (fan simulation)
- Breadboard / Proteus for simulation

  ---
## Note

Due to the unavailability of some physical components, this project was implemented and tested using **Proteus simulation software**.  
The fan is simulated with an LED connected to pin D13, where its brightness represents the fan speed.  

For real hardware implementation:
-Use a transistor or motor driver to connect a DC fan.
-Pick a PWM pin (like D9, D10, or D11) instead of D13 for smoother control.

---

##  How It Works
1.Thermistor + 10k resistor form a voltage divider, output fed to A0.
2.Arduino calculates the temperature from the ADC value.
3.Depending on temperature, PWM output controls the LED/fan.
4.Serial Monitor shows temperature and fan status in real time.

---
## Project Structure
```
Fan_Control_using_NTC/
│── README.md
│── src/
│   └── fan.ino
│── docs/
│   └── How_Code_Works.md
│── images/
│   └── simulation_output.jpg
```
---
# Detailed Explanation

## 1. Thermistor Voltage Divider
- The thermistor (RT1, 10kΩ NTC) and a fixed resistor (R1, 10kΩ) form a voltage divider.  
- The divider output is connected to A0.  
- Voltage depends on thermistor resistance, which changes with temperature.

## 2. Temperature Calculation

The thermistor and a fixed 10kΩ resistor form a voltage divider.  
The Arduino reads the divider output on pin A0 (0–1023 from ADC).  

### 1. Resistance Calculation
The thermistor resistance (RT) is calculated as:

RT = R1 × (1023 / ADC - 1)

here:
RT = thermistor resistance (Ω)
R1 = fixed resistor (10kΩ)
ADC = analogRead(A0) result (0–1023)

### 2. B-Parameter Equation
To convert resistance into temperature, we use the B-parameter (simplified Steinhart–Hart) formula:

1/T = 1/T0 + (1/B) × ln(RT / R0)

here:
- T  = Temperature (Kelvin)
- T0 = 298.15 K (25°C)
- R0 = 10kΩ (resistance at 25°C)
- B  = 3900 (thermistor beta coefficient)

### 3. Celsius Conversion
Finally, temperature is converted to Celsius:

T(°C) = T(K) - 273.15

---
