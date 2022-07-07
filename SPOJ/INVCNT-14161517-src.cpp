#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll BIT[1000000];
int t,n,tam;
int arr[1000000], arr2[1000000];
ll read(int idx)
{
    ll r = 0LL;
    while(idx>0)
    {
        r+=BIT[idx];
        idx -= (idx & -idx);
    }
    return r;
}

void update(int idx, int val)
{
    while(idx<=tam)
    {
        BIT[idx]+=(ll)val;
        idx += (idx & -idx);
    }
}


int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        memcpy(arr2,arr, sizeof(arr));
        sort(arr2,arr2+n);
        tam = unique(arr2, arr2+n)-arr2;
        ll sol = 0;

        for(int i = n-1; i >= 0; i--)
        {
            int val = lower_bound(arr2,arr2+tam, arr[i])-arr2;
            val++;
            update(val, +1);
            sol+=read(val-1);
        }
        printf("%lld\n", sol);
        for(int i = 0; i < 1000000; i++)
        {
            BIT[i] = 0LL;
        }
    }

	return 0;
}
