#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <memory.h>
#include <queue>
#include <set>
#include <map>
#include <complex.h>
#include <string.h>
#include <stack>
#include <limits.h>

using namespace std;
#define fo(i,n) for(int i=0;i<n;i++)
#define fa(i,x,n) for(int i=x;i<n;i++)
#define X first
#define Y second
#define ll long long
#define pb push_back
#define zero(x) memset(x,0,sizeof(x))
#define mone(x) memset(x,-1,sizeof(x))
#define sz(x) x.size()
#define mos(x) cout<<#x<<" = "<<x<<endl
#define MAX 5005
#define mod 1000000007
#define base 107
#define endl '\n'

const ll oo = INT_MAX;
const double err = 1e-10;
const double PI = acos(0)*2.;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

//inicializacion: c=cc=1, limpiar ady, use, dfn, low, C
//cc-1 cantidad de componentes
//C[i] componente en la q esta el nodo i
int dfn[MAX],low[MAX],C[MAX],cc,x,c;
bool use[MAX];
vector<int> ady[MAX];
stack<int> S;
void init(){
    fo(i,MAX){
        ady[i].clear();
        use[i]=low[i]=C[i]=dfn[i]=0;
    }
    cc=c=1;
}
void dfs(int node){
    use[node]=true;
    dfn[node]=low[node]=c++;
    S.push(node);
    for(int i=0; i<ady[node].size(); i++)
        if(!use[ady[node][i]]){
            dfs(ady[node][i]);
            low[node] = min(low[node],low[ady[node][i]]);
        }
        else  if(C[ady[node][i]]==0)
            low[node] = min(low[node],low[ady[node][i]]);
    if(low[node]==dfn[node]){
        while(!C[node]){
            x = S.top();
            S.pop();
            C[x]=cc;
        }
        cc++;
    }
}
int n,m,sol[5005],con;
bool hij[MAX];
int main(){
    while(scanf("%d",&n),n){
        scanf("%d",&m);
        init();zero(hij);
        fo(i,m){
            int u,v;
            scanf("%d%d",&u,&v);
            ady[u].pb(v);
        }
        fo(i,n)if(!use[i+1])dfs(i+1);
        //fo(i,n)cout<<i+1<<" "<<C[i+1]<<endl;
        for(int i=1;i<=n;i++){
            if(!hij[C[i]]){
                fo(j,sz(ady[i]))if(C[i]!=C[ady[i][j]]){
                    hij[C[i]]=1;
                    break;
                }
            }
        }
        con=0;
        for(int i=1;i<=n;i++){
            if(!hij[C[i]]){
                sol[con++]=i;
            }
        }
        if(con){
            sort(sol,sol+con);
            fo(i,con)printf("%s%d",i?" ":"",sol[i]);
        }
        printf("\n");
    }
    return 0;
}
