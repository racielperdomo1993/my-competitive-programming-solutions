#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
typedef long long ll;

int t;
int N, q,a,b,op;
ll tree[4*MAXN], v;
ll prop[4*MAXN];
void lazy(int n,int izq, int der)
{
    if(prop[n/2])
    {
        tree[n]+=(der-izq+1)*prop[n/2];
        prop[n]+=prop[n/2];
    }
}
void create(int n, int izq, int der)
{
    if(izq>der)return;
    if(izq==der)
    {
        tree[n] = 0;
        prop[n] = 0;
        return;
    }
    int m = (izq+der)/2;
    prop[n] = 0;
    create(2*n,izq,m);
    create(2*n+1,m+1,der);
    tree[n] = tree[2*n]+tree[2*n+1];
    return;

}
void update(int n, int izq, int der)
{
    if(izq>b||der<a) return;
    if(a<=izq&&der<=b)
    {
        tree[n]+=(der-izq+1)*v;
        prop[n]+=v;
        return;
    }
    int m = (izq+der)/2;
    lazy(2*n,izq,m);
    lazy(2*n+1,m+1,der);
    prop[n] = 0;
    update(2*n,izq,m);
    update(2*n+1,m+1,der);
    tree[n] = tree[2*n]+tree[2*n+1];
    return;
}

ll query(int n, int izq, int der)
{
    if(izq>b||der<a)return 0;
    if(a<=izq&&der<=b)
    {
        return tree[n];
    }
    int m = (izq+der)/2;
    lazy(2*n,izq,m);
    lazy(2*n+1,m+1,der);
    prop[n] = 0;
    return query(2*n,izq,m)+query(2*n+1,m+1,der);
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        memset(prop,0,sizeof(prop));
        memset(tree, 0, sizeof(tree));
        scanf("%d%d", &N,&q);
        create(1,0,N-1);
        while(q--)
        {
            scanf("%d",&op);
            if(op==0)
            {
                scanf("%d%d%lld",&a,&b,&v);
                if(a>b)swap(a,b);
                a--,b--;
                update(1,0,N-1);
            }else{
                scanf("%d%d",&a,&b); if(a>b)swap(a,b);
                a--,b--;
                printf("%lld\n", query(1,0,N-1));
            }
        }

    }

    return 0;
}
