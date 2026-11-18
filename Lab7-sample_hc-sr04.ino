#include "src/HeptaSat.h"

HeptaCdh cdh;
HeptaEps eps;
HeptaHcSr04 ultrasonic;

void setup() {
  cdh.begin();
  eps.init();
  // HC-SR04 2020: VCC = 3.3 V payload rail (module rated 3–5.5 V).
  eps.switch_3V3_on();

  if (!ultrasonic.begin(USER_IO_1, USER_IO_2)) {
    cdh.println("HC-SR04 init failed");
    while (true) {
      delay(1000);
    }
  }

  cdh.println("HC-SR04 2020 ready");
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
