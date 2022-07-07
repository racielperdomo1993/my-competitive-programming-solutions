#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;
int Pow(long,long);

int main()
{
	int testCases = 0;
	scanf("%d",&testCases);
	while (testCases-- > 0)
	{
		long base , power;
		cin >> base;
		cin >> power;
		printf("%d\n",Pow(base%10,power));
	}
    return 0;
}

int Pow(long base,long power)
{
	if (power == 0)return 1;
	if (power == 1)return base%10;
	
	if (power%2 == 0) return (Pow((base*base)%10,power/2))%10;
	return (base*Pow(base,power -1))%10;
}
