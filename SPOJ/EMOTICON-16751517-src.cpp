#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <string.h>
#include <stack>
#include <map>
using namespace std;
#define ll long long

#define MAXN 2002
int numero = 1;
map<char,int> mapa;
int Convertir(char x){
        if (!mapa[x])
                return mapa[x] = numero++;
        return mapa[x];
}


#define F(x,y) T[x].next[y]
const int alfa = 130;
struct Aho_Corasick{
        struct PMA {
                int suf,next[alfa],accept;
                PMA() {accept=-1;
                memset(next,0,sizeof(next));suf = 0;}
        };
        int root,size,father[MAXN],Q[MAXN];
        vector<PMA> T;
        Aho_Corasick(){
                T.push_back(PMA());
                T.push_back(PMA());
                root = size = 1;
        }
        void Add(char *p,int id){
                int t = root,i = -1;
                while( p[++i]){
                        int c = Convertir(p[i]);
                        if (F(t,c) == 0 )
                                F(t,c) = ++size, T.push_back(PMA());
                        t = F(t,c);
                }
                if(T[t].accept != -1 )
                        father[id] = T[t].accept;
                else
                        T[t].accept = father[id] = id;
        }
        void buildPMA() {
                T.push_back(PMA());
                int izq= 0,der= 0,c= 0;
                while(++c<alfa)
                        if (F(root,c)) {
                                F( F(root,c) ,0) = root;
                                Q[der++] = F(root,c);
                        } else
                                F(root,c) = root;

                while (izq < der){
                        int t = Q[izq++];
                        for ( c = 1 ; c < alfa ; ++c)
                                if (F(t,c)) {
                                        Q[der++] = F(t,c);
                                        int r = F(t,0);
                                        while (!F(r,c)) r =F(r,0);
                                        F(F(t,c),0)= F(r,c);
                                        if (T[F(F(t,c),0)].accept != -1)
                                                T[F(t,c)].suf =F(F(t,c),0);
                                        else
                                                T[F(t,c)].suf =T[F(F(t,c),0)].suf;
                                }
                }
        }
        int match(char *S) {
                int v = root,i = -1, cant = 0;
                while (S[++i]){
                        int c = Convertir(S[i]);
                        while (!F(v,c)) v = F(v,0);
                        v = F(v,c);
                        if(T[v].accept != - 1){
                                v = root, cant++;
                                continue;
                        }
                        for (int u= T[v].suf; u; u= T[u].suf){
                                v = root, cant++;
                                break;
                        }
                }
                return cant;
        }
};
char cad[100];
int main(){
        int n,m,i,sol;
        while(scanf("%d%d",&n,&m), n || m){
                getchar();
                numero = 1; mapa.clear();
                Aho_Corasick ac;
                for(i=0;i<n;i++){
                        gets(cad);
                        ac.Add(cad,i+1);
                }
                ac.buildPMA();
                sol = 0;
                while(m--){
                        gets(cad);
                        sol += ac.match(cad);
                }
                ac.T.clear();
                printf("%d\n",sol);
        }

        return 0;
}