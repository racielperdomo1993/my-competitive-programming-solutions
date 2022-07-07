#include <iostream>
#include <cstdio>
using namespace std;
 int n,m,t;

double dp[2004][2004];
int main()
{
    for(int i = 1; i <= 6; i++)
    {
        dp[i][1] = 1.0/6.0;
    }
    for(int i = 2; i<=2000;i++)
    {
        for(int j = i; j <= 2000; j++)
        {
            for(int k = 1; k<=6 && k<=j;k++)
            {
                if(j-k>=1)
                {
                    dp[j][i]+=(dp[j-k][i-1])/6.0;
                }
            }
        }
    }
    cin >> t;
    while(t--)
    {
        scanf("%d%d",&n,&m);
        if(n>2000 || m > 2000)
            cout <<0<<endl;
        else{
            unsigned long long r =  dp[m][n]*100;
            cout << r << endl;
        }


    }

    return 0;
}
