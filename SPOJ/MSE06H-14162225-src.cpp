#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pi;

int BIT[10004];
int read(int idx)
{
    int r = 0;
    while(idx>0)
    {
        r+=BIT[idx];
        idx -= (idx & -idx);
    }
    return r;
}

void update(int idx, int val)
{
    while(idx <= 1000)
    {
        BIT[idx]+=val;
        idx += (idx & -idx);
    }
}


struct NODE{
    int x;
    int y;
    NODE(){}
    NODE(int x, int y): x(x), y(y){}
} arr[2000000];

bool operator<(const NODE &a, const NODE &b)
{
    if(a.x==b.x)
    {
        return a.y>b.y;
    }
    return a.x>b.x;
}
int main() {
    int c,n,m,k;
	char ch;
	int val,val2;
    scanf("%d",&c);
    for(int t=1;t<=c; t++){
        scanf("%d%d%d",&n,&m,&k);
        for(int i = 0,a,b; i < k; i++)
        {
            scanf("%d%d", &a, &b);
            arr[i] = NODE(a,b);
        }
        sort(arr,arr+k);
        ll sol = 0LL;
        for(int i = 0; i < k; i++)
        {
            sol+=read(arr[i].y-1);
            update(arr[i].y, +1);
        }
        printf("Test case %d: %lld\n", t,sol);
        memset(BIT,0,sizeof(BIT));
    }
	return 0;
}
