# Wiring and hardware notes

Connect the computer to the ESP32 development board's USB connector with a compatible USB data cable. The board's onboard USB interface carries programming and serial communication; USB also powers the board.

The sketch uses only the onboard Wi-Fi radio and serial interface. No jumper wires, external LEDs, resistors, sensors, or GPIO connections are needed. The breadboard in the photograph supports the board but adds no external circuit for this project.

Nearby Wi-Fi access points are radio signal sources. There is no wired connection to them, and the sketch does not join them.

[block-diagram.svg](block-diagram.svg) is a functional diagram, not a pin-level schematic or an assertion about the exact board revision's internal wiring.
