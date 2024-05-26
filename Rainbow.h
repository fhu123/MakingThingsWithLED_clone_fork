#ifndef RAINBOW_H
#define RAINBOW_H

#include <FastLED.h>

void rainbow(CRGB* leds, int numLeds, uint8_t hue) {
  fill_rainbow(leds, numLeds, hue);
}

#endif
