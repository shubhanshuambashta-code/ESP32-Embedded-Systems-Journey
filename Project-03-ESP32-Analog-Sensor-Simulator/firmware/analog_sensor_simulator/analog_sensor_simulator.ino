// Project 03 — classic ESP32 analog simulator
// GPIO4 = D4 (ADC2); GPIO23 = D23 (LED).
const int sensorPin = 4;
const int ledPin = 23;
const float limit = 1.5;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  analogReadResolution(12);
  analogSetPinAttenuation(sensorPin, ADC_11db);
}

void loop() {
  int raw = analogRead(sensorPin);
  int millivolts = analogReadMilliVolts(sensorPin);
  float voltage = millivolts / 1000.0;

  Serial.print("NODE1,");
  Serial.print(raw);
  Serial.print(",");
  Serial.print(millivolts);
  Serial.print(",");

  if (voltage > limit) {
    digitalWrite(ledPin, HIGH);
    Serial.println("ALERT");
  } else {
    digitalWrite(ledPin, LOW);
    Serial.println("NORMAL");
  }
  delay(1000);
}
