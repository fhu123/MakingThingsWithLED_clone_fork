#ifndef FIREBARBIEPINK_H
#define FIREBARBIEPINK_H

#include <FastLED.h>
#include "Config.h"

#define COOLING  55
#define SPARKING 120

void FireBarbiePink(CRGB* leds, int numLeds) {
  static byte heat[NUM_LEDS];

  for (int i = 0; i < numLeds; i++) {
    heat[i] = qsub8(heat[i], random8(0, ((COOLING * 10) / numLeds) + 2));
  }
  
  for (int k = numLeds - 1; k >= 2; k--) {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2]) / 3;
  }

  if (random8() < SPARKING) {
    int y = random8(7);
    heat[y] = qadd8(heat[y], random8(160, 255));
  }

  for (int j = 0; j < numLeds; j++) {
    CRGB color = CHSV(255, 192, heat[j]);
    leds[j] = color;
  }
}

#endif
