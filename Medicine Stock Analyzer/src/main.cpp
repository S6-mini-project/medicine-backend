#include <Arduino.h>
//CALIBRATION PROGRAM

// #include <HX711_ADC.h>
// #if defined(ESP8266)|| defined(ESP32) || defined(AVR)
// #include <EEPROM.h>
// #endif

// //pins:
// const int HX711_dout = 14; //mcu > HX711 dout pin
// const int HX711_sck = 12; //mcu > HX711 sck pin

// //HX711 constructor:
// HX711_ADC LoadCell(HX711_dout, HX711_sck);

// const int calVal_eepromAdress = 0;
// unsigned long t = 0;
// void calibrate() {
//   Serial.println("***");
//   Serial.println("Start calibration:");
//   Serial.println("Place the load cell an a level stable surface.");
//   Serial.println("Remove any load applied to the load cell.");
//   Serial.println("Send 't' from serial monitor to set the tare offset.");

//   boolean _resume = false;
//   while (_resume == false) {
//     LoadCell.update();
//     if (Serial.available() > 0) {
//       if (Serial.available() > 0) {
//         char inByte = Serial.read();
//         if (inByte == 't') LoadCell.tareNoDelay();
//       }
//     }
//     if (LoadCell.getTareStatus() == true) {
//       Serial.println("Tare complete");
//       _resume = true;
//     }
//   }

//   Serial.println("Now, place your known mass on the loadcell.");
//   Serial.println("Then send the weight of this mass (i.e. 100.0) from serial monitor.");

//   float known_mass = 0;
//   _resume = false;
//   while (_resume == false) {
//     LoadCell.update();
//     if (Serial.available() > 0) {
//       known_mass = Serial.parseFloat();
//       if (known_mass != 0) {
//         Serial.print("Known mass is: ");
//         Serial.println(known_mass);
//         _resume = true;
//       }
//     }
//   }

//   LoadCell.refreshDataSet(); //refresh the dataset to be sure that the known mass is measured correct
//   float newCalibrationValue = LoadCell.getNewCalibration(known_mass); //get the new calibration value

//   Serial.print("New calibration value has been set to: ");
//   Serial.print(newCalibrationValue);
//   Serial.println(", use this as calibration value (calFactor) in your project sketch.");
//   Serial.print("Save this value to EEPROM adress ");
//   Serial.print(calVal_eepromAdress);
//   Serial.println("? y/n");

//   _resume = false;
//   while (_resume == false) {
//     if (Serial.available() > 0) {
//       char inByte = Serial.read();
//       if (inByte == 'y') {
// #if defined(ESP8266)|| defined(ESP32)
//         EEPROM.begin(512);
// #endif
//         EEPROM.put(calVal_eepromAdress, newCalibrationValue);
// #if defined(ESP8266)|| defined(ESP32)
//         EEPROM.commit();
// #endif
//         EEPROM.get(calVal_eepromAdress, newCalibrationValue);
//         Serial.print("Value ");
//         Serial.print(newCalibrationValue);
//         Serial.print(" saved to EEPROM address: ");
//         Serial.println(calVal_eepromAdress);
//         _resume = true;

//       }
//       else if (inByte == 'n') {
//         Serial.println("Value not saved to EEPROM");
//         _resume = true;
//       }
//     }
//   }

//   Serial.println("End calibration");
//   Serial.println("***");
//   Serial.println("To re-calibrate, send 'r' from serial monitor.");
//   Serial.println("For manual edit of the calibration value, send 'c' from serial monitor.");
//   Serial.println("***");
// }

// void changeSavedCalFactor() {
//   float oldCalibrationValue = LoadCell.getCalFactor();
//   boolean _resume = false;
//   Serial.println("***");
//   Serial.print("Current value is: ");
//   Serial.println(oldCalibrationValue);
//   Serial.println("Now, send the new value from serial monitor, i.e. 696.0");
//   float newCalibrationValue;
//   while (_resume == false) {
//     if (Serial.available() > 0) {
//       newCalibrationValue = Serial.parseFloat();
//       if (newCalibrationValue != 0) {
//         Serial.print("New calibration value is: ");
//         Serial.println(newCalibrationValue);
//         LoadCell.setCalFactor(newCalibrationValue);
//         _resume = true;
//       }
//     }
//   }
//   _resume = false;
//   Serial.print("Save this value to EEPROM adress ");
//   Serial.print(calVal_eepromAdress);
//   Serial.println("? y/n");
//   while (_resume == false) {
//     if (Serial.available() > 0) {
//       char inByte = Serial.read();
//       if (inByte == 'y') {
// #if defined(ESP8266)|| defined(ESP32)
//         EEPROM.begin(512);
// #endif
//         EEPROM.put(calVal_eepromAdress, newCalibrationValue);
// #if defined(ESP8266)|| defined(ESP32)
//         EEPROM.commit();
// #endif
//         EEPROM.get(calVal_eepromAdress, newCalibrationValue);
//         Serial.print("Value ");
//         Serial.print(newCalibrationValue);
//         Serial.print(" saved to EEPROM address: ");
//         Serial.println(calVal_eepromAdress);
//         _resume = true;
//       }
//       else if (inByte == 'n') {
//         Serial.println("Value not saved to EEPROM");
//         _resume = true;
//       }
//     }
//   }
//   Serial.println("End change calibration value");
//   Serial.println("***");
// }

// void setup() {
//   Serial.begin(9600); delay(10);
//   Serial.println();
//   Serial.println("Starting...");

//   LoadCell.begin();
//   //LoadCell.setReverseOutput(); //uncomment to turn a negative output value to positive
//   unsigned long stabilizingtime = 2000; // preciscion right after power-up can be improved by adding a few seconds of stabilizing time
//   boolean _tare = true; //set this to false if you don't want tare to be performed in the next step
//   LoadCell.start(stabilizingtime, _tare);
//   if (LoadCell.getTareTimeoutFlag() || LoadCell.getSignalTimeoutFlag()) {
//     Serial.println("Timeout, check MCU>HX711 wiring and pin designations");
//     while (1);
//   }
//   else {
//     LoadCell.setCalFactor(1.0); // user set calibration value (float), initial value 1.0 may be used for this sketch
//     Serial.println("Startup is complete");
//   }
//   while (!LoadCell.update());
//   calibrate(); //start calibration procedure
// }

// void loop() {
//   static boolean newDataReady = 0;
//   const int serialPrintInterval = 0; //increase value to slow down serial print activity

//   // check for new data/start next conversion:
//   if (LoadCell.update()) newDataReady = true;

//   // get smoothed value from the dataset:
//   if (newDataReady) {
//     if (millis() > t + serialPrintInterval) {
//       float i = LoadCell.getData();
//       Serial.print("Load_cell output val: ");
//       Serial.println(i);
//       newDataReady = 0;
//       t = millis();
//     }
//   }

//   // receive command from serial terminal
//   if (Serial.available() > 0) {
//     char inByte = Serial.read();
//     if (inByte == 't') LoadCell.tareNoDelay(); //tare
//     else if (inByte == 'r') calibrate(); //calibrate
//     else if (inByte == 'c') changeSavedCalFactor(); //edit calibration value manually
//   }

//   // check if last tare operation is complete
//   if (LoadCell.getTareStatus() == true) {
//     Serial.println("Tare complete");
//   }

// }

//WEIGHT MEASUREMENT PROGRAM

#include <HX711_ADC.h>
#if defined(ESP8266)|| defined(ESP32) || defined(AVR)
#include <EEPROM.h>
#include "SSD1306Wire.h"
#include<Wire.h>
#include<ESP8266WiFi.h>
#include<WiFiClient.h>
#include<ESP8266WebServer.h>
#include<ESP8266mDNS.h>
#include<SPI.h>
//#include<MFRC522.h>


#endif
SSD1306Wire display(0x3c,D0,D1);//Try GPIO pins of D0 and D1  Refer techtutorialsx.com


//pins:
const int HX711_dout = 14; //mcu > HX711 dout pin
const int HX711_sck = 12; //mcu > HX711 sck pin

//HX711 constructor:
HX711_ADC LoadCell(HX711_dout, HX711_sck);

float weight;

const int calVal_eepromAdress = 0;
unsigned long t = 0;

 const char* ssid = "HUAWEI-kccl";// 
const char* password = "9847452948";
//WiFiClient client;
char server[] = "192.168.18.222"; 


WiFiClient client;  
void Sending_to_phpadmindatabase()
{
  if (client.connect(server,80))
  {
    Serial.println("Connected");

    //make a http request
    // Serial.print("GET /testcase/test.php?weight=");
    client.print("GET http://localhost/medicine/test.php?weight=");
    Serial.println(weight);
    // client.print("weight=");
    client.print(weight);
     client.print(" ");      //SPACE BEFORE HTTP/1.1
    client.print("HTTP/1.1");
    client.println();
    client.println("Host: 192.168.1.7");
    client.println("Connection: close");
    client.println();
    //  client.print(String("GET http://your_hostname/testcase/testcase.php?") + 
    //                       ("&weihumidity=") + humidity +
    //                       " HTTP/1.1\r\n" +
    //              "Host: " + host + "\r\n" +
    //              "Connection: close\r\n\r\n");
  } else 
  {
    // if you didn't get a connection to the server:
    Serial.println("connection failed");
  }
 }
  


void setup() {
  Serial.begin(9600); delay(10);
  Serial.println();
  Serial.println("Starting...");


  LoadCell.begin();
  //LoadCell.setReverseOutput(); //uncomment to turn a negative output value to positive
  float calibrationValue; // calibration value (see example file "Calibration.ino")
  //calibrationValue = 696.0; // uncomment this if you want to set the calibration value in the sketch
#if defined(ESP8266)|| defined(ESP32)
  EEPROM.begin(512); // uncomment this if you use ESP8266/ESP32 and want to fetch the calibration value from eeprom
#endif
  EEPROM.get(calVal_eepromAdress, calibrationValue); // uncomment this if you want to fetch the calibration value from eeprom

  unsigned long stabilizingtime = 2000; // preciscion right after power-up can be improved by adding a few seconds of stabilizing time
  boolean _tare = true; //set this to false if you don't want tare to be performed in the next step
  LoadCell.start(stabilizingtime, _tare);
  if (LoadCell.getTareTimeoutFlag()) {
    Serial.println("Timeout, check MCU>HX711 wiring and pin designations");
    while (1);
  }
  else {
    LoadCell.setCalFactor(calibrationValue); // set calibration value (float)
    Serial.println("Startup is complete");
  }
//  Serial.println("Initialiazing OLED Display....");
//  display.init();

//  display.flipScreenVertically();
//  display.setFont(ArialMT_Plain_10);
Serial.println();
Serial.println();

Serial.println("Connecting to");
Serial.print(ssid);

WiFi.begin(ssid,password);

while(WiFi.status()!= WL_CONNECTED)
{
  delay(500);
  Serial.print(".");
}
Serial.println("");
Serial.println("Wifi is Connected!");

//Server.begin();
Serial.println("Server Started");
Serial.println(WiFi.localIP());
delay(1000);
Serial.println("Connecting..");

}

void loop() {
  //display.clear();
  // display.setTextAlignment(TEXT_ALIGN_LEFT);
  // display.drawString(0,10,"Jeevan");
  // display.display();
  static boolean newDataReady = 0;
  const int serialPrintInterval = 50; //increase value to slow down serial print activity

  // check for new data/start next conversion:
  if (LoadCell.update()) newDataReady = true;

  // get smoothed value from the dataset:
  if (newDataReady) {
    if (millis() > t + serialPrintInterval) {
       weight = LoadCell.getData();
      Serial.print("Load_cell output val: ");
      if(weight<0)
      {
        weight=0;
        // Serial.println(weight);
      }
      else{
     
        weight=weight*100;
      }
      newDataReady = 0;
      t = millis();
    }
  }

  // receive command from serial terminal, send 't' to initiate tare operation:
  if (Serial.available() > 0) {
    char inByte = Serial.read();
    if (inByte == 't') LoadCell.tareNoDelay();
  }

  // check if last tare operation is complete:
  if (LoadCell.getTareStatus() == true) {
    Serial.println("Tare complete");
  }
  Sending_to_phpadmindatabase();
}
