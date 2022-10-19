void gps_init(unsigned short cold_start){
  unsigned int sec=0;
  unsigned int temp=60;
  ss.begin(9600);
  Serial.println(TinyGPS::library_version());
  for(sec=0;sec<cold_start;sec++){
    Serial.print((int)(cold_start-sec)/60);
    Serial.print(":");
    Serial.print(temp);
    Serial.println(" remaining");
    if(sec==59){
        temp=59;
    }
    else{
        temp--;
    }
    delay(1000);
  }
}

void GPS_update(unsigned short wait){

  gps.f_get_position(&flat, &flon, &age);

  flat = flat == TinyGPS::GPS_INVALID_F_ANGLE ? 0 : flat;
  flon = flon == TinyGPS::GPS_INVALID_F_ANGLE ? 0 : flon;
  sat  = gps.satellites() == TinyGPS::GPS_INVALID_SATELLITES ? 0 : gps.satellites();
  hdop = gps.hdop() == TinyGPS::GPS_INVALID_HDOP ? 0 : gps.hdop();
  
  str +=  ' ';
  str +=  String(flat,6) + ' ';
  str +=  String(flon,6) + ' ';
  str +=  String(sat)    + ' ';
  str +=  String(hdop)   + ' ';

  gps.stats(&chars, &sentences, &failed);
  if(chars>10000)
    chars=1;
  if (chars == 0)
    Serial.println("** No characters received from GPS: check wiring **");
  delay(wait);
}