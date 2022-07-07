#include <string>
#include <cstdio>
#include <iostream>
using namespace std;
#define MAXN 2000005
bool marca[MAXN];
int arr[MAXN];
bool dp[MAXN];
int op[10];

int main()
{
    int m;
	op[0] = 1;
	scanf("%d%d%d", &op[1],&op[2],&m);
        for(int i = 0; i < m; i++)
        {
            scanf("%d", &arr[i]);
        }
        dp[0] = false;
        for(int j = 0; j <= 1000000; j++)
        {
            for(int i = 0; i < 3; i++)
            {
                if(j-op[i]>=0){
                    if(!dp[j-op[i]])
                    {
                        dp[j] = true;
                    }
                }
            }
        }

        for(int i = 0; i<m;i++)
        {
            printf("%c", dp[arr[i]]?'A':'B');
        }printf("\n");

	return 0;
}
