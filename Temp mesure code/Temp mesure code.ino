#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

LiquidCrystal_I2C LCD(0x27, 16, 2);
DHT CAP(7,  DHT11);

void setup() {
  Wire.begin();
  CAP.begin();
  LCD.init();
  LCD.backlight();
  LCD.setCursor(0,0);
  LCD.print("Hello");
  LCD.setCursor(0,1);
  LCD.print("Project by yssf");
  delay(1000);
}

void loop() {
  float temp = CAP.readTemperature();
  float hum = CAP.readHumidity();
  LCD.clear();
  LCD.setCursor(0,0);
  LCD.print("Temp = " + String(temp) + "C");
  LCD.setCursor(0,1);
  LCD.print("Hum = " + String(hum) + "%");
  delay(500);
}
