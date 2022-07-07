#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <bitset>
#include <cmath>
using namespace std;
typedef long long ll;

int main()
{
    int n, m, aux, aux2;
    map<int, bool> amigos, aamigos;
    scanf("%d", &n);
    int sol = 0;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &aux2);
        amigos[aux2] = true;
        if(amigos[aux2] && aamigos[aux2])
        {
            sol--;
            aamigos[aux2] = false;
            //cout << "desconto " << aux2 << endl;
        }
        scanf("%d", &m);
        for(int j = 0; j < m; j++)
        {
            scanf("%d", &aux);
            if(!amigos[aux] && !aamigos[aux])
            {
                sol++;
                //cout <<"conto " << aux << endl;
                aamigos[aux] = true;
            }else{
                if(amigos[aux] && aamigos[aux])
                {
                    sol--;
                    aamigos[aux] = false;
                    //cout << "desconto " << aux2 << endl;
                }
            }
        }
    }
    printf("%d\n", sol);

	return 0;
}
