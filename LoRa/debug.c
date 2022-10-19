
void debug(){
    if(state!=0){
        Serial.println("These are the common cause(s) of this error     ");
        if(state==-2){
            Serial.println("   -> Incorret connection");
            Serial.println("   -> No power to chip");
            Serial.println("   -> You might burned the chip");
        }
        else if(state==-5)
            Serial.println("   -> Trasmitter timed out");
        else if(state==-6)
            Serial.println("   -> No Trasmitter");
        else if(state==-7)
            Serial.println("   -> Packet Damaged in Trasmisson, retransmit required");
        else if(state==-705)
            Serial.println("   -> Incorret SPI timeout");
        else if(state==-706)
            Serial.println("   -> Incorret connection of SPI pins");
        else{
            Serial.print("   -> Unknown error");
            Serial.println(state);
        } 
    
    }
    
}
