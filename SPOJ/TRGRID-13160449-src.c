#include <stdio.h>
int main(){
    int t;
    int rows,columns;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&rows,&columns);
        if(columns>=rows){
            if(rows%2==0)
                printf("L\n");

            else printf("R\n");

        }
        else{
            if(columns%2==0)printf("U\n");
            else printf("D\n");
        }
    }
    return 0;
    }