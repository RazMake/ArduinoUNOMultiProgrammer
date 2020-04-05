#include <Adafruit_NeoPixel.h>

#define NUM_LEDS 1
#define DATA_PIN 13

Adafruit_NeoPixel strip(NUM_LEDS, DATA_PIN, NEO_RGB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();
}

void loop() {
  strip.setBrightness(125);
  strip.setPixelColor(0, strip.Color(255,0,0));
  strip.show();

  delay(800);

  strip.setBrightness(0);
  strip.show();
  delay(800);
}
