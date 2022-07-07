#include<bits/stdc++.h>
using namespace std;
#define MAXN 10005
vector<int> g[MAXN];
int D[MAXN];
int nod1, maxi1;
queue<int> cola;
bool visited[MAXN];
int diameter(int n)
{
    D[n] = 0;
    visited[n] = true;
    cola.push(n);
    maxi1 = 0;
    while(!cola.empty())
    {
        int u = cola.front();
        cola.pop();
        for(int i = g[u].size()-1; i >= 0; i--)
        {
            int v = g[u][i];
            if(!visited[v])
            {
                visited[v] = true;
                cola.push(v);
                D[v] = D[u]+1;
                if(D[v]>maxi1)
                {
                    maxi1 = D[v];
                    nod1 = v;
                }
            }else{
                if(D[v]>maxi1)
                {
                    maxi1 = D[v];
                    nod1 = v;
                }
            }
        }
    }
    return nod1;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 0,a,b; i < n-1; i++)
    {
        scanf("%d%d",&a,&b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int val = diameter(1);
    memset(visited,false,sizeof(visited));
    memset(D,0,sizeof(D));
    int val2 = diameter(val);
    printf("%d\n", maxi1);

    return 0;
}
