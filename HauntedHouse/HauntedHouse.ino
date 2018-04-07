void setup() {
  Serial.begin(9600);
  Serial.println("Ready");

}

void loop() {
  char inMessage = ' ';

  if (Serial.available())
  {
    inMessage = Serial.read();
    Serial.println(inMessage);
    digitalWrite(12,HIGH);
  }

  delay(100);
  
}
