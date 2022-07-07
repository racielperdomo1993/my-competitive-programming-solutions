#include <stdio.h>
#include <stdlib.h>

int main(){
    int t,nC,nM,maxNG,maxNM;
    scanf("%d",&t);
    while(t-->0){
      scanf("%d",&nC);
      scanf("%d",&nM);
      maxNG = maxNM = 0;
      int array1[nC];
      int array2[nM];
      int i;
      for(i = 0;i<nC;i++){
          scanf("%d",&array1[i]);
          if(array1[i]>maxNG){
             maxNG = array1[i];
          }  
      }
      
      for(i = 0;i<nM;i++){
          scanf("%d",&array2[i]);
          if(array2[i]>maxNG){
             maxNM = array2[i];
          }  
      }
      
      if(maxNM >= maxNG){
         printf("MechaGodzilla\n");
      }else{
         printf("Godzilla\n");
      }
      
    }      
  return 0;
}