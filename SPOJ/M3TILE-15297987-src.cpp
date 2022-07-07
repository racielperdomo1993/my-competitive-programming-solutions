#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
#define ll long long

int dp[50][1<<3];
bool marca[50][1<<3];
int C;

int solve(int col, int mask)
{
    if(col==31)
    {
        return !mask;
    }
    if(marca[col][mask]) return dp[col][mask];
    marca[col][mask] = true;
    int sol = 0;
    for(int current = 0; current < (1<<3); current++)
    {
        if((current & (current>>1)) || (current & 1) || (current & mask) || ((mask&(current>>1)))) continue;
        int next_mask = current | (current>>1) | mask;
        next_mask ^= ((1<<3)-1);
        sol += solve(col+1, next_mask);
    }
    return dp[col][mask] = sol;
}
int t;
int main()
{
    solve(1,0);
    while(true)
    {
        scanf("%d", &C);
        if(C==-1)break;
        if(C==0)printf("1\n");
        else printf("%d\n", dp[31-C][0]);
    }
    return 0;
}
