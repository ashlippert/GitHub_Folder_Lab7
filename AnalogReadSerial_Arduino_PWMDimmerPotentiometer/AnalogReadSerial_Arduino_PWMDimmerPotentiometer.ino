/*
  AnalogReadSerial with PWM LED Control

  Reads an analog input from a potentiometer, maps the value (0-1023) to a PWM range (0-255),
  and adjusts the brightness of an LED on a PWM-capable pin.

  Connect:
  - The center pin of a potentiometer to A0.
  - One outer pin to +5V.
  - The other outer pin to GND.
  - An LED to a PWM-capable pin with a resistor in series.

  This example code is in the public domain.
*/

// Define the pins
const int potPin = A0;    // Potentiometer connected to A0
const int ledPin = 10;     // LED connected to PWM pin 9 (PWM capable)

// Setup function runs once when the Arduino is powered on or reset
void setup() {
  Serial.begin(9600);     // Initialize serial communication at 9600 baud
  pinMode(ledPin, OUTPUT); // Set LED pin as an output
}

// Loop function runs repeatedly
void loop() {
  // Read the analog value from the potentiometer (0 - 1023)
  int sensorValue = analogRead(potPin);

  // Map the sensor value to a PWM range (0 - 255)
  int pwmValue = map(sensorValue, 0, 1023, 0, 255);

  // Print values to Serial Monitor for debugging
  Serial.print("Potentiometer Value: ");
  Serial.print(sensorValue);
  Serial.print(" -> PWM Value: ");
  Serial.println(pwmValue);

  // Adjust the LED brightness using PWM
  analogWrite(ledPin, pwmValue);

  delay(10); // Small delay for stability
}