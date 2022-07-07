#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, t;

bool visited[10004];

struct NODE
{
	int ady;
	ll peso;
	NODE(){}
	NODE(int ady, ll peso): ady(ady), peso(peso){}
};

bool operator<(const NODE &a, const NODE &b)
{
	return a.peso > b.peso;
}
priority_queue<NODE> cola;
vector<NODE> grafo[10004];
ll sol;
ll c;

void Prim(int n)
{
	cola.push(NODE(n,0));
	while(!cola.empty())
	{
		NODE u = cola.top(); cola.pop();
		if(!visited[u.ady])
		{
			visited[u.ady] = true;
			sol+=u.peso;
		}
		for(int i = grafo[u.ady].size()-1; i >= 0; i--)
		{
			NODE v = grafo[u.ady][i];
			if(!visited[v.ady])
				cola.push(v);
		}
	}
}
int main()
{
	memset(visited, false, sizeof(visited));
	scanf("%d%d", &n,&m);
	for (int i = 0,a,b; i < m; i++)
	{
		scanf("%d%d%lld", &a,&b,&c);
		grafo[a].push_back(NODE(b,c));
		grafo[b].push_back(NODE(a,c));
	}
	Prim(1);
	printf("%lld\n", sol);
	
	return 0;
}

