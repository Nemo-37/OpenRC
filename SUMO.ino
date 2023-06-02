#include <Ultrasonic.h>
#define PIN_PHOTO_SENSOR1 A0
#define PIN_PHOTO_SENSOR3 A2
#define PIN_ENA 6      // Вывод управления скоростью вращения мотора №1
#define PIN_ENB 5      // Вывод управления скоростью вращения мотора №2
#define PIN_IN1 3      // Вывод управления направлением вращения мотора №1
#define PIN_IN2 2      // Вывод управления направлением вращения мотора №1
#define PIN_IN3 7      // Вывод управления направлением вращения мотора №2
#define PIN_IN4 4      // Вывод управления направлением вращения мотора №2
uint8_t power = 255;   // Значение ШИМ (или скорости движения)
uint8_t power1 = 255;  // Значение ШИМ (или скорости врашения)
Ultrasonic ultrasonic(12, 13);
int distance; 
int sensor1 = 300;  //срабатывание первого сенсора 700
int sensor3 =100;  //срабатывниие третьего сенсора 300
void setup() {
  pinMode(11, OUTPUT);
  Serial.begin(9600);
  // Установка всех управляющих пинов в режим выхода
  pinMode(PIN_ENA, OUTPUT);
  pinMode(PIN_ENB, OUTPUT);
  pinMode(PIN_IN1, OUTPUT);
  pinMode(PIN_IN2, OUTPUT);
  pinMode(PIN_IN3, OUTPUT);
  pinMode(PIN_IN4, OUTPUT);
  // Команда остановки двум моторам
}
void loop() {
  digitalWrite(11, HIGH);
  int sen1 = analogRead(PIN_PHOTO_SENSOR1);
  int sen3 = analogRead(PIN_PHOTO_SENSOR3);
  distance = ultrasonic.read();
  if (sen1 < sensor1) {                // Первый датчик (фоторезистор)
    analogWrite(PIN_ENA, power - 50);       // Устанавливаем скорость 1-го мотора
    analogWrite(PIN_ENB, power);            // Устанавливаем скорость 2-го мотора
    // Задаём направление для 1-го мотора
    digitalWrite(PIN_IN1, HIGH);
    digitalWrite(PIN_IN2, LOW);
    // Задаём направление для 2-го мотора
    digitalWrite(PIN_IN3, HIGH);
    digitalWrite(PIN_IN4, LOW);
    delay(1000);
  }
  if (sen3 < sensor3) {                // Второй датчик (фоторезистор)
    analogWrite(PIN_ENA, power);            // Устанавливаем скорость 1-го мотора
    analogWrite(PIN_ENB, power - 50);       // Устанавливаем скорость 2-го мотора
    // Задаём направление для 1-го мотора
    digitalWrite(PIN_IN1, HIGH);
    digitalWrite(PIN_IN2, LOW);
    // Задаём направление для 2-го мотора
    digitalWrite(PIN_IN3, HIGH);
    digitalWrite(PIN_IN4, LOW);
    delay(1000);
  }

  if (distance < 60) {
    analogWrite(PIN_ENA, power);  // Устанавливаем скорость 1-го мотора
    analogWrite(PIN_ENB, power);  // Устанавливаем скорость 2-го мотора
    // Задаём направление для 1-го мотора
    digitalWrite(PIN_IN1, LOW);    // Задаем направление для первого мотора
    digitalWrite(PIN_IN2, HIGH);   
    digitalWrite(PIN_IN3, LOW);   // Задаем направление для второго мотора
    digitalWrite(PIN_IN4, HIGH);
    //if (distance < 5) {
      //digitalWrite(PIN_IN1, HIGH);  // команда остановки двух мотором
      //digitalWrite(PIN_IN2, HIGH);
      //digitalWrite(PIN_IN3, HIGH);
      //digitalWrite(PIN_IN4, HIGH);
      // Задаём направление для 1-го мотора
      //digitalWrite(PIN_IN1, LOW);
      //digitalWrite(PIN_IN2, HIGH);
      // Задаём направление для 2-го мотора
      //digitalWrite(PIN_IN3, HIGH);
      //digitalWrite(PIN_IN4, LOW);
      //delay(200);
    //}
  }

  else {
    analogWrite(PIN_ENA, power1);  // Устанавливаем скорость 1-го мотора
    analogWrite(PIN_ENB, power1);  // Устанавливаем скорость 2-го мотора
    digitalWrite(PIN_IN1, HIGH);    // Задаем направление для первого мотора
    digitalWrite(PIN_IN2, LOW);   
    digitalWrite(PIN_IN3, LOW);   // Задаем направление для второго мотора
    digitalWrite(PIN_IN4, HIGH);
  }
}
