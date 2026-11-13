#include <WiFi.h>

int packetNumber = 1;

void setup() {
  Serial.begin(115200);

  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(1000);
}

void loop() {
  int networks = WiFi.scanNetworks();
  int strongest = -1000;

  for (int i = 0; i < networks; i++) {
    int signal = WiFi.RSSI(i);

    if (signal > strongest) {
      strongest = signal;
    }
  }

  Serial.print("NODE1,");
  Serial.print(packetNumber);
  Serial.print(",");

  if (networks > 0) {
    Serial.println(strongest);
  } else {
    Serial.println("NA");
  }

  packetNumber++;

  WiFi.scanDelete();
  delay(2000);
}
