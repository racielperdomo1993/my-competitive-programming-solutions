#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 1000005
#define pb push_back
#define mp make_pair
int padre[MAXN], size[MAXN], nivel[MAXN], heavy[MAXN], CAD[MAXN], POS[MAXN], len[MAXN], START[MAXN];
int M;
int L,R;
vector<int> ady[MAXN];
void dfs(int u, int v = -1)
{
    padre[u] = v;
    size[u] = 1;
    nivel[u] = 1;
    heavy[u] = -1;
    if(v!=-1) nivel[u]+=nivel[v];

    for(int i = ady[u].size()-1; i >= 0; i--)
    {
        v = ady[u][i];
        if(v==heavy[u] || v == padre[u]) continue;
        dfs(v,u);
        size[u]+=size[v];
        if(heavy[u]==-1 || size[v]>size[heavy[u]])
        {
            heavy[u] = v;
        }
    }
}

void HDL(int u, int v = -1)
{
    CAD[u] = M;
    POS[u] = ++len[M];
    if(heavy[u]!=-1)
    {
        HDL(heavy[u], u);
    }
    for(int i = ady[u].size()-1; i>= 0; i--)
    {
        v = ady[u][i];
        if(v == heavy[u] || v == padre[u]) continue;
        M++;
        START[M] = v;
        len[M] = 0;
        HDL(v, u);
    }
}

struct SEGTREE
{
    vector<ll> tree;
    vector<ll> prop;
    int n;
    SEGTREE(){}
    SEGTREE(int nn) {
        n = nn;
        tree = vector<ll> (5*(n+1));
        prop = vector<ll> (5*(n+1));
    }
    void lazy(int n, int izq, int m, int der)
    {
        if(prop[n])
        {
            tree[2*n]+=(ll)(m-izq+1)*prop[n];
            prop[2*n]+=prop[n];
            m++;
            tree[2*n+1]+= (ll)(der-m+1)*prop[n];
            prop[2*n+1]+=prop[n];
            prop[n] = 0LL;
        }
    }
    void update(int n, int izq, int der)
    {
        if(izq>der)return;
        if(izq>R || der < L) return;
        if(L<=izq&&der<=R)
        {
            tree[n]+=(ll)(der-izq+1);
            prop[n]++;
            return;
        }

        int m = (izq+der)/2;
        lazy(n, izq,m,der);
        update(2*n, izq,m);
        update(2*n+1, m+1,der);
        tree[n] = tree[2*n]+tree[2*n+1];
    }

    ll query(int n, int izq, int der)
    {
        if(izq>der)return 0LL;
        if(izq>R || der < L) return 0LL;
        if(L<=izq&&der<=R)
        {
            return tree[n];
        }
        int m = (izq+der)/2;
        lazy(n, izq,m,der);
        return query(2*n,izq,m)+query(2*n+1,m+1,der);
    }


};
vector<SEGTREE> tree;

int n, m,indice;
char op[2];

void update(int a, int b)
{
    while(CAD[a]!=CAD[b])
    {
        if(nivel[START[CAD[a]]] < nivel[START[CAD[b]]])
        {
            swap(a,b);
        }
        int p = START[CAD[a]];
        indice = CAD[a];
        int cantidad = POS[a];
        L = 1;
        R = POS[a];
        tree[indice].update(1, 1, len[indice]);
        a = padre[p];
    }
    indice = CAD[a];
    if(POS[a]>POS[b])swap(a,b);
    int cantidad = POS[b]-POS[a];
    L = POS[a]+1;
    R = POS[b];
    tree[indice].update(1,1,len[indice]);
}

ll solve(int a, int b)
{
    ll r = 0;
    while(CAD[a]!=CAD[b])
    {
        if(nivel[START[CAD[a]]] < nivel[START[CAD[b]]])
        {
            swap(a,b);
        }
        int p = START[CAD[a]];
        indice = CAD[a];
        L = 1;
        R = POS[a];
        r += tree[indice].query(1,1,len[indice]);
        a = padre[p];
    }
    if(POS[a]>POS[b])swap(a,b);
    indice = CAD[a];
    int izq = POS[a]+1;
    int der = POS[b];
    L = izq;
    R = der;
    r+=tree[indice].query(1,1,len[indice]);
    return r;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 1,a,b; i < n; i++)
    {
        scanf("%d%d", &a, &b);
        ady[a].pb(b);
        ady[b].pb(a);
    }
    M = len[M] = 0;
    int ROOT = 1;
    START[M] = ROOT;
    dfs(ROOT);
    HDL(ROOT);
    for(int i = 0; i <= M; i++)
    {
        int longitud = len[i];
        tree.push_back(SEGTREE(longitud));
    }
    for(int i = 0,a,b; i < m; i++)
    {
        scanf("%s%d%d", op,&a,&b);
        if(op[0]=='P')
        {
            update(a,b);
        }else{
            printf("%lld\n", solve(a,b));
        }
    }
    return 0;
}
/*
7 100
1 2
1 3
2 4
2 5
3 6
4 7
P 1 7
P 2 7
Q 4 7
6
*/

