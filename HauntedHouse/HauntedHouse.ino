void setup() {
  Serial.begin(9600);
  Serial.println("Ready");

}

void loop() {
  char inMessage = ' ';

  if (Serial.available())
  {
    inMessage = Serial.read();

    if (inMessage == '1') {
      turnOffAll();
      digitalWrite(2,HIGH);
    } else if (inMessage == '2') {
      turnOffAll();
      digitalWrite(4,HIGH);
    } else if (inMessage == '3') {
      turnOffAll();
      digitalWrite(7,HIGH);
    } else if (inMessage == '4') {
      turnOffAll();
      digitalWrite(8,HIGH);
    } else if (inMessage == '5') {
      turnOffAll();
      digitalWrite(12,HIGH);
    }

    delay(500);
  }

}

void turnOffAll(){
  digitalWrite(2,LOW);
  digitalWrite(4,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(12,LOW); 
}

