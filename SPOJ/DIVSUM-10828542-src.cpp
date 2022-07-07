#include <stdio.h>
#include <memory.h>

int suma[500001];

int main() {
	for(int i=2;i<500001;i++)
		suma[i]=1;
	
	for(int i=2;i<=250000;i++)
		for(int j=i+i;j<500001;j+=i)
			suma[j]+=i;

	suma[0]=suma[1]=0;
	int t,num;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&num);
		printf("%d\n",suma[num]);
	}
	return 0;
}