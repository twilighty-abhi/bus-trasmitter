unsigned short len(unsigned short num,String str){
    unsigned short s_d[] = {1000,100,10,1};
    int i;
    for(i=0;i<4;i++){
        if((int)(num/s_d[i])==0){
            break;
        }
    }
    return i+1;
}