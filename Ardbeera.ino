
#include "teensy_config.h"

void setup()
{
  Serial.begin(115200);
  Serial.println("\n   ~ Ardbeera Start ~ ");
  
  pinMode(ONBOARD_LED, OUTPUT);
  digitalWrite(ONBOARD_LED, HIGH);
}


void loop()
{

}

