#ifndef LORA_H
#define LORA_H
    /*
      LoRa Uplink   -> From Base Tx to Rx
      LoRa Downlink -> Rx response 
      BW Max        -> 500.0 khz
      Max Tx Power  -> 22 dBm
      SF Max        -> 12
    */
    
    #define UL     867.1
    #define DL     867.3  
    #define TX_POW 22
    #define SF     12
    #define BW     500.0
    
    #ifdef DEBUG
      #include "debug.c"
    #endif

    #ifndef LORA_C
    #define LORA_C
      #include "LoRa.c"
    #endif

#endif