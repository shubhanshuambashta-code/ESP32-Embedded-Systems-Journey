# Testing and evidence

## Supplied physical evidence

Date: 13 November 2026, based on the original attachment filenames.

- `media/IMG20261113192129.jpg`: ESP32 board on a breadboard with a USB cable connected and an onboard indicator illuminated. No external sensor circuit is shown.
- `media/Screenshot 2026-11-13 192115.png`: Arduino IDE code and Serial Monitor. The selected target is ESP32 Dev Module, port COM5, at 115200 baud. Visible records are `NODE1,1,-52`, `NODE1,2,-53`, and `NODE1,3,-47`.

Both original image files are preserved byte for byte. The screenshot supports that three serial RSSI records were produced on the user's setup. It does not show timestamps, network identities, the board-package version, or a full compile/upload log.

## Source review

The sketch is the code supplied by the user, without functional edits. The positive scan-count path selects the maximum RSSI and prints it. A zero or negative count prints `NA`. Each iteration frees the scan results and delays for 2000 ms after the blocking scan. No runtime measurement has been newly performed on connected hardware as part of preparing this repository update.

## Build verification

The unchanged supplied sketch compiled successfully on 13 November 2026 with Arduino CLI, Espressif Arduino-ESP32 **3.3.12**, and target **esp32:esp32:esp32** (ESP32 Dev Module).

```sh
arduino-cli compile --fqbn esp32:esp32:esp32 firmware/esp32_wifi_rssi_scanner
```

Compiler summary: **876872 bytes (66%)** of program storage, **45696 bytes (13%)** of global-variable RAM, and **281984 bytes** remaining for local variables. The installed board package and an explicit local build directory were used. This is a compile check; no firmware was uploaded and no new hardware test was performed during repository preparation.

## Reproduce on hardware

1. Compile and upload for the actual board, then open Serial Monitor at 115200 baud.
2. Confirm records have three comma-separated fields and the counter increases by one.
3. With at least one detectable supported Wi-Fi access point, confirm the third field contains an RSSI value.
4. Reset the board and confirm the counter restarts at 1.
5. For an empty-scan test, use a controlled environment with no detectable supported access points. Expect `NA`; this case has not been demonstrated in the supplied screenshot.
6. If character output is unreadable, check baud rate. If upload fails, check the data cable, selected board/port and the board's BOOT procedure.

RSSI may vary between samples, and the strongest result may come from a different access point. Do not interpret these three records as a controlled distance, coverage, or reliability test.
