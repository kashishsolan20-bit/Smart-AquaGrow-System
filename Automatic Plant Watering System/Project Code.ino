# PROJECT CODE

#include <Wire.h>  
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int sensor_pin = A0;    // Sensor Pin
int relay_pin = 7;      // Relay Pin

void setup()
{
  Serial.begin(9600);        // Start serial monitor
  
  pinMode(relay_pin, OUTPUT); // Set relay as output
  
  lcd.init();                
  lcd.backlight();           

  lcd.setCursor(0,0);
  lcd.print("System Starting");
  delay(2000);
  lcd.clear();
}

void loop()
{
  int sensor_data = analogRead(sensor_pin);

  Serial.print("Sensor_data: ");
  Serial.print(sensor_data);
  Serial.print(" | ");

  // DRY SOIL
  if(sensor_data > 950)
  {
    Serial.println("Soil Dry");
    digitalWrite(relay_pin, LOW);  // Pump ON

    lcd.setCursor(0,0);
    lcd.print("Soil: Dry   ");
    lcd.setCursor(0,1);
    lcd.print("Pump: ON    ");
  }

  // MEDIUM MOISTURE
  else if(sensor_data >= 400 && sensor_data <= 950)
  {
    Serial.println("Soil Medium");
    digitalWrite(relay_pin, HIGH); // Pump OFF

    lcd.setCursor(0,0);
    lcd.print("Soil: Medium");
    lcd.setCursor(0,1);
    lcd.print("Pump: OFF   ");
  }

  // WET SOIL
  else if(sensor_data < 400)
  {
    Serial.println("Soil Wet");
    digitalWrite(relay_pin, HIGH); // Pump OFF

    lcd.setCursor(0,0);
    lcd.print("Soil: Wet   ");
    lcd.setCursor(0,1);
    lcd.print("Pump: OFF   ");
  }

  delay(1000);
}
