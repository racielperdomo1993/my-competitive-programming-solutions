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

int main()
{
	int t, n;
	string cad[100004];
	map<string,int> mapa;
	scanf("%d", &t);
	while(t--)
	{
		mapa.clear();
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			cin >> cad[i];
			mapa[cad[i]]++;
		}
		int sol = 0;
		for(int i = 0; i < n; i++)
		{
			if(mapa[cad[i]] == 1)
			{
				sol++;
			}
		}
		printf("%d\n", sol);
	}
	return 0;
}
