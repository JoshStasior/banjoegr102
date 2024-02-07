const int sensorPin = 11;
const int LightStringPin = 5;
const int numLights = 50; //number of lights in the string

#include <Adafruit_NeoPixel.h>

#define PIN_NEO_PIXEL 5  // Arduino pin that connects to NeoPixel
#define NUM_PIXELS 10    // The number of LEDs (pixels) on NeoPixel

Adafruit_NeoPixel NeoPixel(numLights, LightStringPin, NEO_GRB + NEO_KHZ800);
void setup() {
  pinMode(sensorPin, INPUT_PULLUP);

  NeoPixel.begin();
  NeoPixel.setBrightness(100);
  for (int pixel = 0; pixel < 50; pixel++) {
    NeoPixel.setPixelColor(pixel, NeoPixel.Color(0, 255, 0));
    NeoPixel.show();
  }
}

void loop() {
    int n = 55;
    for (int i = 0; i < 5; i++) {
      n = n * 2;
      tone(8, n, 500);
      for (int p = 0; p < numLights; p++) {
        if (i == 0) {
          NeoPixel.setPixelColor(p, NeoPixel.Color(255, 0, 0));
          NeoPixel.show();
        }
        if (i == 1) {
          NeoPixel.setPixelColor(p, NeoPixel.Color(255, 215, 0));
          NeoPixel.show();
        }
        if (i == 2) {
          NeoPixel.setPixelColor(p, NeoPixel.Color(0, 0, 255));
          NeoPixel.show();
        }
        if (i == 3) {
          NeoPixel.setPixelColor(p, NeoPixel.Color(255, 0, 0));
          NeoPixel.show();
        }
        if (i == 4) {
          NeoPixel.setPixelColor(p, NeoPixel.Color(255, 215, 0));
          NeoPixel.show();
        }
      }
      delay(500);
    }
  } 
  //test
  
  