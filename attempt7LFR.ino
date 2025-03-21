// PID Line Follower Robot
#define LEFT_IR A0
#define RIGHT_IR A1

#define IN1 6
#define IN2 7
#define IN3 8
#define IN4 9
#define ENA 10
#define ENB 11

// PID Variables
float Kp = 40;   // Proportional constant
float Ki = 0.5;  // Integral constant
float Kd = 30;   // Derivative constant

int maxSpeed = 90;   // Max motor speed
int minSpeed = 0;      // Min motor speed

// PID error terms
int lastError = 0;
int integral = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(LEFT_IR, INPUT);
  pinMode(RIGHT_IR, INPUT);
  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
}

void loop() {
  int leftValue = digitalRead(LEFT_IR);   // Read Left IR sensor
  int rightValue = digitalRead(RIGHT_IR); // Read Right IR sensor

  // Calculate error
  int error = (leftValue ? 0 : 1) - (rightValue ? 0 : 1);

  // PID Calculations
  integral += error;
  int derivative = error - lastError;
  int output = (Kp * error) + (Ki * integral) + (Kd * derivative);
  lastError = error;

  // Speed calculation
  int leftSpeed = maxSpeed - output;
  int rightSpeed = maxSpeed + output;

  leftSpeed = constrain(leftSpeed, minSpeed, maxSpeed);
  rightSpeed = constrain(rightSpeed, minSpeed, maxSpeed);

  // Motor control logic
  if (leftValue == 0 && rightValue == 0) {
    moveForward(leftSpeed, rightSpeed);
  } 
  else if (leftValue == 1 && rightValue == 0) {
    turnRight();
  } 
  else if (leftValue == 0 && rightValue == 1) {
    turnLeft();
  } 
  else {
    stopMotors();
  }
}

void moveForward(int leftSpeed, int rightSpeed) {
  analogWrite(ENA, leftSpeed);
  analogWrite(ENB, rightSpeed);
  
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnLeft() {
  analogWrite(ENA, 100);
  analogWrite(ENB, 150);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void turnRight() {
  analogWrite(ENA, 150);
  analogWrite(ENB, 100);

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
