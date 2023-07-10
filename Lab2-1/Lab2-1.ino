int i = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()>0){
    char In = Serial.read();
    Serial.print("num i:");
    Serial.println(i);
    Serial.print("Count data:");
    Serial.println(Serial.available());
    Serial.print("character");
    Serial.print(In);
    delay(1000);
    i++;
  }

}
