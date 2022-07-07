using namespace std;
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <climits>
#include <cstring>
#include <map>
#include <vector>
#include <complex>
#include <list>
#include <cctype>
#include <queue>
#include <stack>
typedef long long ll;
typedef unsigned long long ull;

int  main()
{
    int t,n,a,d;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&a,&d);
        int val = a;
        int sol = a;
        for(int i = 1; i < n; i++)
        {
            val+=d;
            sol+=val;
        }
        printf("%d\n", sol);
    }
    return 0;
}
