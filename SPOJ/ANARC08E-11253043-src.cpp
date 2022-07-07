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
    int a,b;
    while(scanf("%d%d",&a,&b)&&(a!=-1||b!=-1))
    {
        if(a==1||b==1)
        {
            printf("%d+%d=%d\n",a,b,a+b);
        }else{
            printf("%d+%d!=%d\n",a,b,a+b);
        }

    }

    return 0;
}
