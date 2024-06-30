#include "mas001.h"
#include "sbd10.h"

MAS001 mas001;
SBD10 sbd10;


bool ena = 0;
bool dir = 0;
uint16_t pulse = 1000;

void setup() {
  sbd10.init();
  Serial.begin(115200);
}

void loop() {
  
  (mas001.button1Clicked()) ? ena = 1 : ena = 0;
  (mas001.button2Clicked()) ? dir = 1 : dir = 0;
  pulse = mas001.getPot();
  (pulse < 16) ? pulse = 16: pulse;
  Serial.println(pulse);

  sbd10.enable(ena);
  sbd10.direction(dir);
  sbd10.continuousPulse(pulse);

  delay(10);
}
