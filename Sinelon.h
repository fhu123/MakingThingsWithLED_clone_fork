#ifndef SINELON_H
#define SINELON_H

#include <FastLED.h>

void sinelon(CRGB* leds, int numLeds, uint8_t hue) {
  fadeToBlackBy(leds, numLeds, 20);
  int pos = beatsin16(13, 0, numLeds - 1);
  leds[pos] += CHSV(hue, 255, 192);
}

#endif
