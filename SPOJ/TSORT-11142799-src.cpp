
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
//tomaso
//daripoll


int main()
{
	int n, arr[1000001];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	sort(arr, arr+n);
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", arr[i]);
	}
	
	return 0;
}
/*
int main()
{
	int t, n;
	string cad[50005];
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			cin >> cad[i];
		}
		sort(cad, cad+n);
		for (int i = 0; i < n; i++)
		{
			cout << cad[i] << endl;
		}
		
		
	}
	
	
	return 0;
}*/
