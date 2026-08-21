#include "src/HeptaSat.h"
#include "hc_sr04.h"

HeptaCdh cdh;
HeptaEps eps;
HcSr04 ultrasonic;

// V4.1.1 digital USER_IO: USER_IO_1 = GP21, USER_IO_2 = GP22
constexpr uint8_t kTrigPin = 21;  // USER_IO_1 -> TRIG
constexpr uint8_t kEchoPin = 22;  // USER_IO_2 -> ECHO

void setup() {
  cdh.begin();
  eps.init();
  // HC-SR04 2020: VCC = 3.3 V payload rail (module rated 3–5.5 V).
  eps.switch_3V3_on();

  if (!ultrasonic.begin(kTrigPin, kEchoPin)) {
    cdh.println("HC-SR04 init failed");
    while (true) {
      delay(1000);
    }
  }

  cdh.printf("HC-SR04 2020 ready (TRIG=GP%u / ECHO=GP%u, VCC=3.3V)\r\n",
             kTrigPin, kEchoPin);
}

void loop() {
  float distance_cm = 0.0f;

  if (ultrasonic.get_distance_cm(&distance_cm)) {
    cdh.printf("Distance: %.1f [cm]\r\n", distance_cm);
  } else {
    cdh.println("Distance: timeout / out of range");
  }

  delay(1000);
}
