int LEDpin = 9;
int obstaclePin = 10;
int hasObstacle = LOW; // LOW MEANS NO OBSTACLE

void setup() {
pinMode(LEDpin, OUTPUT);
pinMode(obstaclePin, INPUT);
Serial.begin(9600);
}

void loop() {
hasObstacle = digitalRead(obstaclePin);

if (hasObstacle == HIGH) {
Serial.println("No Motion");

digitalWrite(LEDpin, LOW);
}
else {
Serial.println("Motion Detected");
digitalWrite(LEDpin, HIGH);
analogWrite(LEDpin, 255);
delay(2000);
analogWrite(LEDpin, 127);
delay(2000);
analogWrite(LEDpin, 64);
delay(1000);
}
delay(500);
}
