int rightBlink = 10; //blue led plugged into pin 10
int leftBlink = 9; //green led plugged into pin 9
const int echo = 11;
const int trig = 12;
const int AIN1 = 7;
const int AIN2 = 4;
const int BIN1 = 2;
const int BIN2 = 3;
const int PWMA = 6;
const int PWMB = 5;
float distance = 0;
int motorSpeed = 0;
void setup() {
  // put your setup code here, to run once:
pinMode(rightBlink, OUTPUT);
pinMode(leftBlink, OUTPUT);
pinMode(echo, INPUT);
pinMode(trig, OUTPUT);
pinMode(AIN1, OUTPUT);
pinMode(AIN2, OUTPUT);
pinMode(BIN1, OUTPUT);
pinMode(BIN2, OUTPUT);
Serial.begin(9600);

}
/* ******************** Right Motor ******************** */

void rightMotor(int motorSpeed) {
  if (motorSpeed > 0) {
    digitalWrite(AIN1, HIGH);
    digitalWrite(AIN2, LOW);
  }
  else if (motorSpeed < 0) {
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, HIGH);
  }
  else {
    digitalWrite(AIN1, LOW);
    digitalWrite(AIN2, LOW);
  }
  analogWrite(PWMA, abs(motorSpeed));
 
}
/*------------------ Left Motor ------------------*/
void leftMotor(int motorSpeed) {
if (motorSpeed > 0) {
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
}
else if (motorSpeed < 0) {
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
}
else {
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
}
analogWrite(PWMB, abs(motorSpeed));
}
void forward() {
  rightMotor(100);
  leftMotor(100);
}

void backward() {
  rightMotor(-150);
  leftMotor(-150);
}

void left() {
  digitalWrite(leftBlink, HIGH);
  delay(200);
  digitalWrite(leftBlink, LOW);
  delay(200);
  digitalWrite(leftBlink, HIGH);
  delay(200);
  digitalWrite(leftBlink, LOW);
  delay(200);
  rightMotor(150);
  leftMotor(-150);
  
}

void right() {
  digitalWrite(rightBlink, HIGH);
  delay(200);
  digitalWrite(rightBlink, LOW);
  delay(200);
  digitalWrite(rightBlink, HIGH);
  delay(200);
  digitalWrite(rightBlink, LOW);
  delay(200);
  rightMotor(-150);
  leftMotor(150);

}

void stop() {
  rightMotor(0);
  leftMotor(0);
}
void loop() {
  // put your main code here, to run repeatedly:
distance = getDistance();
Serial.println(distance);
 if (distance < 5) {
    //Serial.println(distance);
    stop();
    delay(1000);
    right();
    delay(480);
    stop();
    delay(2000);
    distance = getDistance();
    if (distance < 10 && distance >3) {
    //Serial.println(distance);
    left();
    delay(480);
    stop();
    delay(800);
    left();
    delay(480);
    distance = getDistance();
    }
    else if (distance < 3) {
      right();
      delay(700);
    }
      
}
 else {
  forward();
}
}

float getDistance() {
digitalWrite(trig, HIGH);
delayMicroseconds(10);
digitalWrite(trig, LOW);
float echoTime = pulseIn(echo, HIGH);
float calculateDistance = echoTime/148.0;
return calculateDistance;
} 

 
