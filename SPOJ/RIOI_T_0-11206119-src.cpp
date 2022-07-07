#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <string>
typedef unsigned long long ull;
typedef long long ll;

using namespace std;
bool fun(int a, int b)
{
	return a>b;
}
int main()
{
	int t, n;
	int a[100004], b[100004];
	ll sol;
	scanf("%d", &t);
	while(t--)
	{
		sol = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &b[i]);
		}
		sort(a, a+n, fun);
		for (int i = 0; i < n; i++)
		{
			sol+=(ll)(a[i]*b[i]);
		}
		printf("%lld\n", sol);
		
		
	}
	
	return 0;
}
