#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <string>
#include <cstring>
typedef unsigned long long ull;
typedef long long ll;

using namespace std;

int main()
{
	int n, k, sol = 0, num;
	scanf("%d%d", &n,&k);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &num);
		sol += (num%k==0);
	}
	printf("%d\n", sol);
	return 0;
}
