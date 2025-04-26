// Dual IR Sensor Person Detection with LED Control

// Define the IR sensor pins
const int irSensor1Pin = 7; // First IR sensor connected to digital pin 7
const int irSensor2Pin = 8; // Second IR sensor connected to digital pin 8
const int ledPin = 9;       // LED connected to digital pin 9

void setup() {
  // Initialize the serial monitor
  Serial.begin(9600);

  // Set the IR sensor pins as input
  pinMode(irSensor1Pin, INPUT);
  pinMode(irSensor2Pin, INPUT);

  // Set the LED pin as output
  pinMode(ledPin, OUTPUT);

  Serial.println("Dual IR Sensor Person Detection Initialized");
}

void loop() {
  // Read the sensor values
  int sensor1Value = digitalRead(irSensor1Pin);
  int sensor2Value = digitalRead(irSensor2Pin);

  // Check if the first sensor detects a person before the second
  if (sensor1Value == LOW && sensor2Value == HIGH) {
    // Turn on the LED
    digitalWrite(ledPin, HIGH);
    Serial.println("LED ON: First sensor detected first");
  }

  // Check if the second sensor detects a person before the first
  else if (sensor2Value == LOW) {
    // Turn off the LED
    digitalWrite(ledPin, LOW);
    Serial.println("LED OFF: Second sensor detected first");
  }

  delay(100); // Small delay to avoid rapid toggling
}
