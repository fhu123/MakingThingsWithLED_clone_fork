#ifndef FIRE2012_H
#define FIRE2012_H

#include <FastLED.h>
#include "Config.h"

#define COOLING  55
#define SPARKING 120

void Fire2012(CRGB* leds, int numLeds) {
  static byte heat[NUM_LEDS];

  // Step 1. Cool down every cell a little
  for (int i = 0; i < numLeds; i++) {
    heat[i] = qsub8(heat[i], random8(0, ((COOLING * 10) / numLeds) + 2));
  }
  
  // Step 2. Heat from each cell drifts 'up' and diffuses a little
  for (int k = numLeds - 1; k >= 2; k--) {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2]) / 3;
  }

  // Step 3. Randomly ignite new 'sparks' near the bottom
  if (random8() < SPARKING) {
    int y = random8(7);
    heat[y] = qadd8(heat[y], random8(160, 255));
  }

  // Step 4. Map from heat cells to LED colors
  for (int j = 0; j < numLeds; j++) {
    CRGB color = HeatColor(heat[j]);
    int pixelnumber = (gReverseDirection) ? (numLeds - 1 - j) : j;
    leds[pixelnumber] = color;
  }
}

#endif
