int RGBPin[] = {A0,A1,A2};
int i = 0;
void setup() {
  pinMode(RGBPin[0],OUTPUT);
  pinMode(RGBPin[1],OUTPUT);
  pinMode(RGBPin[2],OUTPUT);
  Serial.begin(9600);
}

void loop() {
char In = Serial.read();
  
    if(In == 'a'){
      Serial.println("a");
      color(255,0,0);
      delay(200);
    }else if(In == 's'){
      Serial.println("s");
      color(0,255,0);
      delay(200);
    }else if(In == 'd'){
      Serial.println("d");
      color(0,0,255);
      delay(200);
    }else if(In == 'f'){
      Serial.println("f");
      color(255,255,255);
      delay(200);
    }
  
}

void color(int R ,int G ,int B) {
  analogWrite(RGBPin[0],R);
  analogWrite(RGBPin[1],G);
  analogWrite(RGBPin[2],B);
}
