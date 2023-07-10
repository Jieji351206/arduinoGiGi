int SW = A0;
int led1 = A2;
int SWread = 0;

void setup() {
  pinMode(SW,INPUT);
  pinMode(led1,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  SWread = digitalRead(SW);
  if (SWread == HIGH) {
    Serial.println("Hello World");
    digitalWrite(led1, HIGH); //ถ้ากดปุ่ม ไฟจะติด
    delay(200);
  }
  else {
    Serial.println("Good Bye");
    digitalWrite(led1, LOW); //ถ้าไม่กดปุ่ม ไฟจะดับ
    delay(200);
  }
}
