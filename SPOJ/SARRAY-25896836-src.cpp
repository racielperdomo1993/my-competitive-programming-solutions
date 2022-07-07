#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

namespace SA
{
#define XX w[ok]
#define YY w[!ok]
#define FOR(i,n) for(int i = 0; i<n;i++)
#define FAB(i,a,b) for(int i = a; i<b;i++)
#define FORR(i, n) for(int i = n; i >= 0; i--)
const int MAXN = 1e5+5;
int SA[MAXN],cnt[MAXN+1], w[3][MAXN];
int N,i,pot,p,k,ok, range;

void radix_pass(int *a,bool s)
{
    memset(cnt,0, range * 4);
    FOR(i,N) cnt[ a[i] ]++;
    FAB(i,1,range) cnt[i] += cnt[ i-1 ];
    FORR(i,N-1) SA[ --cnt[a[i]]]= s? YY[i]:i;
}
void Sufix_Array(char *cad)
{
    N = strlen(cad)+1, ok=0, range = 256;
    for(i=0; i<N; i++) XX[i] = cad[i];
    radix_pass(XX,0);
    for(int pot=p=1; p<N; pot *=2, range=p)
    {
        for(p=0,i=N-pot; i<N; YY[p++]= i++) ;
        for(i=0; i<N; i++) if (SA[i] >= pot)
                YY[p++]= SA[i]-pot;
        for(i=0; i<N; i++) w[2][i]= XX[YY[i]];
        radix_pass(w[2],1);
        ok ^= p=1, XX[SA[0]] = 0;
        for(i=1; i<N; XX[SA[i++]]=k? p-1: p++)
            if(k=0, YY[SA[i]] == YY[SA[i-1]])
                if(YY[SA[i]+pot] == YY[SA[i-1]+pot])
                    k = 1;
    }
}
};
char cad[SA::MAXN];
int main()
{
    scanf("%s", cad);
    SA::Sufix_Array(cad);
    int len = strlen(cad);
    for(int i = 1; i <= len; i++){
        printf("%d\n", SA::SA[i]);
    }
	return 0;

}
