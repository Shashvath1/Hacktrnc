// Pin assignments
const int currentPin1 = 34;    // Current Sensor 1
const int currentPin2 = 35;    // Current Sensor 2
const int currentPin3 = 32;    // Current Sensor 3
const int voltagePin = 36;     // Voltage Sensor

const int relayPin1 = 12;      // Relay 1 (for load control)
const int relayPin2 = 13;      // Relay 2 (for load control)
const int relayPin3 = 14;      // Relay 3 (for load control)
const int relayPin4 = 27;      // Relay 4 (for trip control)

// Constants for ADC to voltage conversion
const float vRef = 3.3;        // Reference voltage for ESP32 ADC
const int adcResolution = 4096; // 12-bit resolution

// Thresholds for trip
const float overcurrentThreshold = 5.0; // 5 Amperes
const float overvoltageThreshold = 240.0; // 240 Volts

// Sensitivity for current sensors (example for ACS712-5A)
const float sensitivity = 0.185; // 185 mV per Amp (ACS712-5A)

void setup() {
  Serial.begin(115200);

  // Setup relay pins as outputs
  pinMode(relayPin1, OUTPUT);
  pinMode(relayPin2, OUTPUT);
  pinMode(relayPin3, OUTPUT);
  pinMode(relayPin4, OUTPUT);

  // Ensure relays are off at startup
  digitalWrite(relayPin1, LOW);
  digitalWrite(relayPin2, LOW);
  digitalWrite(relayPin3, LOW);
  digitalWrite(relayPin4, LOW);
}

void loop() {
  // Read current and voltage from sensors
  float current1 = readCurrentSensor(currentPin1);
  float current2 = readCurrentSensor(currentPin2);
  float current3 = readCurrentSensor(currentPin3);
  float voltage = readVoltageSensor(voltagePin);

  // Print sensor values for debugging
  Serial.print("Current 1: ");
  Serial.print(current1);
  Serial.print(" A\tCurrent 2: ");
  Serial.print(current2);
  Serial.print(" A\tCurrent 3: ");
  Serial.print(current3);
  Serial.print(" A\tVoltage: ");
  Serial.print(voltage);
  Serial.println(" V");

  // Check for overcurrent or overvoltage conditions
  if (current1 > overcurrentThreshold || current2 > overcurrentThreshold || current3 > overcurrentThreshold) {
    // Trigger relay to cut off the power (trip system)
    digitalWrite(relayPin4, HIGH); // Trip relay 4
    delay(2000); // Trip relay for 2 seconds, then reset
    digitalWrite(relayPin4, LOW);
  }

  if (voltage > overvoltageThreshold) {
    // Trigger relay to cut off the power (trip system)
    digitalWrite(relayPin4, HIGH); // Trip relay 4
    delay(2000); // Trip relay for 2 seconds, then reset
    digitalWrite(relayPin4, LOW);
  }

  // Control relays based on current/voltage conditions (e.g., turn on/off power)
  if (current1 < overcurrentThreshold && voltage < overvoltageThreshold) {
    digitalWrite(relayPin1, HIGH); // Turn on relay 1 for load 1
  } else {
    digitalWrite(relayPin1, LOW);  // Turn off relay 1
  }

  if (current2 < overcurrentThreshold && voltage < overvoltageThreshold) {
    digitalWrite(relayPin2, HIGH); // Turn on relay 2 for load 2
  } else {
    digitalWrite(relayPin2, LOW);  // Turn off relay 2
  }

  if (current3 < overcurrentThreshold && voltage < overvoltageThreshold) {
    digitalWrite(relayPin3, HIGH); // Turn on relay 3 for load 3
  } else {
    digitalWrite(relayPin3, LOW);  // Turn off relay 3
  }

  delay(1000);  // Delay before the next loop iteration
}

// Function to read current from the sensor
float readCurrentSensor(int pin) {
  int adcValue = analogRead(pin);
  float sensorVoltage = adcValue * (vRef / adcResolution);
  float current = (sensorVoltage - 2.5) / sensitivity; // Assuming 2.5V offset for ACS712
  return current;
}

// Function to read voltage from the sensor
float readVoltageSensor(int pin) {
  int adcValue = analogRead(pin);
  float sensorVoltage = adcValue * (vRef / adcResolution);
  return sensorVoltage * (5.0 / 3.3); // Assuming voltage divider if needed for scaling
}
