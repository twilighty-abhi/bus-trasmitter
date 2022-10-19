#ifndef GLOBALS_H
#define GLOBALS_H
  int state;
  unsigned short a,b,c;
  float x,y,z,s_x,s_y,s_z;
  float dt = 0.01;
  String str;
  unsigned short sign_index=0;
  SX1262 LoRa = new Module(LORA_CS, LORA_DIO1, LORA_RST, LORA_BUSY);
  DFRobot_LIS2DW12_I2C DFRobot;
  TinyGPS gps;
  SoftwareSerial ss(5,4);
#endif