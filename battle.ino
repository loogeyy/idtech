const int forwardBtn= 0;
const int leftBtn = 10;
const int rightBtn = 1;
const int backBtn = 8; 

const int AIN1 = 7;
const int AIN2 = 4;
const int BIN1 = 2;
const int BIN2 = 3;
const int PWMA = 6;
const int PWMB = 5;
int motorSpeed = 0;
void setup() {
  // put your setup code here, to run once:
pinMode(forwardBtn, INPUT_PULLUP);
pinMode(leftBtn, INPUT_PULLUP);
pinMode(rightBtn, INPUT_PULLUP);
pinMode(backBtn, INPUT_PULLUP);
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
  rightMotor(255);
  leftMotor(255);
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

  rightMotor(-150);
  leftMotor(150);

}

void stop() {
 rightMotor(0);
 leftMotor(0);  
}
 
  
void loop() {
  // put your main code here, to run repeatedly:
int red = digitalRead(forwardBtn);
int yellow = digitalRead(rightBtn);
int green = digitalRead(backBtn);
int blue = digitalRead(leftBtn);
 
 if (red == LOW){
    forward();
    
  }
 else if (yellow == LOW) {
     right();
 }

 else if (green == LOW) {
     backward();
 }

 else if (blue == LOW) {
     left();
 }
 
  else {
    stop();
  }

}
