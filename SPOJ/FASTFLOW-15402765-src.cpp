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
const double err = 1e-10;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int n;
const ll oo = INT_MAX;
namespace dinic{
    const int M=5005;
    vector<int> G[M]; //edges
    vector<ll> W[M]; //initial flow
    ll F[M][M];   //flow
    ll C[M][M];   //capacity
    ll A[M];
    bool B[M];
    void init(){
        FOR(i,M)G[i].clear(),W[i].clear();
    }
    void add(int a,int b,ll w){
        G[a].push_back(b);
        W[a].push_back(w);
    }
    #define R(s,t) (C[s][t]-F[s][t]) //residue
    ll augment(int u, int t, ll w){
        if (u==t || w==0) return w;
        if (B[u]) return 0;
        B[u] = 1;
        FOR(i, sz(G[u])) if (A[G[u][i]]>A[u]){
            ll f=augment(G[u][i], t, min((ll)w,(ll)R(u,G[u][i])));
            if (f>0){
                F[u][G[u][i]]+=f;
                F[G[u][i]][u]-=f;
                B[u]=0;
                return f;
            }
        }
        return 0;
    }
    ll maxFlow(int s, int t){
        int i,j,k;
        zero(F);zero(C);
        FOR(i,n)FOR(j,sz(G[i]))
            C[i][G[i][j]]+=W[i][j];
        ll r=0;
        for(int c=1; c;){
            c=0;
            mone(A);
            A[s]=0;
            queue<int> Q;
            Q.push(s);
            for(int i=n+1; !Q.empty() && A[Q.front()]<i;){
                int j=Q.front();
                Q.pop ();
                if (j==t) i=A[j];
                FOR(k,sz(G[j])) if(R(j,G[j][k])>0 && A[G[j][k]]==-1)
                    Q.push(G[j][k]), A[G[j][k]]=A[j]+1;
            }
            zero(B);
            for (ll f=1; f>0;f){
                f = augment(s, t, oo);
                if (f==0) break;
                //cout<<f<<endl;
                r += f;
                c=1;
            }
        }
        return r;
    }
}
int m;
int main()
{
    int a,b,c;
    dinic::init();
    scanf("%d%d", &n,&m);
    for(int i = 0; i < m; i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        a--,b--;
        dinic::add(a,b,c);
        dinic::add(b,a,c);
    }
    printf("%lld\n", dinic::maxFlow(0,n-1));
    return 0;
}

/*
6 7
2 4 -5 7 9 9
*/
