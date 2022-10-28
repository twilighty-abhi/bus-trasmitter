float x_of,y_of,z_of;
int cnt=0;
void init_accli(){
  while(!DFRobot.begin()){
     Serial.println("Communication failed, check the connection and I2C address setting when using I2C communication.");
  }
  Serial.print("chip id : ");
  Serial.println(DFRobot.getID(),HEX);
  DFRobot.softReset();
  DFRobot.continRefresh(true);
  DFRobot.setDataRate(DFRobot_LIS2DW12::eRate_50hz);
  DFRobot.setRange(DFRobot_LIS2DW12::e2_g);
  DFRobot.setFilterPath(DFRobot_LIS2DW12::eLPF);
  DFRobot.setFilterBandwidth(DFRobot_LIS2DW12::eRateDiv_4);
  DFRobot.setPowerMode(DFRobot_LIS2DW12::eContLowPwrLowNoise2_14bit);
}

//init update 
void hpf(float max){
    if(x<max) x=0.0;

    if(y<max) y=0.0;

    if(y<max) z=0.0;
}

void sign_encode(){
  if(x<0){a=1;x=-x;}
  else    a=0;
  if(y<0){b=1;y=-y;}
  else    b=0;
  if(z<0){c=1;z=-z;}
  else    c=0;

  sign_index = a*4 + b*2 + c*1;
}

unsigned short len(unsigned short num){
    int i;
    for(i=0;num>0;i++){
        num/=10;
    }
    return i;
}
void calibrate(){
  while(cnt<1000){
    cnt++;
    x = DFRobot.readAccX();
    y = DFRobot.readAccY();
    z = DFRobot.readAccZ();
    x_of += (0.0-x)*-1;
    y_of += (0.0-y)*-1;
    z_of += (1000.0-z);
  }
}
void getAccliration(){
  
  // x = DFRobot.readAccX() - x_of/cnt;
  // y = DFRobot.readAccY() - y_of/cnt;
  // z = DFRobot.readAccZ() - z_of/cnt;
  
   x = analogRead(A0);
   y = analogRead(A1);
   z = analogRead(A2);
  
  //calib
  //   s_x += x;
  //   s_y += y;
  //   s_z += z;

  // sign_encode();
  // hpf(0.15);

  // str = String(len(x))+String(len(y))+String(len(z));
  // str += String(x)+' '+String(y)+' '+String(z);
  // 
  str =  String(sign_index)   + ' ';
  str += String(x,1) + ' '; 
  str += String(y,1) + ' ';
  str += String(z,1) + ' ';
  // str += String(DFRobot.readAccX()) + ' '; 
  // str += String(DFRobot.readAccY()) + ' ';
  // str += String(DFRobot.readAccZ()) + ' ';

  // str += String(s_x/count)    + ' ';
  // str += String(s_y/count)    + ' ';
  // str += String(s_z/count)    + ' ';
  // count++; //calib

}  

