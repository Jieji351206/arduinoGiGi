#include <Wire.h>
#include <LiquidCrystal_I2C.h> /*include LCD I2C Library*/
LiquidCrystal_I2C lcd(0x27, 16, 2); /*I2C scanned address defined + I2C screen size*/
#include "DHT.h"
DHT dht;

void setup() {
  Serial.begin(9600);
  Serial.println();
  Serial.println("Status\tHumidity (%)\tTemperature (C)\t(F)");
  dht.setup(A2); // data pin 2
  lcd.init();
  lcd.backlight();
}

void loop() {
  delay(dht.getMinimumSamplingPeriod());
  float humidity = dht.getHumidity(); // ดึงค่าความชื้น
  float temperature = dht.getTemperature(); // ดึงค่าอุณหภูมิ

  Serial.print(dht.getStatusString());
  Serial.print("\t");
  Serial.print(humidity, 1);
  Serial.print("\t\t");
  Serial.print(temperature, 1);
  Serial.print("\t\t");
  Serial.println(dht.toFahrenheit(temperature), 1);
  
  lcd.setCursor(2, 0); //ฟังก์ชั่นในการกำหนดตำแหน่ง Cursor
  lcd.print("Temp:"); //แสดงค่าความซื้นบนLCD
  lcd.setCursor(7, 0);
  lcd.print(temperature);
  lcd.setCursor(13, 0);
  lcd.print("c");

  lcd.setCursor(2, 1); //ฟังก์ชั่นในการกำหนดตำแหน่ง Cursor
  lcd.print("Humi:"); //แสดงค่าอุณหภูมิบนLCD
  lcd.setCursor(7, 1);
  lcd.print(humidity);
  lcd.setCursor(13, 1);
  lcd.print("%");
  
}
