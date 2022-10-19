void LoRa_init(int EN){
    pinMode(EN,OUTPUT);
    digitalWrite(EN,HIGH); 

    #ifndef DEBUG
        state = LoRa.begin();
        state = LoRa.setFrequency(UL,true);
        state = LoRa.setSpreadingFactor(SF);
        state = LoRa.setBandwidth(BW); 
        state = LoRa.setOutputPower(TX_POW);
    #endif

    #ifdef DEBUG
        Serial.println("Starting LoRa");
        state = LoRa.begin();
        debug();

        Serial.print("Setting Frequncy (hz) : ");
        Serial.println(UL);
        state = LoRa.setFrequency(UL,true);
        debug();

        Serial.print("Setting Spreading Factor : ");
        Serial.println(SF);
        state = LoRa.setSpreadingFactor(SF);
        debug();

        Serial.print("Setting Trasmit Power : ");
        Serial.println(TX_POW);
        state = LoRa.setOutputPower(TX_POW);
        debug();

        Serial.print("Setting Bandwidth (khz) : ");
        Serial.println(BW);
        state = LoRa.setBandwidth(BW);
        debug();
    #endif 
}

void LoRa_Tx(String text){
    state = LoRa.transmit(text);
    if(state==0){
        Serial.println("Sucess!");
        Serial.print(F("Datarate:\t"));
        Serial.print(LoRa.getDataRate());
        Serial.println(F(" bps"));
    }
    #ifdef DEBUG
        debug();
    #endif
}

void LoRa_Rx(){

    state = LoRa.receive(str);
    if(state==0){
        Serial.print(str);
        Serial.print(F(" "));
        Serial.print(LoRa.getRSSI());
        Serial.print(F(" "));
        Serial.print(LoRa.getSNR());
    }
    #ifdef DEBUG
        debug();
    #endif
}
