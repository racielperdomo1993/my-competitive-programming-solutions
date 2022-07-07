#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int c[1000004];
int q;
int arr[30004];
int resp[200004];
int BLOCK;
int sol;
int L,R;
struct query
{
    int L;
    int R;
    int ind;
} Q[200004];

bool fun(query a, query b)
{
    if(a.L/BLOCK != b.L/BLOCK)
    {
        return a.L/BLOCK < b.L/BLOCK;
    }
    return a.R<b.R;
}

void adicionar(int idx)
{
    c[arr[idx]]++;
    if(c[arr[idx]]==1)
    {
        sol++;
    }
}

void eliminar(int idx)
{
    c[arr[idx]]--;
    if(c[arr[idx]]==0)
    {
        sol--;
    }
}

int solve(int idx)
{
    while(L<Q[idx].L)
    {
        eliminar(L);
        L++;
    }
    while(L>Q[idx].L)
    {
        L--;
        adicionar(L);
    }
    while(R<=Q[idx].R)
    {
        adicionar(R);
        R++;
    }
    while(R>Q[idx].R+1)
    {
        eliminar(R-1);
        R--;
    }
    return sol;
}
int n,m;

int main()
{
    scanf("%d",&n);
    BLOCK = sqrt(n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    scanf("%d",&m);
    for(int i = 0, a,b; i < m; i++)
    {
        scanf("%d%d",&a,&b);
        a--,b--;
        Q[i].L = a;
        Q[i].R = b;
        Q[i].ind = i;
    }
    sort(Q,Q+m,fun);
    for(int i = 0; i < m; i++)
    {
        resp[Q[i].ind] = solve(i);
    }
    for(int i = 0; i < m; i++)
    {
        printf("%d\n", resp[i]);
    }
    return 0;
}
