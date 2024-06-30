#include "mas001.h"
#include "sbd10.h"

MAS001 myShield;
SBD10 myDevice;
void setup() {
  myDevice.init();
  Serial.begin(115200);
}

void loop() {

  if(myShield.button1Clicked()){
    myDevice.enable(LOW);
    myDevice.direction(HIGH);
    myDevice.pulseControl(750, 300);
    myDevice.direction(LOW);
    myDevice.pulseControl(250, 300);
    myDevice.pulseControl(0);
    delay(200);
    myDevice.pulseControl(250, 300);
    myDevice.pulseControl(0);
    delay(200);
    myDevice.pulseControl(250, 300);
    myDevice.pulseControl(0);
    delay(200);
  }else{
    myDevice.enable(HIGH);
    myDevice.continuousPulse(0);
  }

  delay(50);
}