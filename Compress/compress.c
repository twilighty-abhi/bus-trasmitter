// void hpf(float max){
//     if(x<max) x=0.0;

//     if(y<max) y=0.0;

//     if(y<max) z=0.0;
// }

void sign_encode(){

  if(x_DF<0){a=1;x_DF=-x_DF;}
  else    a=0;
  if(y_DF<0){b=1;y_DF=-y_DF;}
  else    b=0;
  if(z_DF<0){c=1;z_DF=-z_DF;}
  else    c=0;

  sign_index = (a*4 + b*2 + c*1);

}

unsigned short len(unsigned short num){
    unsigned short s_d[] = {1000,100,10,1};
    int i;
    for(i=0;i<4;i++){
        if((int)(num/s_d[i])==0){
            break;
        }
    }
    return i+1;
}

