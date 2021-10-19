#ifndef _CONSTANTS_h
#define _CONSTANTS_h

#define TRUE 0
#define FALSE 1

// BUTTON
const byte BUTTON_0 = 2;

// WAVES
volatile byte WAVE_0 = 0;

// NOTIFICATION LED
const byte PIN_LED_1 = 13;

enum relay_setting {
  ACTIVATED = 0,  // LOW
  DEACTIVATED =1  // HIGH
};

#endif