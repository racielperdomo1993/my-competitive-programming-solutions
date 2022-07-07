/*
    By Raikiri
*/
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define ll long long
#define pb push_back
#define mp make_pair
#define zero(x) memset(x,0,sizeof(x))
#define mone(x) memset(x,-1,sizeof(x))
#define sz(x) x.size()
#define mos(x) cout<<#x<<" = "<<x<<endl
#define MAXN 50005
#define MOD 1000000007
#define base 107
#define endl '\n'
#define FOR(i,n) for(int i = 0; i < n; i++)
#define FAB(i,a,b) for(int i = a; i < b; i++)
#define FORR(i,n) for(int i = n; i >= 0; i--)
const ll oo = INT_MAX;
const double err = 1e-10;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

namespace hk{
    const int M=2*50005;
    const int nil=0;
    const int oo=(1<<28);
    vector< int > G[M];
    int n, m, mm[M], d[M];
    // n: number of nodes on left side, nodes are numbered 1 to n
    // m: number of nodes on right side, nodes are numbered n+1 to n+m
    // G = nil[0] ? G1[G[1---n]] ? G2[G[n+1---n+m]]
    void init(){
        for(int i=0;i<M;i++)G[i].clear();
        zero(mm);zero(d);
    }
    bool bfs() {
        int i, u, v, len;
        queue< int > Q;
        for(i=1; i<=n; i++)
            if(mm[i]==nil) {
                d[i] = 0;
                Q.push(i);
            }
            else d[i] = oo;
        d[nil] = oo;
        while(!Q.empty()) {
            u = Q.front(); Q.pop();
            if(u!=nil) {
                len = G[u].size();
                for(i=0; i<len; i++) {
                    v = G[u][i];
                    if(d[mm[v]]==oo) {
                        d[mm[v]] = d[u] + 1;
                        Q.push(mm[v]);
                    }
                }
            }
        }
        return (d[nil]!=oo);
    }
    bool dfs(int u) {
        int i, v, len;
        if(u!=nil) {
            len = G[u].size();
            for(i=0; i<len; i++) {
                v = G[u][i];
                if(d[mm[v]]==d[u]+1)
                    if(dfs(mm[v])) {
                        mm[v] = u;
                        mm[u] = v;
                        return true;
                    }
            }
            d[u] = oo;
            return false;
        }
        return true;
    }
    int hopcroft_karp() {
        int matching = 0, i;
        // mm[] is assumed nil for all vertex in G
        while(bfs())
            for(i=1; i<=n; i++)
                if(mm[i]==nil && dfs(i))
                    matching++;
        return matching;
    }
    void add(int a,int b){
        G[a].push_back(b);
        G[b].push_back(a);
    }
}
int N,M,Q,a,b;
int main()
{
    //en main
    int match = 0;//cantidad de matchings
    scanf("%d%d%d", &N,&M,&Q);
    while(Q--)
    {
        scanf("%d%d", &a,&b);
        hk::add(a,b+N);
    }
    hk::n = N;
    hk::m = M;
    printf("%d\n", hk::hopcroft_karp());
    return 0;
}

/*
6 7
2 4 -5 7 9 9
*/
