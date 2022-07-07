#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair<int, int> pi;
struct NODE
{
	int x;
	int y;
	NODE(){}
	NODE(int x, int y): x(x), y(y){}
};

bool operator<(const NODE &a, const NODE &b)
{
	if(a.x == b.x)
	{
		return a.y < b.y;
	}
	else 
	{
		return a.x > b.x;
	}
}
int main()
{
	int t;
	int n,a,b;
	NODE arr[100005];
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
		{
			scanf("%d%d", &a, &b);
			arr[i] = NODE(a, b);
		}
		sort(arr, arr+n);
		for(int i = n-1; i >= 0; i--)
		{
			printf("%d %d\n", arr[i].x, arr[i].y);
		}
		
	}
	
	
	return 0;
}
