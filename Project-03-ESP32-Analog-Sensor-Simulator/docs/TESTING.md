# Testing record — 18 November 2026

These are **observations from user-supplied photos/screenshots**, not independently rerun experiments.

## Python VS Code screenshot
The terminal visibly prints:

```text
1.05 V - NORMAL
1.08 V - NORMAL
2.23 V - ALERT
1.10 V - NORMAL
2.18 V - ALERT
Total alerts: 2
```

This supports successful classification of five fixed sample readings; no serial ESP32-to-Python integration is claimed.

## ESP32 Serial Monitor photograph
Repeated records visible in the user's photograph are:

```text
NODE1,4095,3130,ALERT
```

The 12-bit raw value **4095 is saturated**. With 467 Ω above and 980 Ω below, nominal divider voltage is **3.3×980/1447 ≈ 2.23 V**, but the ADC reports **3130 mV**. This disagreement requires investigation; it does not prove accurate analog sensing.

## Physical prototype photograph
The breadboarded ESP32 is powered via USB. An external blue LED is illuminated. The photo supports LED operation but not independent verification of each wire endpoint or threshold response.

## Status table

| Capability | Evidence |
| --- | --- |
| Fixed-list Python sample classifier | Output observed |
| Serial output from ESP32 | Records observed |
| External LED lights | Photograph observed |
| Voltage divider correctly measured | **Not established** (ADC saturated) |
| LED turns off when voltage drops | Not shown |
| Live ESP32-to-Python serial logging | Not implemented |

**Next validation:** power off before moving wires. Measure row B6/A6 versus ESP32 GND with multimeter (expect about 2.23 V), then reverse divider resistors and measure again (expect about 1.06 V). Compare with analog serial reading and LED state.
