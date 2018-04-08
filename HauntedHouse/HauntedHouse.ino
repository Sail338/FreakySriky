#include <Servo.h>

Servo servoBed;
Servo servoFrame;

void setup() {
  Serial.begin(9600);
  Serial.println("Ready");
  pinMode(13, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(12, OUTPUT); //Initiates Motor Channel A pin
  pinMode(9, OUTPUT); //Initiates Brake Channel A pin
  
  servoBed.attach(10);
  servoBed.write(0);
  servoFrame.attach(11);
  servoFrame.write(90);
}

void loop() {
  char inMessage = ' ';

  if (Serial.available())
  {
    inMessage = Serial.read();

    if (inMessage == '1') {

    } else if (inMessage == '2') {
      corpse();
    } else if (inMessage == '3') { 

    } else if (inMessage == '4') {
      flicker();
    } else if (inMessage == '5') {
      pictureFrame();
    }

    while (Serial.read() >= 0)
    ;
    delay(2000);
    
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
  servoFrame.write(70);
  delay(300);
  servoFrame.write(110);
  delay(300);
  servoFrame.write(70);
  delay(300);
  servoFrame.write(110);
  delay(300);
  servoFrame.write(70);
  delay(300);
  servoFrame.write(110);
  delay(300);
  servoFrame.write(90);
  delay(300);
}

void corpse(){
  servoBed.write(75);
  delay(2000);
  servoBed.write(0);
  delay(300);
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
  //constantFlicker(300,500, "2");
  //constantFlicker(100, 1000, "3");
}

void constantFlicker(int len, int rate, String a){
  int startProgram = millis();
  int startFunction = startProgram;
  int timeLength = len + startFunction;
  int flickerRate = rate;
  if(flickerRate < 50) flickerRate = 50;
  
  while((startFunction-startProgram) < timeLength){
    startFunction = millis();
    digitalWrite(2, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(4, HIGH);
    Serial.print(a);
    delay(rate);
    digitalWrite(2, LOW);
    digitalWrite(7, LOW);
    digitalWrite(4, LOW);
    Serial.print(a);
    delay(rate);
  }
}



