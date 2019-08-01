#include <SoftwareSerial.h>
#include <Servo.h>
Servo claw;
const int AIN1 = 7;
const int AIN2 = 4;
const int BIN1 = 2;
const int BIN2 = 3;
const int PWMA = 6;
const int PWMB = 5;
int motorSpeed = 0;
bool found = false;
bool turn = false;
SoftwareSerial serialTest(10,11);
void setup() {
  // put your setup code here, to run once:
pinMode(AIN1, OUTPUT);
pinMode(AIN2, OUTPUT);
pinMode(BIN1, OUTPUT);
pinMode(BIN2, OUTPUT);
Serial.begin(9600);
serialTest.begin(9600);
claw.attach(9);
claw.write(0);

}

/* ******************** Right Motor ******************** */

void rightMotor(int motorSpeed) {
  if (motorSpeed > 0) {
    digitalWrite(BIN2, HIGH);
    digitalWrite(BIN1, LOW);
  }
  else if (motorSpeed < 0) {
    digitalWrite(BIN2, LOW);
    digitalWrite(BIN1, HIGH);
  }
  else {
    digitalWrite(BIN1, LOW);
    digitalWrite(BIN2, LOW);
  }
  analogWrite(PWMA, abs(motorSpeed));
 
}
/*------------------ Left Motor ------------------*/
void leftMotor(int motorSpeed) {
if (motorSpeed > 0) {
  digitalWrite(AIN2, HIGH);
  digitalWrite(AIN1, LOW);
}
else if (motorSpeed < 0) {
  digitalWrite(AIN2, LOW);
  digitalWrite(AIN1, HIGH);
}
else {
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
}
analogWrite(PWMB, abs(motorSpeed));
}
/* *********************************************** */
void forward() {
  
  rightMotor(48);
  leftMotor(48);
  delay(200);
}

void backward() {
  rightMotor(-150);
  leftMotor(-150);
}

void left() {
  rightMotor(150);
  leftMotor(-150);  
}

void right() {
  rightMotor(-70);
  leftMotor(70);
}

void stop() {
  rightMotor(0);
  leftMotor(0);
}

void loop() {
//  // put your main code here, to run repeatedly:
  if (found == false) {
    right();
    if (serialTest.available() > 0) {
  //Serial.println(serialTest.read());
    int marker = int(serialTest.read());
    Serial.println(marker);
      if (marker == 49) {
        int photo = analogRead(A0);
        photo = map(photo, 585,780,0,10);
        photo = constrain(photo,0,10);
        if (photo < 6){
          if (turn == false) {
            right();
            delay(100);
            turn = true;
          }
          else {
          forward();
          Serial.println(photo);
          }
          
        }
        else if (photo >= 6){
          Serial.println(photo);
          stop();
          delay(1000);
          claw.write(50);
          delay(1000);
          stop();
          found=true;
        
  }
      }
      else {
    //int marker = 48;
        //Serial.println("done");
        
  }
  
}
 
}
 
}
 





 
