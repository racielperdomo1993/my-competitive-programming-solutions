#include <bits/stdc++.h>
#define sz(n) n.size()
#define SD(n) scanf("%d", &n)
#define SS(n) scanf("%s", n)
#define SDD(n,m) scanf("%d%d", &n,&m)
#define FOR(i, n) for(int i = 0; i < n; i++)
#define FAB(i, a,b) for(int i = a; i < b; i++)
#define mp make_pair
#define pb push_back
#define zero(n) memset(n, 0, sizeof(n))
#define mone(n) memset(n, -1, sizeof(n))
using namespace std;
#define endl '\n'
typedef long long ll;
typedef vector<int> vi;

namespace dominator{
    int const maxn=110000;
    struct bian{
        int next,point;
    }b[maxn*10];
    //x[i] pos i del nodo
    //idom[i] dominator del nodo i
    //go arbol de dominator
    int dfs[maxn],x[maxn],n,p[maxn],m,len,pre[maxn];
    int idom[maxn],best[maxn],semi[maxn],f[maxn];
    vector<int>go[maxn];
    void init(int N){//iniciar grafo, antes de adicionar aristas
        n=N;mone(p);len=-1;
    }
    void ade(int k1,int k2){
        b[++len]=(bian){p[k1],k2}; p[k1]=len;
    }
    void add(int k1,int k2){//adicionar arista (k1,k2)
        ade(k1,k2); ade(k2,k1);
    }
    void solve(int k){
        dfs[k]=++len; x[len]=k;
        for (int i=p[k];i!=-1;i=b[i].next){
            int j=b[i].point; if (i&1) continue;
            if (dfs[j]==0) {solve(j); pre[dfs[j]]=dfs[k];}
        }
    }
    int get(int k){
        if (k==f[k]) return k;
        int k1=get(f[k]);
        if (semi[best[k]]>semi[best[f[k]]]) best[k]=best[f[k]];
        f[k]=k1; return f[k];
    }
    int size[maxn];//cantidad de nodos en el subarbol
    void findans(int k){//calcular el size
        size[k]=1;
        for (int i=0;i<go[k].size();i++){
            int j=go[k][i]; findans(j);
            size[k]+=size[j];
        }
    }
    void tarjan(){
        for (int now=len;now>=2;now--){
            int k1=x[now];
            for (int i=p[k1];i!=-1;i=b[i].next){
                if ((i&1)==0) continue;
                int j=dfs[b[i].point];
                if (j==0) continue; get(j);
                if (semi[best[j]]<semi[now]) semi[now]=semi[best[j]];
            }
            go[semi[now]].push_back(now);
            int k2=pre[now]; f[now]=pre[now];
            for (int i=0;i<go[k2].size();i++){
                int j=go[k2][i];
                get(j);
                if (semi[best[j]]<k2) idom[j]=best[j]; else idom[j]=k2;
            }
            go[k2].clear();
        }
        for (int i=2;i<=len;i++){
            if (semi[i]!=idom[i]) idom[i]=idom[idom[i]];
            go[idom[i]].push_back(i);
        }
    }
    void create_tree(int no){//hace todo
        zero(dfs);zero(x);zero(pre);zero(idom);
        for (int i=1;i<=n;i++){
            f[i]=i; best[i]=i; semi[i]=i;
        }
        FOR(i,n+1)go[i].clear();
        len=0;solve(no);tarjan();//findans(1);
    }
}

int n,m,a,b;
vector<int>sol;

int main()
{
    FOR(zz, 10)
    {
        SDD(n,m);
        dominator::init(n);
        zero(dominator::size);
        FOR(i, m)
        {
            SDD(a,b);
            dominator::add(a,b);
        }
        dominator::create_tree(1);
        dominator::findans(1);
        for(int i = 1; i <= n; i++)
        {
            if(dominator::size[i]>1)
            {
                sol.pb(dominator::x[i]);
            }
        }
        sort(sol.begin(),sol.end());
        int len = sol.size();
        printf("%d\n", len);
        FOR(i, len)
        {
            if(!i)
            {
                printf("%d",sol[i]);
            }else{
                printf(" %d", sol[i]);
            }
        }
        printf("\n");
        sol.clear();
    }


    return 0;
}


