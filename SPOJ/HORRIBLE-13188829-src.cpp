#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define MAXN 100005
int op, l, r,N,q;
ll v;

ll bit1[MAXN], bit2[MAXN];

ll query(ll bit[], int idx)
{
    ll r = 0;
    while(idx>0)
    {
        r+=bit[idx];
        idx-=idx&-idx;
    }
    return r;
}

void update(ll bit[], int idx, ll v)
{
    while(idx<MAXN)
    {
        bit[idx] +=v;
        idx+=(idx&-idx);
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(bit1,0,sizeof(bit1));
        memset(bit2,0,sizeof(bit2));
        scanf("%d%d", &N,&q);
        while(q--)
        {
            scanf("%d",&op);
            if(op==0)
            {
                scanf("%d%d%lld",&l,&r,&v);
                update(bit1, l, v);
                update(bit1, r+1,-v);
                update(bit2, l, -(v*(l-1)));
                update(bit2, r+1, (v*r));
            }else{
                scanf("%d%d",&l,&r);
                printf("%lld\n", (query(bit1, r)*r + query(bit2, r) - (query(bit1,l-1)*(l-1)+ query(bit2, l-1))));
            }
        }
    }
    return 0;
}
