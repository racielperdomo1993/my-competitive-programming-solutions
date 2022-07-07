#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int BIT[1000000];
int t,n,k,tam;
int arr[1000000], arr2[1000000];
int elementos[1000000];
int read(int idx)
{
    int r = 0LL;
    while(idx>0)
    {
        r+=BIT[idx];
        idx -= (idx & -idx);
    }
    return r;
}

void update(int idx, int val)
{
    while(idx<=n)
    {
        BIT[idx]+=(ll)val;
        idx += (idx & -idx);
    }
}

int readSingle(int idx){
int sum = BIT[idx]; // sum will be decreased
if (idx > 0){ // special case
	int z = idx - (idx & -idx); // make z first
	idx--; // idx is no important any more, so instead y, you can use idx
	while (idx != z){ // at some iteration idx (y) will become z
		sum -= BIT[idx];
// substruct tree frequency which is between y and "the same path"
		idx -= (idx & -idx);
	}
}
return sum;
}

int dp[1000005];

int main()
{
    scanf("%d%d",&n,&k);
    for(int i = 1,a,b; i <= k; i++)
    {
        scanf("%d%d", &a,&b);
        dp[a]++;
        dp[b+1]--;
    }
    for(int i = 1; i <= n; i++)
    {
        dp[i]+=dp[i-1];
    }
    sort(dp+1,dp+1+n);
    int m = (1+n)/2;
    printf("%d\n", dp[m]);



	return 0;
}
