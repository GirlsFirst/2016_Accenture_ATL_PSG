#include <OneSheeld.h>

float distance = 0;
char charVal[2];

#include <Servo.h>
Servo servoRight;
Servo servoLeft;

int trigPin = 3;
int echoPin = 4;

void setup() {
  OneSheeld.begin();
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  servoLeft.attach(12);
  servoLeft.writeMicroseconds(1500);
  servoRight.attach(13);
  servoRight.writeMicroseconds(1500);
}

void forward(){
  servoLeft.writeMicroseconds(1300);
  servoRight.writeMicroseconds(1700);
}

void backward(){
  servoLeft.writeMicroseconds(1700);
  servoRight.writeMicroseconds(1300);
}

void leftTurn(){
  servoLeft.writeMicroseconds(1700);
  servoRight.writeMicroseconds(1700);
}

void rightTurn(){
  servoLeft.writeMicroseconds(1300);
  servoRight.writeMicroseconds(1300);
}

void still(){
  servoLeft.writeMicroseconds(1500);
  servoRight.writeMicroseconds(1500);
}

void loop() {
  long duration, distance;
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  
  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1;

  if (distance >= 21 || distance <= 0){
    forward();
  }

  else if (distance <= 20){
    still();
    dtostrf(distance, 2, 0, charVal);
    TextToSpeech.say("watch out");
    delay(1000);
    TextToSpeech.say("object about");
    delay(1000);
    TextToSpeech.say(charVal);
    delay(1000);
    TextToSpeech.say("centimeters away.");
    leftTurn();
    delay(400);
  }
}