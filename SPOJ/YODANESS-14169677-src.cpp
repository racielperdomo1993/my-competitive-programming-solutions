#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;

ll BIT[300000];
int trie[35][30];
int arr[300000];
int t;
 char s[50];
    int ls, c, p, size;
ll read(int idx)
{
    ll r = 0LL;
    while(idx>0){
        r+=BIT[idx];
        idx-=(idx&-idx);
    }
    return r;
}

void update(int idx)
{
    while(idx < 300000)
    {
        BIT[idx]+=1LL;
        idx+=(idx&-idx);
    }
}


int main()
{
    map<string,int> mapa;
    scanf("%d", &t);
    while(t--)
    {
        mapa.clear();
        size = 1;
        scanf("%d", &n);
        for(int j=0;j<n;j++)
        {
            scanf("%s", s);
            mapa[string(s)] = size++;
        }
        for(int j = 0; j < n; j++)
        {
            scanf("%s", s);
            arr[j] = mapa[string(s)];
        }
        ll sol = 0;
        for(int j = n-1; j >= 0; j--)
        {
            sol+=read(arr[j]-1);
            update(arr[j]);
        }

        printf("%lld\n", sol);
        for(int j = 0; j <300000; j++)
        {
            BIT[j] = 0LL;
        }
        for(int i = 0; i < 35; i++)
        {
            for(int j = 0; j < 30; j++)
            {
                trie[i][j] = 0;
            }
        }
    }


    return 0;
}

