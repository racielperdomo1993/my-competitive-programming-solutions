using namespace std;
#include <cstdio>
#include <iostream>

typedef long long ll;
typedef long double ldouble;
typedef unsigned long long ull;
typedef pair<ll,ll> pi;
//code
#define MAXN 1000005
ll dp[MAXN];
ll M[MAXN],C[MAXN];
ll tabla[MAXN];
int top;

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
int puntero;
ll query(ll x) {
    if(puntero > top)
        puntero = top - 1;
    while(puntero < top - 1 && F(x,puntero+1) > F(x,puntero))
        puntero++;
    return F(x,puntero);
}

ll a,b,c;
int n;
int t;



int main()
{
    scanf("%d", &t);
    while(t--)
    {
        top = 0;
        puntero = 0;
        scanf("%d", &n);
        scanf("%lld %lld %lld", &a,&b,&c);
        tabla[0] = 0LL;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &tabla[i]);
            tabla[i]=tabla[i]+tabla[i-1];
        }
        dp[1] = a*tabla[1]*tabla[1] + b*tabla[1] + c;
        add(-2*a*tabla[1], dp[1]+a*tabla[1]*tabla[1] - b*tabla[1]);
        for(int i = 2; i <= n; i++)
        {
            dp[i] = a*tabla[i]*tabla[i] + b*tabla[i] + c;
            dp[i] = max(dp[i], b*tabla[i] + a*tabla[i]*tabla[i] + c + query(tabla[i]));
            add(-2*a*tabla[i], dp[i] + a*tabla[i]*tabla[i] - b*tabla[i]);
        }
        printf("%lld\n", dp[n]);
    }

	return 0;
}





