#ifndef GLOBALS_H
#define GLOBALS_H
  int state;
  unsigned short a,b,c;
  

  String str;
  unsigned short sign_index=0;
  
  SX1262 LoRa = new Module(LORA_CS, LORA_DIO1, LORA_RST, LORA_BUSY);
  // DFRobot_LIS2DW12_I2C DFRobot;

  
#endif
