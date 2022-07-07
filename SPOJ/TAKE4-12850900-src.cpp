#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t,n,m;
    scanf("%d%",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        if(n%(m+1)==0)
        {
            printf("player2 wins\n");
        }else{
            printf("player1 wins\n");
        }
    }
    return 0;
}
