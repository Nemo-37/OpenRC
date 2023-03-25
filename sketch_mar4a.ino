void setup() {
  pinMode(10,OUTPUT);
}

void loop() {
  for(int a=0; a<255; a++)
  {
    analogWrite(10, a);
    delay(15);
    
  }
  delay(100);
}
