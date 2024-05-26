#ifndef CONFETTI_H
#define CONFETTI_H

#include <FastLED.h>

void confetti(CRGB* leds, int numLeds, uint8_t hue) {
  fadeToBlackBy(leds, numLeds, 10);
  int pos = random16(numLeds);
  leds[pos] += CHSV(hue + random8(64), 200, 255);
}

#endif
