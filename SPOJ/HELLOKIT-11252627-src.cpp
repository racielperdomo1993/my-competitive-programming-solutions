using namespace std;
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <climits>
#include <cstring>
#include <map>
#include <vector>
#include <complex>
#include <list>
#include <cctype>
#include <queue>
#include <stack>
typedef long long ll;
typedef unsigned long long ull;

int  main()
{
    string cad="";
    int n;
    while(cin>>cad>>n)
    {
        int len = cad.size();
        string aux = cad;
        for (int i = 0; i < n-1; i++)
        {
            aux+=cad;
        }
        int lon = aux.size();
        int n = 0;
        //cout << aux << endl;
        for(int i = 0; i < len; i++)
        {
            for(int j = i; j < lon+n; j++)
                cout << aux[j%lon];
            cout << endl;
            n++;
        }
    }
    return 0;
}
