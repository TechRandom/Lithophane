#include <FastLED.h>
#define LED_PIN     3
#define NUM_LEDS    6
#define BRIGHTNESS  255
#define LED_TYPE    WS2811
#define COLOR_ORDER GRB
CRGB leds[NUM_LEDS];

int j = 0;

void setup() {
    delay( 1500 ); // power-up safety delay
    FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
    FastLED.setBrightness(  BRIGHTNESS );
    randomSeed(analogRead(0));
}

void loop() {
  rainbow_fade(); 
}

void rainbow_fade(){
  if(j > 255)
    j = 0;
  for (int i = 0; i < NUM_LEDS; i++){
    leds[i] = CHSV( j, 255, 255);
  }
  j++;
  FastLED.show();
  delay(100);
}
