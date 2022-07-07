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
typedef pair<int,int> pii;

map<char,int> mapa;
#define N 505   // max cant de palabras en el alfabeto
#define MN 1000  //MAX CANT NODOS en el arbol
#define ALF 257		//tamanno del alfabeto

int term[MN], ac[MN][ALF], fail[MN], fr[MN], siz;
vector<int> order;
int numero;

int Convertir(char x){
        if (!mapa[x])
                return mapa[x] = numero++;
        return mapa[x];
}

void init() {
        for (int i = 0; i <= siz; i++) {
                memset(ac[i], 0, sizeof(ac[i]));
                term[i] = 0;
        }
        siz = 1;
}
queue<int> Q;
void build() {
        order.clear();
        fail[1] = 1;
        while(!Q.empty())Q.pop();
        for (int i = 0; i < ALF; i++)
                if (ac[1][i]) {
                        fail[ac[1][i]] = 1;
                        Q.push(ac[1][i]);
                } else
                        ac[1][i] = 1;
        while (!Q.empty()) {
                int u = Q.front();
                Q.pop();
                order.push_back(u);
                term[u] |= term[fail[u]];
                for (int i = 0; i < ALF; i++) {
                        int v = ac[u][i];
                        if (v) {
                                fail[v] = ac[fail[u]][i];
                                Q.push(v);
                        } else {
                                ac[u][i] = ac[fail[u]][i];
                        }
                }
        }
}
void insert(char *S, int id) {
        int nod = 1;
        int len = strlen(S);
        for (int i = 0; i < len; i++) {
                int c = Convertir(S[i]);
                if (!ac[nod][c])
                        ac[nod][c] = ++siz;
                nod = ac[nod][c];
        }
        term[nod] = 1;
}

int match(char *S)
{
    int len = strlen(S);
    int nodo = 1;
    int sol = 0;
    FOR(i, len)
    {
        int c = Convertir(S[i]);
        nodo = ac[nodo][c];
        if(term[nodo])
        {
            sol++;
            S[i] = ' ';
            i--;
        }
    }
    return sol;
}
int n,m;
char cad[505], text[505];
int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);
    while(true)
    {
        numero = 1;
        mapa.clear();
        SDD(n,m);
        if(!n && !m)break;
        getchar();
        init();
        FOR(i, n)
        {
            gets(cad);
            insert(cad, i);
        }
        build();
        int r = 0;
        FOR(i, m)
        {
            gets(text);
            r+=match(text);
        }
        printf("%d\n", r);
    }

    return 0;
}