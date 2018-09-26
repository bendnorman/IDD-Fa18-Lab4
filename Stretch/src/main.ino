#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 90;    // variable to store the servo position

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(A0, INPUT);
  myservo.write(pos);
  
  Serial.begin(9600);
}

void loop() {
  int pulldown = analogRead(A0);
  Serial.println(pulldown);
  
  if (pulldown < 800 && pos < 90) {
      pos+=1; // Go down
  }
  if (pulldown > 800 && pos > 0 ) {
      pos-=3;
  }
  myservo.write(pos);
  
  delay(130);
}
