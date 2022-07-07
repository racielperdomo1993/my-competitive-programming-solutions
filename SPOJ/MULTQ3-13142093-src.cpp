#include <set>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
#define mp make_pair
#define pb push_back
#define MAXN 1000000

int N,q,op,a,b;
int tree[MAXN][3], prop[MAXN];

void create(int n, int izq, int der)
{
    if(izq>der)return;
    if(izq==der)
    {
        tree[n][0] = 1;
        prop[n] = 0;
        return;
    }
    prop[n] = 0;
    int m = (izq+der)/2;
    create(2*n,izq,m);
    create(2*n+1,m+1,der);
    tree[n][0] = tree[2*n][0]+tree[2*n+1][0];
    tree[n][1] = tree[2*n][1]+tree[2*n+1][1];
    tree[n][2] = tree[2*n][2]+tree[2*n+1][2];
    return;
}

void lazy(int n)
{
    if(prop[n])
    {
        int ceros = tree[2*n][0];
        int ceros1 = tree[2*n+1][0];
        int unos = tree[2*n][1];
        int unos1 = tree[2*n+1][1];
        int dos = tree[2*n][2];
        int dos1 = tree[2*n+1][2];
        if(prop[n]==1)
        {
            tree[2*n][0] = dos;
            tree[2*n+1][0] = dos1;
            tree[2*n][1] = ceros;
            tree[2*n+1][1] = ceros1;
            tree[2*n][2] = unos;
            tree[2*n+1][2] = unos1;
        }else if(prop[n]==2)
        {
            tree[2*n][0] = unos;
            tree[2*n+1][0] = unos1;
            tree[2*n][1] = dos;
            tree[2*n+1][1] = dos1;
            tree[2*n][2] = ceros;
            tree[2*n+1][2] = ceros1;
        }
        prop[2*n]+=prop[n];
        prop[2*n]%=3;
        prop[2*n+1]+=prop[n];
        prop[2*n+1]%=3;
        prop[n] = 0;
    }
}
void update(int n, int izq, int der)
{
    if(izq>b||der<a) return;
    if(a<=izq&&der<=b)
    {
        int ceros = tree[n][0];
        int unos = tree[n][1];
        int dos = tree[n][2];
        tree[n][0] = dos;
        tree[n][1] = ceros;
        tree[n][2] = unos;
        prop[n]++;
        prop[n]%=3;
        return;
    }
    int m = (izq+der)/2;
    lazy(n);
    update(2*n,izq,m);
    update(2*n+1,m+1,der);
    tree[n][0] = tree[2*n][0]+tree[2*n+1][0];
    tree[n][1] = tree[2*n][1]+tree[2*n+1][1];
    tree[n][2] = tree[2*n][2]+tree[2*n+1][2];
    return;
}
int query(int n, int izq, int der)
{
    if(izq>b || der < a)return 0;
    if(a<=izq&&der<=b)
    {
        return tree[n][0];
    }
    int m = (izq+der)/2;
    lazy(n);
    return query(2*n,izq,m)+query(2*n+1,m+1,der);
}
int main()
{
    scanf("%d%d",&N,&q);
    create(1,0,N-1);
    while(q--)
    {
        scanf("%d",&op);
        if(op==0)
        {
            scanf("%d%d",&a,&b); if(a>b)swap(a,b);
            update(1,0,N-1);
        }else{
            scanf("%d%d",&a,&b); if(a>b)swap(a,b);
            printf("%d\n", query(1,0,N-1));
        }
    }
    return 0;
}
