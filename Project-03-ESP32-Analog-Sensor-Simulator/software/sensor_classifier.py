"""Classify example voltages without needing a connected ESP32."""

readings_mv = [1050, 1080, 2230, 1100, 2180]


def to_volts(millivolts):
    return millivolts / 1000


def classify(voltage, limit):
    if voltage > limit:
        return "ALERT"
    else:
        return "NORMAL"


alert_count = 0

for reading in readings_mv:
    voltage = to_volts(reading)
    status = classify(voltage, 1.5)

    print(f"{voltage:.2f} V - {status}")

    if status == "ALERT":
        alert_count += 1

print("Total alerts:", alert_count)
