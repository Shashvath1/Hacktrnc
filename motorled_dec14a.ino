#include <WiFi.h>
#include <HTTPClient.h>

// Wi-Fi credentials
const char* ssid = "Redmi Note 9 Pro Max";
const char* password = "17052004";

// Make Webhook URL
const char* make_webhook_url = "https://hook.eu2.make.com/kb765p3ti6mccgrv863stoo4jxt6lbr8";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  // Connect to Wi-Fi
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to Wi-Fi...");
  }
  Serial.println("Connected to Wi-Fi");
}

void loop() {
  // Simulated power consumption data
  float power = 120.5;  // Replace with actual sensor data
  String timestamp = String(millis() / 1000);  // Simulated timestamp

  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(make_webhook_url);

    // Create JSON payload
    String payload = String("{\"power\":") + power + ",\"timestamp\":\"" + timestamp + "\"}";
    http.addHeader("Content-Type", "application/json");

    // Send POST request
    int httpResponseCode = http.POST(payload);

    if (httpResponseCode > 0) {
      Serial.println("Data sent successfully!");
    } else {
      Serial.println("Error in sending data.");
    }

    http.end();
  }

  delay(60000);  // Send data every 60 seconds
}