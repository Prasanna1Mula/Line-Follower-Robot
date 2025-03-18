#include <dummy.h>

#include <dummy.h>

// Define motor pins
#define IN1 15
#define IN2 13
#define IN3 18
#define IN4 19
#define ENA 22
#define ENB 23

// Define IR sensor pins
#define IR_LEFT 34
#define IR_RIGHT 35

// PID constants
float Kp = 10.0;  // Proportional gain (adjust as needed)
float Ki = 0.0;   // Integral gain (start with 0)
float Kd = 5.0;   // Derivative gain (adjust as needed)

// PID variables
int error = 0, lastError = 0;
float P = 0, I = 0, D = 0;
float PID_value = 0;

// Motor speeds
int baseSpeed = 200;  // Base speed for motors (adjust as needed)
int leftMotorSpeed = 0, rightMotorSpeed = 0;

void setup() {
  // Set motor pins as output
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Set IR sensor pins as input
  pinMode(IR_LEFT, INPUT);
  pinMode(IR_RIGHT, INPUT);

  // Initialize motors to stop
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);

  Serial.begin(115200);
}

void loop() {
  // Read IR sensor values (0 = black line, 1 = white surface)
  int left = digitalRead(IR_LEFT);
  int right = digitalRead(IR_RIGHT);

  // Calculate error
  error = left - right;  // Left sensor on line: error = -1, Right sensor on line: error = 1

  // Calculate PID terms
  P = error;
  I += error;
  D = error - lastError;
  lastError = error;

  // Calculate PID value
  PID_value = (Kp * P) + (Ki * I) + (Kd * D);

  // Adjust motor speeds
  leftMotorSpeed = baseSpeed - PID_value;
  rightMotorSpeed = baseSpeed + PID_value;

  // Constrain motor speeds to valid PWM range (0-255)
  leftMotorSpeed = constrain(leftMotorSpeed, 0, 255);
  rightMotorSpeed = constrain(rightMotorSpeed, 0, 255);

  // Set motor speeds
  analogWrite(ENA, leftMotorSpeed);
  analogWrite(ENB, rightMotorSpeed);

  // Set motor directions (forward)
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);

  // Debugging output
  Serial.print("Left: ");
  Serial.print(left);
  Serial.print(" Right: ");
  Serial.print(right);
  Serial.print(" Error: ");
  Serial.print(error);
  Serial.print(" PID: ");
  Serial.print(PID_value);
  Serial.print(" Left Speed: ");
  Serial.print(leftMotorSpeed);
  Serial.print(" Right Speed: ");
  Serial.println(rightMotorSpeed);
}
