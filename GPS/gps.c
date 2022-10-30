void gps_init(){
  ss.begin(9600);
}

void GPS_update(){
  float flat, flon;
  unsigned long age;
  gps.f_get_position(&flat, &flon, &age);
  str=String(flat == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flat,6)+" "+String(flon == TinyGPS::GPS_INVALID_F_ANGLE ? 0.0 : flon,6);
}
