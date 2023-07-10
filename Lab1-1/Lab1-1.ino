int led1 = A2;      // คือ ขา IO16 A2

void setup() {
  pinMode(led1,OUTPUT);
  
}

void loop() {
  digitalWrite(led1,LOW);
  delay(500);
  digitalWrite(led1,HIGH);
  delay(500);
}
