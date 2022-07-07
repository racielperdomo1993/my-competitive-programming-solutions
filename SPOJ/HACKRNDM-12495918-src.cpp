#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,k;
int arr[3000004];
int sol;
int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	sort(arr, arr+n);
	for(int i = 0; i < n; i++)
	{
		int val = lower_bound(arr, arr+n, abs(arr[i]-k))-arr;
		if(val < n && arr[i]-arr[val] == k)
			sol++;
	}
	printf("%d\n", sol);
	
	return 0;
}

