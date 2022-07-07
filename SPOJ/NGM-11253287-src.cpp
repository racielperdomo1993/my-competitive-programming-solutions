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

    char cad[50];
            scanf("%s", cad);
            int len = strlen(cad);
            if(cad[len-1] == '0') printf("%d\n", 2);
            else
                printf("%d\n%d\n", 1, cad[len-1]-48);
    return 0;
}
