#include <SoftwareSerial.h>
#include <TinyGPS.h>
#include "include.h"

/*  requires  SoftwareSerial
you need a 4800-baud serial GPS device hooked up on pins 4(rx) and 3(tx).
*/

TinyGPS gps;
SoftwareSerial ss(2, 3);

void setup()
{
  Serial.begin(115200);
  ss.begin(9600);
  LoRa_init(LORA_TXEN);
  Serial.print("Simple TinyGPS library v. "); Serial.println(TinyGPS::library_version());
  Serial.println("by Mikal Hart");
  Serial.println();
}

void loop()
{
  bool newData = false;
  unsigned long chars;
  unsigned short sentences, failed;

  // For one second we parse GPS data and report some key values
  for (unsigned long start = millis(); millis() - start < 1000;)
  {
    while (ss.available())
    {
      char c = ss.read();
      // Serial.write(c); // uncomment this line if you want to see the GPS data flowing
      if (gps.encode(c)) // Did a new valid sentence come in?
        newData = true;
    }
  }

  if (newData)
  {
    float flat, flon;
    unsigned long age;
    gps.f_get_position(&flat, &flon, &age);
    
    str=String(flat == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flat, 6)+" ";
    str+=String(flon == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flon, 6);
   
    Serial.println(str);
    LoRa_Tx(str);
  }
  
  gps.stats(&chars, &sentences, &failed);
  Serial.print(" CHARS=");
  Serial.print(chars);
  Serial.print(" SENTENCES=");
  Serial.print(sentences);
  Serial.print(" CSUM ERR=");
  Serial.println(failed);
  if (chars == 0)
    Serial.println("** No characters received from GPS: check wiring **");
}
