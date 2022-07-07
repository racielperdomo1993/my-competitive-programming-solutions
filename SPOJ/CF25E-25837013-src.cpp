#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define sz(v) (v).size()
#define debug(x) cout << #x << "_=_" << x << "\n"
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vi> vvi;

#define N 500005
#define MN 500005
#define ALF 26
int term[MN], ac[MN][ALF], fail[MN], fr[MN], node[MN], siz;
vector<int> order;
const int INF = 1e9;
int conv(char c) {
	return c-'a';
}
void init() {
        for (int i = 0; i <= siz; i++) {
                memset(ac[i], 0, sizeof(ac[i]));
                term[i] = 0;
                node[i] = 0;
        }
        siz = 1;
}
void build() {
        order.clear();
        fail[1] = 1;
        fr[1] = 1;
        queue<int> Q;
        for (int i = 0; i < ALF; i++)
                if (ac[1][i]) {
                        fail[ac[1][i]] = 1;
                        fr[ac[1][i]] = 1;
                        Q.push(ac[1][i]);
                } else
                        ac[1][i] = 1;
        while (!Q.empty()) {
                int u = Q.front();
                Q.pop();
                order.push_back(u);
                int suffix_parent = fail[u];
                if(term[suffix_parent]){
					fr[u] = suffix_parent;
				}else{
					fr[u] = fr[suffix_parent];
				}
                for (int i = 0; i < ALF; i++) {
                        int v = ac[u][i];
                        if (v) {
                                fail[v] = ac[fail[u]][i];
                                Q.push(v);
                        } else {
                                ac[u][i] = ac[fail[u]][i];
                        }
                }
        }
}
void insert(char *S, int id) {
        int nod = 1;
        int len = strlen(S);
        for (int i = 0; i < len; i++) {
                int c = conv(S[i]);
                if (!ac[nod][c])
                        ac[nod][c] = ++siz;
                nod = ac[nod][c];
        }
        node[nod] = id;
        term[nod] = 1;
}

struct NODE{
		int num, mask, dist;
		NODE(){}
		NODE(int n, int m, int d) : num(n), mask(m), dist(d){}
		bool operator<(const NODE &other) const{
			if(num != other.num) return num < other.num;
			if(mask != other.mask) return mask < other.mask;
			return dist < other.dist;
		}
	};
	
bool vis[1000000][8];
int findSmallest(){
	
	queue<NODE>q;
	q.push(NODE(1, 0, 0));
	memset(vis, false, sizeof(vis));
	vis[1][0]=1;
	while(!q.empty()){
		int u = q.front().num, mask = q.front().mask, dist = q.front().dist;
		q.pop();
		int t=u;
		while (t > 1) {
			int green = fr[t];
			if(green > 1){
				mask |= (1<<(node[green]));
			}
			t = green; 
		}
		if(mask == 7){
			 return dist;
		 }
		bool edge=0;
		for (int i=0; i<ALF; i++){
			int v = ac[u][i];
			if(v && v>1){
				edge=1;
				int mask_aux = mask;
				if(term[v]){
					mask_aux = mask | (1<<node[v]);
				}
				if(!vis[v][mask_aux]){
					vis[v][mask_aux]=1;
					q.push(NODE(v, mask_aux, dist + 1));
				}
			}
		}
		if(!edge && !vis[fail[u]][mask]){                          //Si es la ultima hoja de esa rama me muevo por la arista azul
			vis[fail[u]][mask]=1;
			q.push(NODE(fail[u], mask, dist));
		}
	}
	return -1;
}

char a[1000000], b[1000000], c[1000000];

int main()
{

    while(scanf("%s%s%s", a, b, c) != EOF){
        init();
        insert(a, 0);
        insert(b, 1);
        insert(c, 2);
        build();
        printf("%d\n", findSmallest());
    }



    return 0;
}
