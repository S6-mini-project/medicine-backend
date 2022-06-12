#include <Arduino.h>
#include "HX711.h"

#define DOUT 14
#define CLK 12

HX711 scale;
void setup()
{  
   //float calibration_factor = 888;
   Serial.begin(9600);
   Serial.println("HX711 calibration sketch");
   scale.begin(14,12);
}
void loop()
{
  int units;
 units = scale.get_units(), 10;
 Serial.print(units);
 if(units<0)
 {
   units=0;
 }
  if(units>0)
  {
    Serial.print(units);
    Serial.print("grams");
  }
}
