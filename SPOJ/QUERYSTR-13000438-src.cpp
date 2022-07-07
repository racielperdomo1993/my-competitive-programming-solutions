#include <bits/stdc++.h>
using namespace std;
#define MAXN 2000005
#define FAB(i,val,val2) for(int i = val; i < val2; i++)

int z[MAXN]; // Z[i]=SA[i]%SA[0]
char s[MAXN];
void zAlgo(char *cad, int n)
{
    int L = 0, R = 0;
    for (int i = 1; i < n; i++) {
        if (i > R) {
            L = R = i;
            while (R < n && s[R-L] == s[R]) R++;
            z[i] = R-L; R--;
        } else {
            int k = i-L;
            if (z[k] < R-i+1) z[i] = z[k];
            else {
              L = i;
              while (R < n && s[R-L] == s[R]) R++;
              z[i] = R-L; R--;
            }
        }
    }
}
int t,q,n,val;
int main()
{

    scanf("%d",&t);
    while(t--)
    {
        scanf("%s", s);
        n = strlen(s);
        reverse(s, s+n);
        zAlgo(s,n);
        z[0] = n;
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d",&val);
            printf("%d\n",z[n-val]);
        }
    }



    return 0;
}
