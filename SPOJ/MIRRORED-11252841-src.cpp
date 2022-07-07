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
    char c,d;
    c = getchar();
    d = getchar();
    printf("Ready\n");
    while(c!=' '&&d!=' ')
    {
        getchar();
        if(c>d)swap(c,d);
        if(c=='b'&&d=='d' || c == 'p'&&d=='q')
        {
            printf("Mirrored pair\n");
        }else{
            printf("Ordinary pair\n");
        }
        c = getchar();
        d = getchar();
    }

    return 0;
}
