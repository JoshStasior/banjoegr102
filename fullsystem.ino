const int sensorPin = 11;
const int LightStringPin = 5;
const int numLights = 50; //number of lights in the string
const int speakerPin = 8;
const int speakerPin2 = 2;

int delayStart;
int currentState =0;
  //If Current State = 0 (Magnet connected, still flying)
  //If Current State = 1 (Magnet disconnected, thus drone landed)
  //If Current State = 2 (Magnet disconnected, accelerometer triggered, "Device essentially killed")
int state;  // 0 close - 1 open switch
int delayTime = 10000; //miliseconds

int xpin = A3;                
int ypin = A2;                
int zpin = A1; 
int xvalue;
int yvalue;
int zvalue;


#include <Adafruit_NeoPixel.h>

#define PIN_NEO_PIXEL 5  // Arduino pin that connects to NeoPixel
#define NUM_PIXELS 10    // The number of LEDs (pixels) on NeoPixel

Adafruit_NeoPixel NeoPixel(numLights, LightStringPin, NEO_GRB + NEO_KHZ800);
bool accelerometerTriggered;
void setup() {
  pinMode(sensorPin, INPUT_PULLUP);

  NeoPixel.begin();
  NeoPixel.setBrightness(100);
  for (int pixel = 0; pixel < numLights; pixel++) {
    NeoPixel.setPixelColor(pixel, NeoPixel.Color(0, 255, 0));
    NeoPixel.show();
  }
  currentState = 1;
  accelerometerTriggered=false;
  delayStart=millis();
}

void loop() {
  state = digitalRead(sensorPin);
 if(currentState==1){
    if((millis() - delayStart) >= delayTime){ // once 10 seconds passes
    //code to read accelerometer and decide whether to turn accelerometerTriggered to true (if it's triggered)
      int zvalue1 = analogRead(zpin);
      int yvalue1 = analogRead(ypin);
      int xvalue1 = analogRead(xpin);

      delay(200);

      int zvalue2 = analogRead(zpin);
      int yvalue2 = analogRead(ypin);
      int xvalue2 = analogRead(xpin);
      //z = map(zvalue, 265, 393, -100, 100);
      //float zg2 = (float)z/(100.00);

      if (abs(zvalue2) < abs(zvalue2)-40)
      {
        accelerometerTriggered = true;
      }
      if (abs(zvalue2) > abs(zvalue1)+40)
      {
        accelerometerTriggered = true;
      }
      if (abs(yvalue2) < abs(yvalue2)-40)
      {
        accelerometerTriggered = true;
      }
      if (abs(yvalue2) > abs(yvalue1)+40)
      {
        accelerometerTriggered = true;
      }
      if (abs(xvalue2) < abs(xvalue2)-40)
      {
        accelerometerTriggered = true;
      }
      if (abs(xvalue2) > abs(xvalue1)+40)
      {
        accelerometerTriggered = true;
      }
    }
    if(accelerometerTriggered==true){
      currentState=2;
    }
  } 
  if(currentState==1){
    int n = 55;
    for (int i = 0; i < 5; i++) {
      n = n * 2;
      tone(speakerPin, n, 500);
     // tone(speakerPin2, n, 500);

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
      delay(300);
    }
  } else {
    noTone(speakerPin);
    //noTone(speakerPin2);
    for (int p = 0; p < numLights; p++) {
      NeoPixel.setPixelColor(p, NeoPixel.Color(0, 0, 0));
      NeoPixel.show();
    }
  }
  } 