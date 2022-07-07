#include <bits/stdc++.h>
using namespace std;
string cad;
int sol, var,izq;
int main()
{
    cin >> cad;
    int len = cad.size();
    var =1;
    while(var<len && sol+izq+1<len){
        if(cad[sol+izq]==cad[(var+izq)%len]) izq++;
        else if(cad[sol+izq]<cad[(var+izq)%len]){
            var = var+izq+1;
            izq = 0;
        }else{
            sol = max(sol+izq+1,var);
            var = sol+1;
            izq = 0;
        }
    }
    printf("%d\n",sol);
    return 0;
}
