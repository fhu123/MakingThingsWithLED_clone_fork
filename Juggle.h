#ifndef JUGGLE_H
#define JUGGLE_H

#include <FastLED.h>

void juggle(CRGB* leds, int numLeds, uint8_t hue) {
  fadeToBlackBy(leds, numLeds, 20);
  byte dothue = 0;
  for (int i = 0; i < 8; i++) {
    leds[beatsin16(i + 7, 0, numLeds - 1)] |= CHSV(dothue, 200, 255);
    dothue += 32;
  }
}

#endif
