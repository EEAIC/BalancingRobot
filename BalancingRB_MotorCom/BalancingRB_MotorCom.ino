#include <SoftwareSerial.h>
#include "ENC_Motor.h"
#include "PID.h"
#include "MPU6050.h"

SoftwareSerial Serial_M(13,12);

void setup() {
  pinMode(13, INPUT);
  pinMode(12, OUTPUT);
  Serial.begin(115200);
  Serial_M.begin(115200);
  Motorsetup();
  dmpsetup();
}

void loop() { 
 //runEvery(25){
  dmploop();
  Serial.println(ypr[1]-105);
    Pid(ypr[1]-105);
    //Serial.println(speed);
    Motor_L(speed);
    Motor_R(speed);
// }
}

