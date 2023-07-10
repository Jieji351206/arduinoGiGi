int pin[] = {9,10,11};

void setup(){
  pinMode(pin[0], OUTPUT);
  pinMode(pin[1], OUTPUT);
  pinMode(pin[2], OUTPUT);
  attachInterrupt(1, blink, RISING);
  // เลข 1 คือ Interrupt หมายเลข 1 จะอยู่ที่ ขา3
  // blink คือ ชื่อฟังชันที่จะให้ไปทำ
  // RISING คือ ถ้าขา3 มีการเปลี่ยนสถานะจาก LOW เป็น HIGH ให้ทำในฟังก์ชั่น blink
}

void loop(){
    for(int i=0; i<=3; i++){
    digitalWrite(pin[i], HIGH);
    delay(500);
    digitalWrite(pin[i], LOW);
    delay(100);
  }
}

void blink(){
  digitalWrite(pin[0],HIGH);
  digitalWrite(pin[1],HIGH);
  digitalWrite(pin[2],HIGH);
  delay(5000);
}
