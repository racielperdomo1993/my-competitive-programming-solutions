#include <bits/stdc++.h>
using namespace std;
#define MAXN 2000005
typedef long long ll;
typedef pair<int,int> Pi;
ll val;
char T[MAXN],P[MAXN];
ll pi[MAXN];

void PreKMP(char *P, int n)
{
    int q,k=0; pi[1] = 0;
    for(q=2;q<=n; pi[q++] = k)
    {
        while(k && (P[k]!=P[q-1]))
            k = pi[k];
        if(P[k]==P[q-1]) k++;
    }
}

int main()
{
    while(true)
    {
        cin >> val >> P;
        int len = strlen(P);
        if(P[0]=='*')
            break;
        PreKMP(P, len);
        ll aux = len-pi[len];
        ll sol = (1 + (val-len)/aux);
        if(val < len)
            cout << 0 << endl;
        else cout << sol <<endl;
    }
    return 0;
}
