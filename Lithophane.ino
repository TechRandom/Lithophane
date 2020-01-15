#include <FastLED.h>
#define LED_PIN     3
#define NUM_LEDS    4
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

void loop(){
  white();
  for(int i = 0; i < 510; i++){
    rainbow_fade();
  }
  animation();
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

void white(){
  for (int i = 0; i < NUM_LEDS; i++){
    leds[i] = CRGB( 255, 255, 255);
  }
  FastLED.show();
  delay(5000);
}

void animation(){
  int t = 0;
  int color1 = 0;
  int color2 = 96;
  for (int i = 0; i < NUM_LEDS; i++){
    leds[i] = CHSV( color1, 255, 255);
  }
  while(t < 10){
    fade(color1, color2);
    t++;
    delay(500);
  }
}

void fade(int color1, int color2){
  int location = random(40)%4;
  if(color1 < color2){
    for(int i = color1; i < color2; i++){
      leds[location] = CHSV( i, 255, 255);
      FastLED.show();
    }
    for(int i = color2; i >= color1; i--){
      leds[location] = CHSV( i, 255, 255);
      FastLED.show();
    }
  }
  if(color1 > color2){
    for(int i = color1; i > color2; i--){
      leds[location] = CHSV( i, 255, 255);
      FastLED.show();
    }
    for(int i = color2; i <= color1; i++){
      leds[location] = CHSV( i, 255, 255);
      FastLED.show();
    }
  }
}
