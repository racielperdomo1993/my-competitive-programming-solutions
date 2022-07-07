#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[36][1<<4];
bool marca[36][1<<4];

ll F(int col, int mask)
{
    if(col==35)
    {
        return !mask;
    }
    if(marca[col][mask]) return dp[col][mask];
    marca[col][mask] = true;
    ll sol = 0;
    for(int current = 0; current < (1<<4); current++)
    {
        if(current & (current>>1) || (current & mask) || ((current>>1)&mask) || (current & 1)) continue;
        int nextmask = current | (current>>1) | mask;
        nextmask^=((1<<4)-1);
        sol += F(col+1,nextmask);
    }
    return dp[col][mask] = sol;
}
int main()
{
    int t;
    int n;
    F(1,0);
    scanf("%d", &t);
    for(int c = 1; c<=t; c++)
    {
        scanf("%d", &n);
        printf("%d %lld\n", c, dp[35-n][0]);
    }

    return 0;
}
