#ifndef LIS2DW12_H

  #define LIS2DW12_H
  #define G_M 0.009806 //milli g to g factor
  #define G   9.806
  // xyz calib factor
  #define X_D -0.28
  #define Y_D -0.41
  #define Z_D 9.826 // (-9.806 accli due to gravity)

  #if defined(ESP32) || defined(ESP8266)
      #define LIS2DW12_CS  D3
      #elif defined(__AVR__) || defined(ARDUINO_SAM_ZERO)
      #define LIS2DW12_CS 3
      #elif (defined NRF5)
      #define LIS2DW12_CS 2  //The pin on the development board with the corresponding silkscreen printed as P24
  #endif

  #include "LIS2DW12.c"

#endif

