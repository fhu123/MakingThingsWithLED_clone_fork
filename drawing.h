#ifndef DRAWING_H
#define DRAWING_H

#include <FastLED.h>
#include "Config.h"

void setPixel(CRGB* leds, int numLeds, int pos, CRGB color) {
  if (pos >= 0 && pos < numLeds) {
    leds[pos] = color;
  }
}

void fadeAll(CRGB* leds, int numLeds, uint8_t fadeValue) {
  for (int i = 0; i < numLeds; i++) {
    leds[i].nscale8(fadeValue);
  }
}

#endif
