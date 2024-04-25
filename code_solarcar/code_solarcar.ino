// Assign integers to the H-bridge's motor pins
int motor1pin1 = 2;
int motor1pin2 = 3;
int motor2pin1 = 4;
int motor2pin2 = 5;

// Assign integers to the IR-sensors signal pins
int leftSensor = 6;
int rightSensor = 7;

void setup() {
  // Define the motor pins as outputs
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
}

void loop() {
  // Define values from the sensors by using digitalRead command
  int right_value = digitalRead(rightSensor);
  int left_value = digitalRead(leftSensor);

  // If right value is seeing tape, and left is not - Drive right
  if (right_value == 0 && left_value == 1) {
    delay(50);
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, HIGH);
    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, LOW);
    delay(50);
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, LOW);
    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, LOW);
  }
  // If left value is seeing tape, and right is not - Drive left
  else if (right_value == 1 && left_value == 0) {
    delay(50);
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, LOW);
    digitalWrite(motor2pin1, HIGH);
    digitalWrite(motor2pin2, LOW);
    delay(50);
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, LOW);
    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, LOW);
  }
  // If right sensor and left sensor are seeing the same (tape or no tape) - zig zag with a small delay in between
  else {
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, HIGH);
    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, LOW);
    delay(100);
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, LOW);
    digitalWrite(motor2pin1, HIGH);
    digitalWrite(motor2pin2, LOW);
    delay(100);
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, LOW);
    digitalWrite(motor2pin1, LOW);
    digitalWrite(motor2pin2, LOW);
    delay(100);
  }
}

// Code to calibrate the sensors
// Read the digital pins that the sensors are connected to
int right_sensor = digitalRead(6);
int left_sensor = digitalRead(7);

void setup() {
  // Start the serial monitor
  Serial.begin(9600);
}

void loop() {
  // Prints out the current values of the sensors with a delay
  Serial.println("Left");
  Serial.println(left_sensor);
  delay(3000);
  Serial.println("Right");
  Serial.println(right_sensor);
  delay(3000);
}

