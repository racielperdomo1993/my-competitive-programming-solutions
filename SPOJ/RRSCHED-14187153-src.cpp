#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;

int BIT[1000000];
int N;
pi arr[1000000];
ll sol[1000000];
int read(int idx)
{
    int r = 0;
    while(idx>0)
    {
        r+=BIT[idx];
        idx-=(idx&-idx);
    }
    return r;
}

void update(int idx, int val)
{
    while(idx <= N)
    {
        BIT[idx]+=val;
        idx+=(idx&-idx);
    }
}



int main()
{
    scanf("%d", &N);
    arr[0].first = 0;
    arr[0].second = 0;
    for(int i = 1; i <= N; i++)
    {
        update(i, 1);
        scanf("%d",&arr[i].first);
        arr[i].second = i;
    }
    sort(arr+1,arr+1+N);
    ll tiempo = 0;
    for(int i = 1; i <= N; i++)
    {
        tiempo += (ll)(arr[i].first - arr[i-1].first - 1)*(ll)(N-i+1);
        tiempo += (ll)read(arr[i].second);
        sol[arr[i].second] = tiempo;
        update(arr[i].second, -1);
        tiempo += (ll)(N-i) - (ll)read(arr[i].second);
    }
    for(int i = 1; i <= N; i++)
    {
        printf("%lld\n", sol[i]);
    }

    return 0;
}
