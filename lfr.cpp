#define leftMotor1 4
#define leftMotor2 5
#define rightMotor1 6
#define rightMotor2 7

#define leftSensor 2
#define rightSensor 3

void setup() {
  
  pinMode(leftMotor1, OUTPUT);
  pinMode(leftMotor2, OUTPUT);
  pinMode(rightMotor1, OUTPUT);
  pinMode(rightMotor2, OUTPUT);
  
  pinMode(leftSensor, OUTPUT);
  pinMode(rightSensor, OUTPUT);
  
}

void loop() {
  int leftStatus = digitalRead(leftSensor);
  int rightStatus = digitalRead(rightSensor);
  
  if (leftStatus == LOW && rightStatus == LOW ){
    moveForward();
  }
  
  if (leftStatus == LOW && rightStatus == HIGH) {
    turnLeft();
  }
  
  if (leftStatus == HIGH && rightStatus == LOW) {
    turnRight();
  }
  
  
  else {
    stopMotors();
  }
}

void moveForward() {
  digitalWrite(leftMotor1, HIGH);  
  digitalWrite(leftMotor2, LOW);   
  digitalWrite(rightMotor1, HIGH); 
  digitalWrite(rightMotor2, LOW);  
}

void turnRight() {
  digitalWrite(leftMotor1, LOW);  
  digitalWrite(leftMotor2, LOW);   
  digitalWrite(rightMotor1, HIGH); 
  digitalWrite(rightMotor2, LOW);  
}

void turnLeft() {
  digitalWrite(leftMotor1, HIGH);  
  digitalWrite(leftMotor2, LOW);   
  digitalWrite(rightMotor1, LOW);  
  digitalWrite(rightMotor2, LOW);  
}

void stopMotors() {
  digitalWrite(leftMotor1, LOW);  
  digitalWrite(leftMotor2, LOW);  
  digitalWrite(rightMotor1, LOW); 
  digitalWrite(rightMotor2, LOW); 
}
  
