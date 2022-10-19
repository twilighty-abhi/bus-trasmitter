#include <stdio.h>
int main(){
    char a[]={'2','3','4','5'};
    int i,j,k;
    for(i=0;i<4;i++){
       for(j=0;j<4;j++){
          for(k=0;k<3;k++){
            printf("%c%c%c,\n",a[i],a[j],a[k]);
          }
       } 
    }
}