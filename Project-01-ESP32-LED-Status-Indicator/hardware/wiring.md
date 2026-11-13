# Physical Wiring — Project 01

## Electrical connections

| From | To |
| --- | --- |
| ESP32 **GPIO23** (`D23` on some boards) | Series current-limiting resistor (~260 Ω) |
| Other end of resistor | **Anode (+)** of external blue LED (usually longer leg) |
| **Cathode (−)** of LED (usually shorter leg / flat side) | ESP32 **GND** |
| ESP32 USB port | Laptop USB data cable |

The resistor and LED are in **series**. Their order within the series chain can be interchanged, but LED polarity must be correct. Breadboard row numbers are only physical locations: any electrically equivalent rows work. Do **not** connect an external 9 V battery directly to ESP32 GPIO. The red light on the development board is a power indicator, not the external GPIO23 LED.

No button or sensor is part of Project 01; those belong to later experiments.
