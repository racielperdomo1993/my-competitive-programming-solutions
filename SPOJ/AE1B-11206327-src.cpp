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

bool fun(int a, int b)
{
	return a > b;
}
int main()
{
	int n,k,s,arr[1004];
	scanf("%d%d%d", &n,&k,&s);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	sort(arr, arr+n, fun);
	int val = k*s;
	int sol = 0, j = 0;
	while(sol < val)
	{
		sol+=arr[j++];
	}
	printf("%d\n", j);
	
	return 0;
}
