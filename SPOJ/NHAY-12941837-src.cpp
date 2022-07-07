#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int pi[4000000];
char text[4000000],pat[4000000];
vector<int> sol;
int n,m;

void preKmp()
{
    int i = 0, j = -1;
    pi[0] = -1;
    while(i < m)
    {
        while(j>=0 && pat[i]!=pat[j])
        {
            j = pi[j];
        }
        i++,j++;
        pi[i] = j;
    }
}

void kmp()
{
    int i=0,j=0;
    while(i<n)
    {
        while(j>=0 && text[i]!=pat[j])
        {
            j=pi[j];
        }
        i++,j++;
        if(j==m)
        {
            sol.push_back(i-m);
            j=pi[j];
        }
    }
}
int main()
{
    while(cin >> m >> pat >> text)
    {
        n = strlen(text);
        sol.clear();
        preKmp();
        kmp();
        for(int i = 0; i < sol.size(); i++)
        {
            cout << sol[i] << endl;
        }
        if(sol.size()==0) cout << endl;
    }

    return 0;
}
