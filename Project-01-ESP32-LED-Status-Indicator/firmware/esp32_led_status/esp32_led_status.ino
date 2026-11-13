// Project 01: ESP32 LED Status Indicator
// Board: ESP32 (e.g., ESP32 Dev Module)
// Circuit: GPIO23 -> current-limiting resistor (~260 ohm) -> LED anode
//          LED cathode -> ESP32 GND
// This is a timed demonstration: modes do not respond to a sensor yet.

const int ledPin = 23;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // Normal mode: Slow blinking
  Serial.println("NORMAL MODE");
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(1000);

  // Alert mode: Fast blinking
  Serial.println("ALERT MODE");
  for (int i = 0; i < 3; i++) {
    digitalWrite(ledPin, HIGH);
    delay(150);
    digitalWrite(ledPin, LOW);
    delay(150);
  }
  delay(2000);
}
