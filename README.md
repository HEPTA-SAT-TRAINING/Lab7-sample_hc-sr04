# Lab7-sample_hc-sr04

HEPTA-SAT training sample: **HC-SR04 (2020)** ultrasonic distance sensor (no third-party library).

## Sensor Specifications

| Item | Value |
|------|-------|
| Module | **HC-SR04 2020** (RCWL-9206; board marking “2020”) |
| Interface | Digital TRIG / ECHO → **USER_IO_1 / USER_IO_2** (V4.1.1) |
| Supply | **3.3 V** (module VCC; rated 3–5.5 V) |
| Range (typical) | approx. 2 cm to 450 cm |
| Conversion | `distance [cm] = pulse_us × 0.0343 / 2` (speed of sound ≈ 343 m/s) |
| Min. interval | ≥ 200 ms between measurements |

## Wiring (HEPTA-SAT V4.1.1)

| Sensor | HEPTA-SAT |
|--------|-----------|
| TRIG | `USER_IO_1` |
| ECHO | `USER_IO_2` |
| VCC | **3.3 V** payload (`eps.switch_3V3_on()`) |
| GND | GND |

Pass the TRIG terminal first and the ECHO terminal second: `ultrasonic.begin(USER_IO_1, USER_IO_2)`.

> **2020 module:** With VCC = 3.3 V, Echo is also 3.3 V logic, so USER_IO_2 can be wired
> directly (no level shifter). Older 5 V-only HC-SR04 modules are out of scope for this sample.

## Build and Upload

1. Open `Lab7-sample_hc-sr04.ino` in the Arduino IDE
2. Board: **Generic RP2350**
3. Check out the `src/` submodule (`git submodule update --init`)
4. Compile and upload
5. Serial monitor at **9600 baud**

## Example Serial Output

```
HC-SR04 2020 ready
Distance: 42.3 [cm]
Distance: 41.8 [cm]
Distance: timeout / out of range
```

## Driver

- Board interface: `HeptaHcSr04` from `src/HeptaSat.h`
- `src/drv/hc_sr04.h` / `.cpp` (HEPTA-SAT Library)
- Details: `src/docs/drivers/hc-sr04.md`
