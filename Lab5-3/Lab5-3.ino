#include <Servo.h>
Servo myservo; //ประกาศตัวแปรแทน Servo

int pin1 = 9;
int pin2 = 10;

void setup() {
  myservo.attach(A2); // กำหนดขาควบคุม Servo
  attachInterrupt(0, blink0, RISING);
  attachInterrupt(1, blink1, RISING);
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
}

void loop() {
  digitalWrite(pin1, LOW);
  digitalWrite(pin2, LOW);
  myservo.write(0); // สั่งให้ Servo หมุนไปองศาที่ 0
  delay(3000); // หน่วงเวลา 1000ms
}

void blink0() {
  digitalWrite(pin1, HIGH);
  myservo.write(90); // สั่งให้ Servo หมุนไปองศาที่ 90
}

void blink1() {
  digitalWrite(pin2, HIGH);
  myservo.write(180); // สั่งให้ Servo หมุนไปองศาที่ 180
}
