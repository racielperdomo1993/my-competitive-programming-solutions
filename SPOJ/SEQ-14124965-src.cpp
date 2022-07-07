#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
#define MOD 1000000000

struct M { ll m[20][20];};

int K;
M operator*(const M &a,const M &b){
	M r;
	memset(&r,0,sizeof(r));
	for (int i = 0; i < K; i++)
		for (int j = 0; j < K; j++)
			for (int k = 0; k < K; k++)
				r.m[i][j]=(r.m[i][j]+a.m[i][k]*b.m[k][j])%MOD;
	return r;
}

M bin_pot(const M &b,ll e){
	if(e==1)return b;
	if(e&1)return b*bin_pot(b,e-1);
	M m=bin_pot(b,e/2);
	return m*m;
}



M mat;
int n;
int t;
ll arr[20];
int main()
{
    cin >> t;
    while(t--)
    {
        cin>>K;
        for(int i = 0; i < K; i++)
        {
            cin >> arr[i];
        }
        for(int i = 0; i < K; i++)
        {
           cin>>mat.m[0][i];
        }
        for(int fil=1; fil < K; fil++)
        {
            for(int col = 0; col < K; col++)
            {
                if(col+1==fil)
                {
                    mat.m[fil][col] = 1;
                }else{
                    mat.m[fil][col] = 0;
                }
            }
        }
        cin >> n;
        if(n <= K)
        {
            cout << arr[n-1] << endl;
        }else{
            M aux = bin_pot(mat, n-K);
            ll sol = 0;
            for(int i = 0; i < K; i++)
            {
                sol+=aux.m[0][i]*arr[K-i-1];
                sol%=MOD;
            }
            cout << sol << endl;
        }
    }

	return 0;
}

