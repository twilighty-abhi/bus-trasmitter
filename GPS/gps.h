#ifndef GPS_H
#define GPS_H
   unsigned long chars;
   unsigned short sentences, failed;
   bool newData;
   unsigned short sat=0,hdop=0; 
   float flat=0, flon=0;
   unsigned long age;
   #include "gps.c"
#endif