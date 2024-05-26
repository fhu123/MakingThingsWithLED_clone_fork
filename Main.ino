#include <FastLED.h>
#include <Espalexa.h>
#include <ESP8266WiFi.h>

// Include effect header files
#include "Config.h"
#include "Rainbow.h"
#include "Fire2012.h"
#include "Confetti.h"
#include "Sinelon.h"
#include "Juggle.h"
#include "BPM.h"
#include "FireBlue.h"
#include "FireChemical.h"
#include "FireAqua.h"
#include "FireBarbiePink.h"
#include "FireElectricBlue.h"
#include "FireGreen.h"
#include "FireOrange.h"
#include "FirePurple.h"
#include "FireWhite.h"
#include "FireYellow.h"
#include "drawing.h"
#include "effects.h"

#define LED_PIN 6
#define BRIGHTNESS  64
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB

char* ssid = "SSID";
char* password = "password";

CRGB leds[NUM_LEDS];
uint8_t gHue = 0; // Global hue value for color cycling
uint8_t currentEffect = 0;
bool gReverseDirection = false; // Define it here

// Espalexa instance
Espalexa espalexa;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");

  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);

  espalexa.addDevice("Rainbow", onRainbow);
  espalexa.addDevice("Fire", onFire);
  espalexa.addDevice("Confetti", onConfetti);
  espalexa.addDevice("Sinelon", onSinelon);
  espalexa.addDevice("Juggle", onJuggle);
  espalexa.addDevice("BPM", onBPM);
  espalexa.addDevice("FireBlue", onFireBlue);
  espalexa.addDevice("FireChemical", onFireChemical);
  espalexa.addDevice("Fire Aqua", onFireAqua);
  espalexa.addDevice("Fire Barbie Pink", onFireBarbiePink);
  espalexa.addDevice("Fire Electric Blue", onFireElectricBlue);
  espalexa.addDevice("Fire Green", onFireGreen);
  espalexa.addDevice("Fire Orange", onFireOrange);
  espalexa.addDevice("Fire Purple", onFirePurple);
  espalexa.addDevice("Fire White", onFireWhite);
  espalexa.addDevice("Fire Yellow", onFireYellow);

  espalexa.begin();
}

void loop() {
  espalexa.loop();
  switch(currentEffect) {
    case 0: rainbow(leds, NUM_LEDS, gHue); break;
    case 1: Fire2012(leds, NUM_LEDS); break;
    case 2: confetti(leds, NUM_LEDS, gHue); break;
    case 3: sinelon(leds, NUM_LEDS, gHue); break;
    case 4: juggle(leds, NUM_LEDS, gHue); break;
    case 5: bpm(leds, NUM_LEDS, gHue); break;
    case 6: FireBlue(leds, NUM_LEDS); break;
    case 7: FireChemical(leds, NUM_LEDS); break;
    case 8: FireAqua(leds, NUM_LEDS); break;
    case 9: FireBarbiePink(leds, NUM_LEDS); break;
    case 10: FireElectricBlue(leds, NUM_LEDS); break;
    case 11: FireGreen(leds, NUM_LEDS); break;
    case 12: FireOrange(leds, NUM_LEDS); break;
    case 13: FirePurple(leds, NUM_LEDS); break;
    case 14: FireWhite(leds, NUM_LEDS); break;
    case 15: FireYellow(leds, NUM_LEDS); break;
  }

  FastLED.show();
  FastLED.delay(30);
  gHue++; // Increment the global hue for color cycling effects
}

// Espalexa callback functions for each effect
void onRainbow(uint8_t brightness) {
  Serial.println("Effect: Rainbow");
  currentEffect = 0;
  FastLED.setBrightness(map(brightness, 0, 255, 0, 255));
}

void onFire(uint8_t brightness) {
  Serial.println("Effect: Fire");
  currentEffect = 1;
  FastLED.setBrightness(map(brightness, 0, 255, 0, 255));
}

void onConfetti(uint8_t brightness) {
  Serial.println("Effect: Confetti");
  currentEffect = 2;
  FastLED.setBrightness(map(brightness, 0, 255, 0, 255));
}

void onSinelon(uint8_t brightness) {
  Serial.println("Effect: Sinelon");
  currentEffect = 3;
  FastLED.setBrightness(map(brightness, 0, 255, 0, 255));
}

void onJuggle(uint8_t brightness) {
  Serial.println("Effect: Juggle");
  currentEffect = 4;
  FastLED.setBrightness(map(brightness, 0, 255, 0, 255));
}

void onBPM(uint8_t brightness) {
  Serial.println("Effect: BPM");
  currentEffect = 5;
  FastLED.setBrightness(map(brightness, 0, 255, 0, 255));
}

void onFireBlue(uint8_t brightness) {
  Serial.println("Effect: FireBlue");
  currentEffect = 6;
  FastLED.setBrightness(map(brightness, 0, 255, 0, 255));
}

void onFireChemical(uint8_t brightness) {
  Serial.println("Effect: FireChemical");
  currentEffect = 7;
  FastLED.setBrightness(map(brightness, 0, 255, 0, 255));
}

void onFireAqua(uint8_t brightness) {
  Serial.println("Effect: Fire Aqua");
  currentEffect = 8;
  FastLED.setBrightness(map(brightness, 0, 255, 0, 255));
}

void onFireBarbiePink(uint8_t brightness) {
  Serial.println("Effect: Fire Barbie Pink");
  currentEffect = 9;
  FastLED.setBrightness(map(brightness, 0, 255, 0, 255));
}

void onFireElectricBlue(uint8_t brightness) {
  Serial.println("Effect: Fire Electric Blue");
  currentEffect = 10;
  FastLED.setBrightness(map(brightness, 0, 255, 0, 255));
}

void onFireGreen(uint8_t brightness) {
  Serial.println("Effect: Fire Green");
  currentEffect = 11;
  FastLED.setBrightness(map(brightness, 0, 255, 0, 255));
}

void onFireOrange(uint8_t brightness) {
  Serial.println("Effect: Fire Orange");
  currentEffect = 12;
  FastLED.setBrightness(map(brightness, 0, 255, 0, 255));
}

void onFirePurple(uint8_t brightness) {
  Serial.println("Effect: Fire Purple");
  currentEffect = 13;
  FastLED.setBrightness(map(brightness, 0, 255, 0, 255));
}

void onFireWhite(uint8_t brightness) {
  Serial.println("Effect: Fire White");
  currentEffect = 14;
  FastLED.setBrightness(map(brightness, 0, 255, 0, 255));
}

void onFireYellow(uint8_t brightness) {
  Serial.println("Effect: Fire Yellow");
  currentEffect = 15;
  FastLED.setBrightness(map(brightness, 0, 255, 0, 255));
}
