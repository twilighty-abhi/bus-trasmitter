#define DEBUG
#include "include.h"

void setup(){
  Serial.begin(115200);
  LoRa_init(LORA_TXEN);
  // init_accli();
  // calibrate();
  // gps_init(1);
}

void loop(){   
  // getAccliration();
  // Serial.println(str);
  // delay(10);
  LoRa_Tx("HI");
}