#include <bits/stdc++.h>
using namespace std;
int n, m, t;
vector<int> grafo[100004];
bool visited[100004];
stack<int> pila;
void DFS(int n)
{
	pila.push(n);
	while(!pila.empty())
	{
		int u = pila.top(); pila.pop();
		visited[u] = true;
		for(int i = grafo[u].size()-1; i >= 0; i--)
		{
			int v = grafo[u][i];
			if(!visited[v])
			{
				pila.push(v);
				visited[v] = true;
			}
		}
	}
}

int main()
{
	scanf("%d", &t);
	while(t--)
	{
		for(int i = 0; i < 100004; i++)
			grafo[i].clear();
		memset(visited, false, sizeof(visited));
		scanf("%d%d", &n,&m);
		for (int i = 0,a,b; i < m; i++)
		{
			scanf("%d%d", &a,&b);
			grafo[a].push_back(b);
			grafo[b].push_back(a);
		}
		int sol = 0;
		for(int i = 1; i <= n; i++)
		{
			if(!visited[i])
			{
				sol++;
				DFS(i);
			}
		}
		printf("%d\n", sol-1);
	}
	return 0;
}

