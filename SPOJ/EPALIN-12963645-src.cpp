#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000005
char T[MAXN], P[MAXN];
int pi[MAXN];

void PreKMP(string P, int n)
{
    int q,k=0;
    pi[1] = 0;
    for(q=2; q <= n; pi[q++] = k){
        while(k && (P[k] != P[q-1]))
            k = pi[k];
        if(P[k]==P[q-1]) k++;
    }
}

void KMP(char *T, int n, char *P, int m){
    int i,q=0; PreKMP(P,m);
    for(i = 1; i <= n; i++)
    {
        while((q>0) && (P[q]!=T[i-1]))
            q = pi[q];
        if(P[q] == T[i-1]) q++;
        if(q==m) q = pi[q];
    }
}
string cad,cad2,cad3;
int main()
{
    while(true)
    {
       cin >> cad;
       if(cin.eof()) break;
       int real = cad.size();
       cad2="";
       for(int i = real-1; i >= 0; i--)
       {
           cad2+=cad[i];
       }
       for(int i = 0; i < real; i++)
       {
           cad2+=cad[i];
       }
       int len = cad2.size();
       PreKMP(cad2,len);
       if(pi[len]>=real) cout << cad << endl;
       else{
            cout << cad;
            string aux = "";
            for(int i = 0; i < real; i++)
            {
                aux+=cad2[i];
            }
            reverse(aux.begin(), aux.end());
            for(int i = real-pi[len]-1; i >= 0;i--)
            {
                cout << aux[i];
            }
            cout << endl;
       }

       //zyxxyz
       //000001
       //xyzxy

    }


    return 0;
}
