#include <SoftwareSerial.h>
#include "AdaFruit_NeoPixel_Audio.h"
#define runEvery(t) for (static typeof(t) _lasttime;(typeof(t))((typeof(t))millis() - _lasttime) > (t);_lasttime += (t))

SoftwareSerial Serial_A(12,13);//rx,tx
void setup() {
  pinMode(12, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(115200);
  Ada_setup(); 
}

void loop() {
   Ada_loop();
}

