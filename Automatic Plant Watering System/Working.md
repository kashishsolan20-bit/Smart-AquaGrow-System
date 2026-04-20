# WORKING

The Automatic Plant Watering System using Arduino operates by continuously monitoring soil moisture levels and automatically controlling irrigation based on predefined conditions.

## 1. Power Supply
The system is powered by a 12V power supply connected to the Arduino board. A voltage regulator is used to provide stable DC power suitable for the Arduino Uno.

## 2. Sensor Reading
A capacitive soil moisture sensor is connected to an analog input pin of the Arduino. It detects the moisture level present in the soil.

## 3. Moisture Calculation
The analog values received from the sensor are converted into moisture percentage using predefined air and water threshold values.

## 4. LCD Display
The calculated moisture percentage is displayed on a 16x2 LCD module connected to the Arduino.

## 5. Relay Control
The Arduino controls a relay module based on moisture levels:
- If moisture < 30% → Relay ON → Pump ON (Irrigation starts)
- If moisture > 70% → Relay OFF → Pump OFF

## 6. Pump Status Display
The LCD displays pump status:
- "Pump: ON" → When irrigation is active  
- "Pump: OFF" → When moisture is sufficient  

## 7. Continuous Monitoring
The Arduino continuously:
- Reads sensor values  
- Updates display  
- Controls pump accordingly  

## 8. Automatic Irrigation
The pump supplies water until the soil reaches the desired moisture level. This ensures plants receive the right amount of water even in the absence of the user.

---

**Conclusion:**  
This system automates plant watering efficiently, improves plant health, and reduces manual effort.
