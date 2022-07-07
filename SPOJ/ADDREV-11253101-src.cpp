#include <cstdio>
#include <cstring>
#include <cmath>

int main()
{
	int t;
	scanf("%d", &t);
	char num1[3000], num2[3000];
	while(t--)
	{
		scanf("%s %s", num1, num2);
		long long suma1 = 0;
		long long suma2 = 0;
		int len1 = strlen(num1);
		int len2 = strlen(num2);
		int cont1 = 0;
		int cont2 = 0;
		
		for(int i = 0; i < len1; i++){
			suma1 += (num1[i] - 48) * pow(10.0, cont1++);
		}
		
		for(int j = 0; j < len2; j++){
			suma2 += (num2[j] - 48) * pow(10.0, cont2++);
		}
		long long c = suma1 + suma2;
		
		while(c % 10 == 0){
			c = c/10;
		}
		
		while(c != 0){
			printf("%lld", c%10);
			c = c/10;
		}
		printf("\n");
	}
		
		return 0;
}