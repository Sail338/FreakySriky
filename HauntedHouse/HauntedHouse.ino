#include <Servo.h>

Servo servoBed;
Servo servoFrame;

void setup() {
  Serial.begin(9600);
  Serial.println("Ready");
  pinMode(13, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(12, OUTPUT); //Initiates Motor Channel A pin
  pinMode(9, OUTPUT); //Initiates Brake Channel A pin
  
  servoBed.attach(5);
  servoBed.write(75);
  servoFrame.attach(6);
  servoFrame.write(75);
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

void pictureFrame(){
  servoFrame.write(50);
  delay(300);
  servoFrame.write(90);
  delay(300);
}

void corpse(){
  servoBed.write(0);
  delay(3000);
  servoBed.write(75);
  delay(500);
}

void lightsOut(int len){
  digitalWrite(11, LOW);
  delay(len);
  digitalWrite(11, HIGH);
}

void buzz(){
  digitalWrite(12, HIGH); //Establishes forward direction of Channel A
  digitalWrite(9, LOW);   //Disengage the Brake for Channel A
  analogWrite(3, 255);   //Spins the motor on Channel A at full speed
  
  delay(3000);
  
  digitalWrite(9, HIGH); //Eengage the Brake for Channel A
  delay(1000);
}

void flicker(){
  constantFlicker(500, 300, "1");
  constantFlicker(300,500, "2");
  constantFlicker(100, 1000, "3");
}

void constantFlicker(int len, int rate, String a){
  int startProgram = millis();
  int startFunction = startProgram;
  int timeLength = len + startFunction;
  int flickerRate = rate;
  if(flickerRate < 50) flickerRate = 50;
  
  while((startFunction-startProgram) < timeLength){
    startFunction = millis();
    digitalWrite(13, HIGH);
    Serial.print(a);
    delay(rate);
    digitalWrite(13, LOW);
    Serial.print(a);
    delay(rate);
  }
}



