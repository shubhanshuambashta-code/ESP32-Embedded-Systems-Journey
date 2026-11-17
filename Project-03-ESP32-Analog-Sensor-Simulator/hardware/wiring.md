# Wiring and breadboard map

**Disconnect ESP32 USB power before rewiring. Never connect a 9 V battery to ESP32 3V3 or a GPIO pin.**

Standard breadboards connect same-number holes **A–E**, and separately **F–J**, across each row. The center gap isolates the two halves.

| Component or ESP32 pin | Breadboard hole(s) |
| --- | --- |
| 467 Ω resistor | B2–B6 |
| 980 Ω resistor | B6–B9 |
| ESP32 3V3 | A2 |
| ESP32 GPIO4 (D4) | A6 |
| ESP32 GND | A9 |
| 260 Ω resistor | H3–H7 |
| LED anode (+) | H7 |
| LED cathode (-) | H9 |
| ESP32 GPIO23 (D23) | J3 |
| ESP32 GND | J9 |

**Two independent circuits share a GND:**

- Divider: `3V3 → 467 Ω → row 6 / D4 → 980 Ω → GND`.
- LED: `GPIO23 → 260 Ω → LED anode → LED cathode → GND`.

Do **not** connect the lower 980 Ω divider resistor to the 260 Ω LED resistor. Check the LED cathode really goes to GND, not D23.

Expected divider voltage at row 6: **~2.23 V** with 3.3 V supply; with resistors reversed: **~1.06 V**. If raw ADC reads **4095** continuously, verify D4 pin selection, check for shorts/incorrect rails and measure node voltage with a multimeter before interpreting results.

GPIO4 is an **ADC2** pin on classic ESP32, which can conflict with Wi-Fi. For later wireless monitoring, use an **ADC1** pin (GPIO32 or GPIO33, for example).
