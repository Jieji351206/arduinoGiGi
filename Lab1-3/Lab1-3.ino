int R = 2;
int G = 3;
int B = 4;
int pot1 = 1;
int pot2 = 2;
int pot3 = 3;
int RV,GV,BV;

void setup() {
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(pot1,OUTPUT);
  pinMode(pot2,OUTPUT);
  pinMode(pot3,OUTPUT);
}

void loop() {
  RV = map(analogRead(pot1),0,1023,0,255);
  GV = map(analogRead(pot2),0,1023,0,255);
  BV = map(analogRead(pot3),0,1023,0,255);
  analogWrite(9,RV);
  analogWrite(10,GV);
  analogWrite(11,BV);
}
