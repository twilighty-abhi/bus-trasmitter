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

void getAccliration(){
  str = String(DFRobot.readAccX()) + ' '; 
  str += String(DFRobot.readAccY()) + ' ';
  str += String(DFRobot.readAccZ()) + ' ';
  str += String(analogRead(A0)) + ' ';
  str += String(analogRead(A1)) + ' ';
  str += String(analogRead(A2)) + ' ';
}  

