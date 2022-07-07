#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 4000000
char T[MAXN],P[MAXN];
vector<int> sol;

int pi[MAXN]; // prefix function
void PreKMP(char *P,int n){
   int q,k=0; pi[1] = 0;
   for(q =2;q <=n; pi[q++] =k){
      while(k && (P[k]!=P[q-1]))
         k=pi[k];
      if(P[k]==P[q-1]) k++;
   }
}
void KMP(char *T,int n,char *P,int m){
   int i,q=0; PreKMP(P,m);
   for(i=1;i <= n;i++){
      while((q>0) && (P[q]!=T[i-1]))
         q = pi[q];
      if(P[q]==T[i-1]) q++;
      if(q==m) q = pi[q];//found
   }
}
int main()
{
    int n,m;
    while(scanf("%s", P)!=EOF)
    {
        if(P[0]=='*') break;
        m = strlen(P);
        PreKMP(P,m);
        int sol = 0;
        if(m%(m-pi[m])==0)
        {
            sol=m/(m-pi[m]);
        }else{
            sol = 1;
        }
        cout <<sol<<endl;
    }

    return 0;
}
