#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll BIT[2000][2000];


void update(int idx, int y, ll val)
{
    while(idx< 2000)
    {
        int idy = y;
        while(idy < 2000)
        {
            BIT[idx][idy] += val;
            idy += (idy&-idy);
        }
        idx += (idx&-idx);
    }
}

ll read(int idx, int y)
{
    ll r = 0LL;
    while(idx>0)
    {
        int idy = y;
        while(idy > 0)
        {
            r+=BIT[idx][idy];
            idy-=(idy&-idy);
        }
        idx-=(idx&-idx);
    }
    return r;
}

int x,y,v,x2,y2;
int t,n;
char op[5];

int main()
{
    scanf("%d", &t);
    while(t--)
    {
        memset(BIT,0,sizeof(BIT));
        scanf("%d", &n);
        while(true)
        {
            scanf("%s", op);
            if(op[1]=='E')
            {
                scanf("%d%d%d", &x, &y, &v);
                x++,y++;
                ll OLD = read(x,y) + read(x-1, y-1) - read(x,y-1) - read(x-1, y);
                update(x,y,v-OLD);
            }else if(op[1]=='U')
            {
                scanf("%d%d%d%d", &x, &y, &x2,&y2);
                x++,y++,x2++,y2++;
                ll sol = read(x2,y2)+read(x-1,y-1)-read(x-1,y2)-read(x2, y-1);
                printf("%lld\n", sol);
            }else{
                break;
            }
        }
    }

    return 0;
}

