const int trig = 11;
const int echo = 12;
float distance = 0;
const int AIN1 = 7;
const int AIN2 = 4;
const int BIN1 = 2;
const int BIN2 = 3;
const int PWMA = 6;
const int PWMB = 5;
int switchPin = 8;
int motorSpeed = 0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(echo, INPUT);
pinMode(trig, OUTPUT);
pinMode(switchPin, INPUT_PULLUP);
pinMode(AIN1, OUTPUT);
pinMode(AIN2, OUTPUT);
pinMode(PWMA, OUTPUT);
pinMode(BIN2, OUTPUT);
pinMode(BIN1, OUTPUT);
pinMode(PWMB, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int switchOn = digitalRead(switchPin);
distance = getDistance();
if (switchOn == LOW) {
  if (distance < 10) {
    rightMotor(0); //stop
    leftMotor(0);
    delay(500);
    rightMotor(-150);  //back up
    leftMotor(-150);
    delay(300);
    rightMotor(-150); //turn right
    leftMotor(150);
    delay(500);
    
  }
  else {
    rightMotor(150);
    leftMotor(150);
  }
}
else {
  rightMotor(0);
  leftMotor(0);
}
delay(50);
//Serial.println(String(distance) + "in");
//delay(100);

}
float getDistance(){
digitalWrite(trig, HIGH);
delayMicroseconds(10);
digitalWrite(trig,LOW);
float echoTime = pulseIn(echo, HIGH);
float calculateDistance = echoTime/148.0;
return calculateDistance;
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
void leftMotor(int motorSpeed) { // this drives the motor
  if (motorSpeed > 0) {           // if the motor is given a positive speed
    digitalWrite(BIN1, HIGH);     //pin 1 is high
    digitalWrite(BIN2, LOW);      // pin 2 is low
  }
  else if (motorSpeed < 0) {      //if the motor should drive backwards (negative speed)
    digitalWrite(BIN1, LOW);      //set pin 1 to low
    digitalWrite(BIN2, HIGH);     //set pin 2 to high
  }
  else {                          //if the motor should stop
    digitalWrite(BIN1, LOW);      //set pin 1 to low
    digitalWrite(BIN2, LOW);      //set pin 2 to low
  }
  analogWrite(PWMB, abs(motorSpeed)); //now that the motor direction is set, drive it at the entered speed
}
