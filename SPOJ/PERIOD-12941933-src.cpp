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
    int t;
    cin >> t;
    int casos=1;
    for(int c = 0; c < t; c++){
        cin >> m;
        cin >> pat;
        preKmp();
        cout << "Test case #"<<casos++<<endl;
        for(int i = 1; i < m; i++)
        {
            if((i+1)%((i+1)-pi[i+1]) == 0 && (i+1)/((i+1)-pi[i+1]) > 1)
            {
                cout << i+1 << " " << (i+1)/((i+1)-pi[i+1])<<endl;
            }
        }
        if(casos<t-1)
        {
            cout << endl;
        }
    }


    return 0;
}
