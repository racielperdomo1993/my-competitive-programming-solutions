#include <bits/stdc++.h>
using namespace std;

#define MAXE 1000000
typedef unsigned long long ull;
typedef long long ll;
#define fo(i,n) for(int i=0;i<n;i++)
#define fa(i,x,n) for(int i=x;i<n;i++)
#define X first
#define Y second
#define pb push_back
#define digit(c) ((c) - '0')
#define mp make_pair
#define zero(x) memset(x,0,sizeof(x))
#define mone(x) memset(x,-1,sizeof(x))
#define sz(x) x.size()
#define mos(x) cout<<#x<<" = "<<x<<endl
#define MAX 500005
#define MOD 1000000007
//#define base 107
#define endl '\n'
#define FOR(i,n) for(int i = 0; i < n; i++)
#define FAB(i,a,b) for(int i = a; i < b; i++)
#define FORR(i,n) for(int i = n; i >= 0; i--)
#define endl '\n'
const ll oo = LONG_LONG_MAX;
const double err = 1e-10;
typedef pair<int,int> pii;
typedef pair<ull, ull> puu;

//var
ll W[MAX];
ll arr[MAX];
ll dp[20][MAX];
ll CC[MAX];

ll M[MAX],C[MAX];
int top;
int puntero;
//end var


//fun
//inicio


bool bad(int l1, int l2, int l3) {
    return (C[l3] - C[l1])*(M[l1] - M[l2]) < (C[l2] - C[l1])*(M[l1] - M[l3]);
}
void add(ll m, ll c){
    M[top] = m;
    C[top++] = c;
    while(top >= 3 && bad(top - 3, top - 2, top - 1)){
        M[top - 2] = M[top - 1];
        C[top - 2] = C[top - 1];
        top--;
    }
}

ll F(ll x, int i){
    return M[i]*x+C[i];
}

ll query(ll x) {
    if(puntero > top)
        puntero = top - 1;
    while(puntero < top - 1 && F(x,puntero+1) < F(x,puntero))
        puntero++;
    return F(x,puntero);
}
//fin
//end fun

int main()
{
    int n,K;
    scanf("%d%d", &n,&K);
    FAB(i, 1, n+1)
    {
        FAB(k, 1, K+1)
        {
            dp[k][i] = oo;
        }
    }
    FAB(i,1,n+1)
    {
        scanf("%lld", &arr[i]);
        W[i] = W[i-1]+arr[i];
        CC[i] = CC[i-1]+ arr[i]*(i-1);
    }
    FAB(i, 1, n+1)
    {
        dp[1][i] = CC[i];
    }
    for(int i = 1; i <= K; i++)
    {
        dp[i][i] = 0;
    }
    /*for(int k = 2; k <= K; k++)
    {
        for(int a = k; a <= n; a++)
        {
            for(int b = a+1; b <= n; b++)
            {
                dp[k][b] = min(dp[k][b], dp[k-1][a] +CC[b]-CC[a] - a*(W[b]-W[a]));
            }
        }
    }
    cout << dp[K][n]<<endl;
    */

    for(int k = 2; k <= K; k++)
    {
        puntero = top = 0;
        for(int b = k; b <= n; b++)
        {
            add(-(b-1), (b-1)*W[b-1] - CC[b-1] + dp[k-1][b-1]);
            dp[k][b] = min(dp[k][b], CC[b] + query(W[b]));
        }
    }
    printf("%lld\n", dp[K][n]);

    return 0;
}

