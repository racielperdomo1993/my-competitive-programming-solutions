#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;
#define ll long long
#define ull unsigned long long
#define MP make_pair

#define MAXN 100005

int t, N,a,b,c;
char cad[100];
int arr[MAXN];
vector<int> ady2[MAXN];
int level[MAXN], size[MAXN], heavy[MAXN], father[MAXN], CAD[MAXN], START[MAXN], POS[MAXN], len[MAXN];
int tree[300][MAXN], x, y;
int arista[MAXN];
vector<int> cadena[MAXN];
int indice,L,R,new_valor, M;

struct NODE
{
    int v;
    int costo;
    int id;
    NODE(){}
    NODE(int v, int costo, int id): v(v), costo(costo), id(id){}
};

vector<NODE> ady[MAXN];

void dfs(int u, int p = -1)
{
    father[u] = p;
    level[u] = 1;
    if(p!=-1)level[u]+=level[p];
    heavy[u] = -1;
    size[u] = 1;
    for(int i = ady[u].size()-1; i >= 0; i--)
    {
        NODE v = ady[u][i];
        if(v.v == p)continue;
        arista[v.id] = v.v;
        arr[v.v] = v.costo;
        dfs(v.v,u);
        size[u]+=size[v.v];
        if(heavy[u]==-1 || size[v.v]>size[heavy[u]])
        {
            heavy[u] = v.v;
        }
    }
}

void create(int n, int izq, int der)
{
    if(izq>der)return;
    if(izq==der)
    {
        tree[indice][n] = arr[cadena[indice][izq-1]];
        return;
    }
    int m = (izq+der)/2;
    create(2*n, izq, m);
    create(2*n+1, m+1, der);
    tree[indice][n] = max(tree[indice][2*n], tree[indice][2*n+1]);
}

void update(int n, int izq, int der)
{
    if(izq>der) return;
    if(izq>R || der < L) return;
    if(L<=izq&&der<=R)
    {
        tree[indice][n] = new_valor;
        return;
    }
    int m = (izq+der)/2;
    update(2*n, izq,m);
    update(2*n+1, m+1,der);
    tree[indice][n] = max(tree[indice][2*n], tree[indice][2*n+1]);
}

int query(int n, int izq, int der)
{
    if(izq>der) return 0;
    if(izq>R || der < L) return 0;
    if(L<=izq && der <= R)
    {
        return tree[indice][n];
    }
    int m = (izq+der)/2;
    int r = max(query(2*n, izq,m), query(2*n+1, m+1, der));
    return r;
}

int solve(int a, int b)
{
    int r = 0;
    while(CAD[a]!=CAD[b])
    {
        if(level[START[CAD[a]]] < level[START[CAD[b]]]) swap(a,b);
        int p = START[CAD[a]];
        indice = CAD[a];
        L = POS[p];
        R = POS[a];
        r = max(r, query(1,1,len[indice]));
        //buscar minimo intervalo p - a
        a = father[p];
    }
    if(POS[a]>POS[b]) swap(a,b);
    L = POS[a]+1;
    R = POS[b];
    indice = CAD[a];
    //buscar minimo intervalo a+1 - b
    r = max(r, query(1,1,len[indice]));
    return r;
}
void HDL(int u, int p = -1)
{
    CAD[u] = M;
    cadena[M].push_back(u);
    POS[u] = ++len[M];
    if(heavy[u]!=-1)
    {
        HDL(heavy[u], u);
    }
    for(int i = ady[u].size()-1; i >= 0; i--)
    {
        NODE v = ady[u][i];
        if(v.v == p || v.v == heavy[u]) continue;
        M++;
        START[M] = v.v;
        len[M] = 0;
        HDL(v.v, u);
    }
}

int main()
{
    scanf("%d", &t);
    int casos = 1;
    int aux = t;
    while(t--)
    {
        scanf("%d", &N);
        cadena[0].clear();
        for(int i = 1; i <= N; i++)
        {
            level[i] = 0;
            size[i] = 0;
            ady[i].clear();
            arr[i] = 0;
            cadena[i].clear();
        }
        for(int i = 1; i < N; i++)
        {
            scanf("%d%d%d",&a,&b,&c);
            if(a>b)swap(a,b);
            ady[a].push_back(NODE(b, c, i));
            ady[b].push_back(NODE(a,c,i));
        }
        int ROOT = 1;
        M = len[0] = 0;
        START[M] = 1;
        dfs(ROOT);
        HDL(ROOT);
        for(int i = 0; i <= M; i++)
        {
            indice = i;
            create(1, 1, len[i]);
        }
        /*for(int i = 0; i <= M; i++)
        {
            cout << "Cadena "<<i << endl;
            for(int j = len[i]-1; j >= 0; j--)
            {
                cout << cadena[i][j] << " ";
            }cout << endl;
        }*/
        while(true)
        {
            scanf("%s", cad);
            if(cad[0]=='D') break;
            if(cad[0]=='Q')
            {
                scanf("%d%d", &x, &y);
                printf("%d\n", solve(x, y));
            }else{
                scanf("%d%d", &x, &y);
                int nodo = arista[x];
                indice = CAD[nodo];
                L = POS[nodo];
                R = L;
                new_valor = y;
                update(1,1,len[indice]);
            }
        }
        if(casos<aux){
            printf("\n");
        }
        casos++;

    }
    return 0;
}
/*
1 2
1 3
2 4
2 5
3 6
4 11
5 10
5 9
6 7
6 8
11 13
11 12
13 14
*/
