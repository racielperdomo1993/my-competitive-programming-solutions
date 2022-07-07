#include <stdio.h>
int main()
{
	int t,x,y;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&x,&y);
		if((x!=y)&&(x!=(y+2))){
		printf("No Number\n");
		}
		if(x==y&&x%2==0){
			printf("%d\n",(2*x));
		}else{
		if(x==y&&x%2!=0){
			printf("%d\n",((2*x)-1));
		}
		if((x==(y+2))&&(x%2==0)){
			printf("%d\n",(x+y));
		}
		if((x==(y+2))&&(x%2!=0)){
			printf("%d\n",((y+x)-1));
		}
			}
}
		return 0;
}