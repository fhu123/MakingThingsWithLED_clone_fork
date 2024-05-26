#ifndef BPM_H
#define BPM_H

#include <FastLED.h>

void bpm(CRGB* leds, int numLeds, uint8_t hue) {
  uint8_t BeatsPerMinute = 62;
  CRGBPalette16 palette = PartyColors_p;
  uint8_t beat = beatsin8(BeatsPerMinute, 64, 255);
  for (int i = 0; i < numLeds; i++) {
    leds[i] = ColorFromPalette(palette, hue + (i * 2), beat - hue + (i * 10));
  }
}

#endif
