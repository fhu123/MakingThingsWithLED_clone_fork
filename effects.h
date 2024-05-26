#ifndef EFFECTS_H
#define EFFECTS_H

#include <FastLED.h>
#include "Config.h"

void fillSolid(CRGB* leds, int numLeds, CRGB color) {
  fill_solid(leds, numLeds, color);
}

void fadeToBlack(CRGB* leds, int numLeds, uint8_t fadeValue) {
  fadeAll(leds, numLeds, fadeValue);
}

#endif
