using namespace std;
#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldouble;
typedef unsigned long long ull;
typedef pair<ll,ll> pi;
//code
#define MAXN 500005
int m;
pi arr[MAXN];
pi pila[MAXN];

ll M[MAXN],C[MAXN];
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
    while(puntero < top - 1 && F(x,puntero+1) < F(x,puntero))
        puntero++;
    return F(x,puntero);
}

int main()
{
    int start = 1;
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr,arr+m);
    int N = 0;
    for (int i = 0; i < m; i++) {
		while (N > 0 && pila[N - 1].second <= arr[i].second)
			N--;
		pila[N++] = arr[i];
	}

    ll sol = 1e9;
    add(pila[0].second, 0);
    for(int i = 0; i < N; i++)
    {
        sol = query(pila[i].first);
        if(i<N)
        {
            add(pila[i+1].second, sol);
        }
    }
    cout << sol <<endl;
	return 0;
}





