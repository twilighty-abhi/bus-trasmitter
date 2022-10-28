#include <SoftwareSerial.h>
#include <TinyGPS.h>
#include "include.h"
/* needs softwareserial.h file 
you need a 4800-baud serial GPS device hooked up on pins 4(rx) and 3(tx)
*/

TinyGPS gps;
SoftwareSerial ss(2, 3);

void setup(){
 Serial.begin(115200);
  ss.begin(9600);
  LoRa_init(LORA_TXEN);
  Serial.print("Simple TinyGPS library v. "); Serial.println(TinyGPS::library_version());
  Serial.println("by Mikal Hart");
  Serial.println();
}

void loop(){   
  // getAccliration();
  // Serial.println(str);
  // delay(10);
  LoRa_Tx("HI");
}
