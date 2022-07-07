#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <string>
#include <climits>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;


ll phi(ll n){
	ll aux=n;
	ll num=1, den=1;
	for (ll i = 2; i*i <=n ; i++){
		if(n%i==0){
			num*=(i-1);
			den*=i;
			while(n%i==0)
				n/=i;
		}
	}
	if(n>1){
		num*=(n-1);
		den*=n;
	}
	if(num%den==0)return ((num/den)*aux);
	return (num*(aux/den));
}

int t;
ll n;
int main()
{
    scanf("%d", &t);
    while(t--)
    {
        scanf("%lld", &n);
        printf("%lld\n", phi(n));
    }

    return 0;
}
