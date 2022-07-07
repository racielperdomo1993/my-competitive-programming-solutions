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
	int t, id;
	scanf("%d", &t);
	char cad[85];
	for (int i = 1; i <= t; i++)
	{
		scanf("%d %s", &id, cad);
		printf("%d ", i);
		for(int i = 0; i < (int)strlen(cad); i++)
		{
			if(i==id-1) continue;
			else printf("%c", cad[i]);
		}
		printf("\n");
		
	}
	return 0;
}
