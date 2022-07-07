/*#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <climits>
#include <algorithm>
#include <string>
#include <iostream>
#include <ctime>
#include <stack>


using namespace std;
int n,m;
char cad[30], cad2[30];
#define MOD 1000003;
typedef unsigned long long ull;

#define fo(i,n) for(int i=0;i<n;i++)
#define fa(i,x,n) for(int i=x;i<n;i++)
#define X first
#define Y second
#define ll long long
#define pb push_back
#define mp make_pair
#define zero(x) memset(x,0,sizeof(x))
#define mone(x) memset(x,-1,sizeof(x))
#define sz(x) x.size()
#define mos(x) cout<<#x<<" = "<<x<<endl
#define MAX 105
#define mod 1000000007
#define base 107
#define endl '\n'
const ll oo = INT_MAX;
const double err = 1e-10;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
vector<pii> bridges;
//stack <pii> stk;
vector< vector<int> > C;
vi c;
stack<pii> stk;
vi G[MAX];
int ndfs, vdfs[MAX], low[MAX];
bool apoint[MAX];
bool used[MAX];
// puentes si y solo si vdfs[u] < low[v]
int bcc[MAX];
int cc;
int a[MAX],b[MAX];
void cache_bc(int x, int y){
    vector<int> com;
    int tx,ty;

    do{
        tx = stk.top().first, ty = stk.top().second;
        stk.pop();
        com.push_back(tx), com.push_back(ty);
    }while(tx!=x || ty!=y);
    C.push_back(com);
}
void tarjan(int u, int p = -1)
{
    int v;
    vdfs[u] = low[u] = ndfs++;
    for(int i = G[u].size()-1; i >= 0; --i)
    {
        v = G[u][i];
        if(!vdfs[v])
        {
            stk.push(mp(u,v));
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if((vdfs[u] == 1 && vdfs[v] > 2) || (vdfs[u] != 1 &&
                                                 vdfs[u] <= low[v]))
                apoint[u] = true;
            if(vdfs[u]<low[v])
            {
                //puente
                bridges.push_back(mp(u,v));
            }
            if(low[v] >= vdfs[u])
            {
                cache_bc(u,v);
            }
        }
        else if(v != p) low[u] = min(low[u], vdfs[v]);
    }
}
void BCC(int n)
{
    for(int i = 0; i < n; ++i) vdfs[i] = apoint[i] = 0;
    for(int i = 0; i < n; ++i)
        if(!vdfs[i])
        {
            ndfs = 1;
            tarjan(i);
        }
     cc = C.size();
    memset(used,false,sizeof used);
     for(int i = 0; i < cc; i++)
     {
         sort(C[i].begin(), C[i].end());
         C[i].erase(unique(C[i].begin(),C[i].end()),C[i].end());
         int m = C[i].size();
         for(int j = 0; j < m; j++)
         {
             printf("%d ", C[i][j]);
         }printf("\n");

         if(m>2)
         {
            int val = 0;
            for(int j = 0;j < m;++j){
                val += a[ C[i][j] ];
                used[ C[i][j] ] = true;
            }
            c.push_back(val);
         }
     }
     for(int i = 0;i < n;++i)
        if(!used[i])
            c.push_back(a[i]);


}
vector<int> L[MAX];
bool visited[MAX];
int ri[MAX],le[MAX];

bool hopcroft(int cur)
{
    if(visited[cur]) return false;
    visited[cur] = true;

    for(int i = L[cur].size() - 1,to;i >= 0;--i){
        to = L[cur][i];

        if(le[to] == -1 || hopcroft(le[to])){
            le[to] = cur;
            ri[cur] = to;
            return true;
        }
    }
    return false;
}
int N, M,T;
int main()
{
    scanf("%d%d%d",&N,&M,&T);
    for(int i = 0;i < N;++i)
        scanf("%d",&a[i]);
    for(int i = 0;i < T;++i)
        scanf("%d",&b[i]);
    for(int i = 0,a,b; i < M; i++)
    {
        scanf("%d%d", &a, &b);
        a--,b--;
        G[a].pb(b);
        G[b].pb(a);
    }
    BCC(N);
    return 0;
}
*/

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

#define MAXN 251

int V;
vector<int> adj[MAXN];
int dfn[MAXN],low[MAXN];
vector< vector<int> > C;
stack< pair<int, int> > stk;

void cache_bc(int x, int y){
    vector<int> com;
    int tx,ty;

    do{
        tx = stk.top().first, ty = stk.top().second;
        stk.pop();
        com.push_back(tx), com.push_back(ty);
    }while(tx!=x || ty!=y);

    C.push_back(com);
}

void DFS(int cur, int prev, int number){
    dfn[cur] = low[cur] = number;

    for(int i = adj[cur].size()-1;i>=0;--i){
        int next = adj[cur][i];
        if(next==prev) continue;
        if(dfn[next]==-1){
            stk.push(make_pair(cur,next));
            DFS(next,cur,number+1);
            low[cur] = min(low[cur], low[next]);
            if(low[next]>=dfn[cur]) cache_bc(cur,next);
        }else low[cur] = min(low[cur],dfn[next]);
    }
}

bool used[MAXN];
int a[MAXN],b[MAXN];
vector<int> c;

void biconn_comp(){
    memset(dfn,-1,sizeof(dfn));
    C.clear();

    for(int i = 0;i < V;++i)
        if(dfn[i] == -1) DFS(i,i,0);

    int comp = C.size();
    memset(used,false,sizeof used);
    c.clear();

    for(int i = 0;i < comp;++i){
        sort(C[i].begin(),C[i].end());
        C[i].erase(unique(C[i].begin(),C[i].end()),C[i].end());
        int m = C[i].size();

        if(m > 2){
            int val = 0;

            for(int j = 0;j < m;++j){
                val += a[ C[i][j] ];
                used[ C[i][j] ] = true;
            }

            c.push_back(val);
        }
    }

    for(int i = 0;i < V;++i)
        if(!used[i])
            c.push_back(a[i]);
}

vector<int> L[MAXN];
bool visited[MAXN];
int ri[MAXN],le[MAXN];

bool dfs(int cur){
    if(visited[cur]) return false;
    visited[cur] = true;

    for(int i = L[cur].size() - 1,to;i >= 0;--i){
        to = L[cur][i];

        if(le[to] == -1 || dfs(le[to])){
            le[to] = cur;
            ri[cur] = to;
            return true;
        }
    }

    return false;
}

int main(){
    int T,tc = 1,E,N;

    scanf("%d",&T);

    while(T--){
        scanf("%d %d %d",&V,&E,&N);

        for(int i = 0;i < V;++i) scanf("%d",&a[i]);
        for(int i = 0;i < N;++i) scanf("%d",&b[i]);
        for(int i = 0;i < V;++i) adj[i].clear();

        for(int i = 0,u,v;i < E;++i){
            scanf("%d %d",&u,&v);
            --u; --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        biconn_comp();

        int M = c.size();

        printf("Buzz Mission %d: %d ",tc++,M);

        if(M > N) puts("No");
        else{
            int lo = 0,hi = 1000000,mi;

            while(lo < hi){
                mi = (lo + hi) >> 1;

                for(int i = 0;i < M;++i){
                    L[i].clear();

                    for(int j = 0;j < N;++j)
                        if(abs(c[i] - b[j]) <= mi)
                            L[i].push_back(j);
                }

                int match = 0;
                bool found = true;
                memset(le,-1,sizeof le);
                memset(ri,-1,sizeof ri);

                while(found){
                    memset(visited,false,sizeof visited);
                    found = false;

                    for(int i = 0;i < M;++i)
                        if(ri[i] == -1 && dfs(i))
                            ++match, found = true;
                }

                if(match < M) lo = mi + 1;
                else hi = mi;
            }

            printf("%d\n",lo);
        }
    }

    return 0;
}

