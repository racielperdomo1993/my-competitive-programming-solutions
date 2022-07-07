#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 6200

int N,arr[100005],a,b,v;
int mayor1[2000000];
int mayor2[2000000];
int parcial[4];
int aux1 = 0, aux2 = 0;
priority_queue<int> cola;
void create(int n, int izq, int der)
{
    if(izq>der)return;
    if(izq==der)
    {
        mayor1[n] = arr[izq];
        mayor2[n] = 0;
        return;
    }
    int m = (izq+der)/2;
    create(2*n,izq,m);
    create(2*n+1,m+1,der);
    cola.push(mayor1[2*n]);
    cola.push(mayor2[2*n]);
    cola.push(mayor1[2*n+1]);
    cola.push(mayor2[2*n+1]);
    mayor1[n] = cola.top();
    cola.pop();
    mayor2[n] = cola.top();
    cola.pop();
    cola.pop();
    cola.pop();
    return;
}
void update(int n, int izq, int der)
{
    if(izq>b||der<a) return;
    if(a<=izq&&der<=b)
    {
        mayor1[n] = v;
        mayor2[n] = 0;
        return;
    }
    int m = (izq+der)/2;
    update(2*n,izq,m);
    update(2*n+1,m+1,der);
    cola.push(mayor1[2*n]);
    cola.push(mayor2[2*n]);
    cola.push(mayor1[2*n+1]);
    cola.push(mayor2[2*n+1]);
    int val1 = cola.top();
    cola.pop();
    int val2 = cola.top();
    cola.pop();
    cola.pop();
    cola.pop();
    mayor1[n] = val1;
    mayor2[n] = val2;
    return;
}
char ca[2];
void query(int n, int izq, int der)
{
    if(der<a || izq>b) return;
    if(a<=izq&&der<=b)
    {
        cola.push(mayor1[n]);
        cola.push(mayor2[n]);
        return;
    }
    int m = (izq+der)/2;
    query(2*n, izq,m);
    query(2*n+1,m+1,der);
    return;
}

int main()
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d",&arr[i]);
    }
    create(1,0,N-1);
    int q;
    scanf("%d",&q);
    while(q--)
    {
        while(!cola.empty())cola.pop();
        aux1 = 0;
        aux2 = 0;
        scanf("%s", ca);
        if(ca[0]=='Q')
        {
            scanf("%d%d",&a,&b);
            if(a>b)swap(a,b);
            a--,b--;
            query(1,0,N-1);
            aux1 = cola.top();
            cola.pop();
            aux2 = cola.top();
            cola.pop();
            printf("%d\n", aux1+aux2);
        }else{
            scanf("%d%d",&a,&v);
            a--;
            b=a;
            update(1,0,N-1);
        }
    }
    return 0;
}
