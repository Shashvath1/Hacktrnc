// Define pin for PIR sensor
#define PIR_PIN 13 // Connect OUT pin of PIR to GPIO 13

// Define pins for current and voltage sensors
#define CURRENT_SENSOR_PIN A0 // Analog pin for current sensor
#define VOLTAGE_SENSOR_PIN A1 // Analog pin for voltage sensor

void setup() {
    Serial.begin(9600);      // Start serial communication at 9600 baud rate
    pinMode(PIR_PIN, INPUT); // Set the PIR pin as input
    
    // No need for pinMode for analog pins as they are set automatically
}

void loop() {
    // PIR Sensor
    int motionDetected = digitalRead(PIR_PIN); // Read the state of the PIR sensor

    if (motionDetected == HIGH) {
        Serial.println("Motion detected!"); // Motion detected
        delay(1000); // Delay to avoid multiple prints for the same motion
    } else {
        Serial.println("No motion."); // No motion detected
    }

    // Read current sensor value
    int currentSensorValue = analogRead(CURRENT_SENSOR_PIN); // Raw analog value
    float current = (currentSensorValue / 1023.0) * 5.0;    // Example conversion to voltage (0-5V)
    Serial.print("Current Sensor Value: ");
    Serial.print(current);
    Serial.println(" V");

    // Read voltage sensor value
    int voltageSensorValue = analogRead(VOLTAGE_SENSOR_PIN); // Raw analog value
    float voltage = (voltageSensorValue / 1023.0) * 5.0 * 11; // Example conversion for voltage divider (scale factor 11)
    Serial.print("Voltage Sensor Value: ");
    Serial.print(voltage);
    Serial.println(" V");

    delay(500); // Delay to reduce the frequency of checks
}
