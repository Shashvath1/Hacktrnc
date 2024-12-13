
const int pwmPin = 9;  // PWM output pin (Pin 9 on Arduino Uno)
const int pwmPin1 = 10; // PWM output pin (Pin 10 on Arduino Uno)
const int pwmPin2 = 11; // PWM output pin (Pin 11 on Arduino Uno)

void setup() {
  pinMode(pwmPin, OUTPUT);   // Set pin 9 as output
  pinMode(pwmPin1, OUTPUT);  // Set pin 10 as output
  pinMode(pwmPin2, OUTPUT);  // Set pin 11 as output
  Serial.begin(9600);
  Serial.println("Simulating AC signal at 50 Hz...");
}

void loop() {
  // Generate a 50 Hz square wave (each half cycle is 10ms)
  digitalWrite(pwmPin, HIGH);  // Set pin high
  digitalWrite(pwmPin1, HIGH); // Set pin high
  digitalWrite(pwmPin2, HIGH); // Set pin high
  delay(10);                   // Wait for 10 ms (1/2 of 50 Hz period)

  digitalWrite(pwmPin, LOW);   // Set pin low
  digitalWrite(pwmPin1, LOW);  // Set pin low
  digitalWrite(pwmPin2, LOW);  // Set pin low
  delay(10);                   // Wait for 10 ms (1/2 of 50 Hz period)
}
