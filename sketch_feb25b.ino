#include <Servo.h>
Servo servo1;
int lightSensor = 0; 
int lightSensor1 = 0;

void setup() {
pinMode(0 ,OUTPUT);
pinMode(4 ,OUTPUT);
servo1.attach(8);
Serial.begin (9600);
}

void loop() {
  lightSensor1 = analogRead(A1);
  lightSensor = analogRead(A0);
  Serial.println(lightSensor);
  Serial.println(lightSensor1);
  delay(10);
if (lightSensor > 600) {
  digitalWrite(4, HIGH);
  servo1.write (130);
}
else {
  digitalWrite(4, LOW);
  digitalWrite(0, LOW);
  servo1.write (95);
}
if (lightSensor1 > 600) {
  digitalWrite(0, HIGH);
  servo1.write(50);
}

}