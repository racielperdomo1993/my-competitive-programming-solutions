using namespace std;
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <climits>
#include <cstring>
#include <map>
#include <vector>
#include <complex>
#include <list>
#include <cctype>
#include <queue>
typedef long long ll; 
typedef unsigned long long ull;

#define MAXN 1000000

bool visited[MAXN];
ll prime[MAXN/10],lp,t,n,a,b;

bool isPrime(ll k)
{
	if(k==1 || k==0)return false;
	for (int i = 0; prime[i]*prime[i] <=k ; i++)
		if(k%prime[i]==0)
			return false;
	return true;
}

int main() {
	memset(visited,true,sizeof(visited));
	lp=0;
	for (int i = 2; i*i < MAXN ; i++)
		if(visited[i])
			for(int j=i+i;j<MAXN;j+=i)
				visited[j]=false;
	for (int i = 2; i < MAXN; i++)
		if(visited[i])
			prime[lp++]=ll(i);
	
	scanf("%lld",&t);
	while (t--)
	{
		scanf("%lld%lld",&a, &b);
		for(int i = a; i <= b; i++){
			if(isPrime(i)){
				printf("%lld\n", ll(i));
			}
		}
		printf("\n");
	}
	
	return 0;
}
