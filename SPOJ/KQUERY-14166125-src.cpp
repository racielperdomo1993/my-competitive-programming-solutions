#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000000

int BIT[MAXN];

int read(int idx)
{
    int r = 0;
    while(idx>0){
        r+=BIT[idx];
        idx-=(idx&-idx);
    }
    return r;
}

void update(int idx)
{
    while(idx < MAXN)
    {
        BIT[idx]+=1;
        idx+=(idx&-idx);
    }
}

int n,q;
struct NODE
{
    int val;
    int pos;
};

bool fun(const NODE &a, const NODE &b)
{
    return a.val > b.val;
}

struct query{
    int a;
    int b;
    int k;
    int pos;
};

bool fun2(const query &x, const query &y)
{
    return x.k > y.k;
}

int sol[MAXN];
NODE arr[MAXN];
query Q[MAXN];
int main()
{
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i].val);
        arr[i].pos = i+1;
    }
    sort(arr, arr+n, fun);

    scanf("%d", &q);
    for(int i = 0; i < q; i++)
    {
        scanf("%d%d%d", &Q[i].a, &Q[i].b, &Q[i].k);
        Q[i].pos= i;
    }
    sort(Q, Q+q, fun2);
    int pt = 0;
    for(int i = 0; i < q; i++)
    {
        while(pt<n && arr[pt].val > Q[i].k)
        {
            update(arr[pt].pos);
            pt++;
        }
        sol[Q[i].pos] = read(Q[i].b) - read(Q[i].a-1);
    }
    for(int i = 0; i < q; i++)
    {
        printf("%d\n", sol[i]);
    }
    return 0;
}

