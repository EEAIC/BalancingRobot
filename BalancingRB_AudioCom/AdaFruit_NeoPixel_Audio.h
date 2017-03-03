#include <Adafruit_NeoPixel.h>
#include "Audio_FFT.h"
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN            4
#define NUMPIXELS      32

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int Envelope;
void PIXELRGB_LOW(uint32_t i){
  if(Envelope<15){
      pixels.setPixelColor(i, pixels.Color(200,150,0));
      }
      else if(Envelope>15&&Envelope<18){
      pixels.setPixelColor(i, pixels.Color(0,150,200));
      }
      else{
      pixels.setPixelColor(i, pixels.Color(0,0,200));  
      }
  }

void PIXELRGB_HIGH(int i){
  if(Envelope<15){
      pixels.setPixelColor(i, pixels.Color(0,150,0));
      }
      else if(Envelope>15&&Envelope<18){
      pixels.setPixelColor(i, pixels.Color(0,100,200));
      }
      else{
      pixels.setPixelColor(i, pixels.Color(100,100,100));  
      }
  }  

void Ada_setup() {
  
  pixels.begin();
  pixels.setBrightness(10);
}

void Ada_loop() {
    Audio_FFT_loop();  
    Envelope = analogRead(A1);
    Envelope = map(Envelope, 0, 656, 0, 250);
    
  for(uint32_t i=0; i<8; i++) {
     if(i<*Audio[0]&&i<5){
      PIXELRGB_LOW(i);
      }
     else if (i<*Audio[0]&&i>=5){
      PIXELRGB_HIGH(i);
      } 
     else{
      pixels.setPixelColor(i, pixels.Color(0,0,0));
      }
  }
  for(uint32_t i=8; i<16; i++) {
    if (i-8<*Audio[1]&&i<5+8){
      PIXELRGB_LOW(i);
      }
     else if (i-8<*Audio[1]&&i>=5+8){
      PIXELRGB_HIGH(i);
      } 
     else{
      pixels.setPixelColor(i, pixels.Color(0,0,0));
      }
  }
  for(uint32_t i=16; i<24; i++) {
    if (i-16<*Audio[2]&&i<5+16){
      PIXELRGB_LOW(i);
      }
     else if (i-16<*Audio[2]&&i>=5+16){
      PIXELRGB_HIGH(i);
      } 
     else{
     pixels.setPixelColor(i, pixels.Color(0,0,0));
      }
  }
  for(uint32_t i=24; i<32; i++) {
    if (i-24<*Audio[3]&&i<5+24){
      PIXELRGB_LOW(i);
      }
     else if (i-24<*Audio[3]&&i>=5+24){
      PIXELRGB_HIGH(i);
      } 
     else{
      pixels.setPixelColor(i, pixels.Color(0,0,0));
      }
  }
  pixels.show(); 
}

