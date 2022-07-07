#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N = 1e5 + 5;

struct state {
    int len, link, next[26];
    bool is_clone = false;
    ll cnt = 0;
};

string s;
state st[2*N];

int n, k, sz, last;
vector<pair<int, int> > order;

void st_init() {
    st[0].len = 0;
    st[0].link = -1;
    sz++;
    last = 0;
}

void st_extend(int c){
    int cur = sz++;
    st[cur].len = st[last].len + 1;
    st[cur].cnt = 1;
    order.emplace_back(st[cur].len, cur);
    int p = last;
    while (p != -1 && !st[p].next[c]) {
        st[p].next[c] = cur;
        p = st[p].link;
    }
    if (p == -1) {
        st[cur].link = 0;
    } else {
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len) {
            st[cur].link = q;
        } else {
            int clone = sz++;
            st[clone].is_clone = true;
            st[clone].len = st[p].len + 1;
            st[clone].link = st[q].link;
            st[clone].cnt = 1;
            memcpy(st[clone].next, st[q].next, sizeof(st[q].next));
            order.emplace_back(st[clone].len, clone);
            while (p != -1 && st[p].next[c] == q) {
                st[p].next[c] = clone;
                p = st[p].link;
            }
            st[cur].link = st[q].link = clone;
        }
    }
    last = cur;
}

vector<int> terminales;
string sol = "";
map<int, string> dp;

void solve(int nodo, int K){
    for(int i = 0; i < 26; i++){
        int ady = st[nodo].next[i];
        if(ady){
            int aux = ady;
            if(K > st[aux].cnt){
                K-=st[aux].cnt;
            }else{
                sol += char(i + 'a');
                K--;
                if(K <= 0){
                    return;
                }
                solve(ady, K);
                break;
            }
        }
    }
}

void build_term(int nodo){
    while(nodo != -1){
        terminales.push_back(nodo);
        nodo = st[nodo].link;
        cout << nodo<<endl;
    }
}

int main()
{
    cin >> s;
    n = s.length();
    st_init();
    order.emplace_back(0, 0);
    st[0].cnt = 1;
    for(int i = 0; i < n; i++){
        st_extend(s[i]-'a');
    }
    sort(order.begin(), order.end());
    reverse(order.begin(), order.end());
    for(auto &nodo: order){
        int u = nodo.second;
        for(int i = 0; i < 26; i++){
            int ady = st[u].next[i];
            if(ady){
                st[u].cnt += st[ady].cnt;
            }
        }
    }
    int test;
    cin >> test;
    for(int i = 0; i < test; i++){
        cin >> k;
        sol = "";
        solve(0, k);
        cout << sol << endl;
    }
	return 0;
}
