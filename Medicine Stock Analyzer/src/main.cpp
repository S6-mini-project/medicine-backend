#include <Arduino.h>
#include "HX711.h"

#define DOUT 14
#define CLK 12

HX711 scale;
float calibration_factor=888;
int units;
void setup()
{  
   //float calibration_factor = 888;
   Serial.begin(9600);
   Serial.println("HX711 calibration sketch");
   scale.begin(14,12);
   Serial.println("Remove all wieghts");
   Serial.println("After reading place known weights");
   Serial.println("Press a or + to increase calibration factor");
   Serial.println("Press z or - to decrease the calibration factor");

   scale.set_scale();
   scale.tare();//Reset scale value to 0

   long zero_factor=scale.read_average();//Get baseline reading
   Serial.println("Zero Factor:");
   Serial.print(zero_factor);
}
void loop()
{
 scale.set_scale(calibration_factor);//Adjust to this calibration factor
 Serial.println("Reading....");
 units = scale.get_units(), 10;
if(units<0)
 {
    units=0;
 }
   if(units>=0)
   {
    Serial.println(units);
    Serial.print(" grams");
    Serial.println();
    Serial.println("Calibration Factor:");
    Serial.print(calibration_factor);
    delay(5000);
   }
   if(Serial.available())
   {
    char temp= Serial.read();
    if(temp=='a'||temp=='+')
    {
      calibration_factor=calibration_factor+1;
    }
    else if(temp=='z'||temp=='-')
    {
      calibration_factor=calibration_factor-1;
    }
   }
}
