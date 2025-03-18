#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11
#define EN1 5
#define EN2 6
#define IR_LEFT 3
#define IR_RIGHT 2

float Kp = 10.0;
float Ki = 0.0;
float Kd = 5.0;

int error = 0, lastError = 0;
float P = 0, I = 0, D = 0;
float PID_value = 0;

int baseSpeed = 100;
int leftMotorSpeed = 0, rightMotorSpeed = 0;

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(EN1, OUTPUT);
  pinMode(EN2, OUTPUT);
  pinMode(IR_LEFT, INPUT);
  pinMode(IR_RIGHT, INPUT);

  Serial.begin(9600);
}

void loop() {
  int left = digitalRead(IR_LEFT);
  int right = digitalRead(IR_RIGHT);

  // If sensors are reversed, swap error calculation
  error = left - right;

  P = error;
  I += error;
  I = constrain(I, -50, 50); // Prevent integral windup
  D = error - lastError;
  lastError = error;

  PID_value = (Kp * P) + (Ki * I) + (Kd * D);

  leftMotorSpeed = constrain(baseSpeed - PID_value, 0, 255);
  rightMotorSpeed = constrain(baseSpeed + PID_value, 0, 255);

  if (left == 1 && right == 1) {
    stopMotors();
  } else {
    moveMotors(leftMotorSpeed, rightMotorSpeed);
  }

  Serial.print("L:");
  Serial.print(left);
  Serial.print(" R:");
  Serial.print(right);
  Serial.print(" E:");
  Serial.print(error);
  Serial.print(" P:");
  Serial.print(PID_value);
  Serial.print(" LSpeed:");
  Serial.print(leftMotorSpeed);
  Serial.print(" RSpeed:");
  Serial.println(rightMotorSpeed);

  delay(100);
}

void stopMotors() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(EN1, 0);
  analogWrite(EN2, 0);
}

void moveMotors(int leftSpeed, int rightSpeed) {
  analogWrite(EN1, leftSpeed);
  analogWrite(EN2, rightSpeed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}
