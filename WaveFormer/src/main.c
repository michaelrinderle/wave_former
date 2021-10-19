#include <Arduino.h>
#include "generator.c"

void setup() {
  generator_init();
}

void loop() {
  generator_wave_loop();
}