#include "mas001.h"
#include "dmd150.h"

MAS001 myShield;
DMD150 myMotor;

void setup() {
  Serial.begin(115200);

}

int val;
void loop() {
  val = myShield.getPot() / 4; // rotation funtion takes input from -255 ~ 255
  Serial.println(val);
  
  if(myShield.button1Clicked()){
  	myMotor.floating(); // Use floating function to soft stop
  	// myMotor.brake(); // Use brake function to hard stop
  }else if(myShield.button2Clicked()){
  	myMotor.rotation(-val);
  }else{
  	myMotor.rotation(val)
    ;
  }
}