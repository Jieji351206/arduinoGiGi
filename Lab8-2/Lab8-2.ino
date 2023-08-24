#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run make menuconfig to and enable it
#endif

BluetoothSerial SerialBT;

int ledR = 13;
int ledY = 12;
int ledG = 14;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("Gigi"); //Bluetooth device name
  Serial.println("The device started, now you can pair it with bluetooth!");
  pinMode (ledR, OUTPUT);
  pinMode (ledY, OUTPUT);
  pinMode (ledG, OUTPUT);
  
}

void loop() {
 if (SerialBT.available()) {
    char command = SerialBT.read(); // Read the incoming command
    
    // Check the command and adjust the LED colors accordingly
    if (command == 'r') {
      turnOnRed();
    } else if (command == 'g') {
      turnOnGreen();
    } else if (command == 'b') {
      turnOnBlue();
    } else if (command == 'y') {
      turnOnYellow();
    } else if (command == 'a') {
      turnOnAllColors();
    } else if (command == 'f') {
      turnOffAllColors();
    }
  }
}
void turnOnRed() {
  analogWrite(ledR, 0);
  analogWrite(ledY, 0);
  analogWrite(ledG, 255);
}
void turnOnGreen(){
  analogWrite(ledR, 0);
  analogWrite(ledY, 255);
  analogWrite(ledG, 0);
}
void turnOnBlue(){
  analogWrite(ledR, 255);
  analogWrite(ledY, 0);
  analogWrite(ledG, 0);
}
void turnOnYellow() {
  analogWrite(ledR, 0);
  analogWrite(ledY, 255);
  analogWrite(ledG, 255);
}

void turnOnAllColors() {
  analogWrite(ledR, 255);
  analogWrite(ledY, 255);
  analogWrite(ledG, 255);
}

void turnOffAllColors() {
  analogWrite(ledR, 0);
  analogWrite(ledY, 0);
  analogWrite(ledG, 0);
}
