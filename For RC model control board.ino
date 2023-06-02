#include <Servo.h>
Servo servo;

void setup() {
  pinMode(2, OUTPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(13, OUTPUT);
  servo.attach(12);
}

void loop() {
 
  if (digitalRead(3) == HIGH) {
    servo.write(40);
    delay(10);
    for (int i = 100; i <= 255; i++) {
      analogWrite(11, i);
      delay(10);
      if ((digitalRead(3) == LOW)) break;
    }
  }
  if (digitalRead(6) == HIGH) {
    servo.write(140);
    delay(10);
    for (int i = 100; i <= 255; i++) {
      analogWrite(11, i);
      delay(10);
      if ((digitalRead(6) == LOW)) break;
    }
  }
  if(digitalRead(7) == HIGH){
    for (int i = 100; i <= 255; i++) {
      analogWrite(11, i);
      delay(10);
      if ((digitalRead(7) == LOW)) break;
    }
  }

  else {
    analogWrite(11, 0);
    servo.write(90);
  }
}

