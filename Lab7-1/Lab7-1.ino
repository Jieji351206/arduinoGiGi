#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);
#include "DHT.h"
DHT dht;

#define SCREEN_WIDTH 128 // pixel ความกว้าง
#define SCREEN_HEIGHT 64 // pixel ความสูง
#define OLED_RESET     -1 //ขา reset เป็น -1 ถ้าใช้ร่วมกับขา Arduino reset
Adafruit_SSD1306 OLED(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  
  dht.setup(13);

  Serial.begin(9600);
  if (!OLED.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // สั่งให้จอ OLED เริ่มทำงานที่ Address 0x3C
    Serial.println("SSD1306 allocation failed");
  } else {
    Serial.println("ArdinoAll OLED Start Work !!!");
  }
}

void loop() {
  delay(dht.getMinimumSamplingPeriod());
  float humidity = dht.getHumidity(); // ดึงค่าความชื้น
  float temperature = dht.getTemperature(); // ดึงค่าอุณหภูมิ

  OLED.clearDisplay(); // ลบภาพในหน้าจอทั้งหมด
  OLED.setTextColor(WHITE, BLACK);  //กำหนดข้อความสีขาว ฉากหลังสีดำ

  OLED.setCursor(0, 0); // กำหนดตำแหน่ง x,y ที่จะแสดงผล
  OLED.setTextSize(1); // กำหนดขนาดตัวอักษร
  OLED.print("Temp:"); // แสดงผลข้อความ ALL
  OLED.print(temperature);
  OLED.println("c");
  OLED.print("Humi:");
  OLED.print(humidity);
  OLED.println("%");

  OLED.display(); // สั่งให้จอแสดงผล
  delay(1000);

}
