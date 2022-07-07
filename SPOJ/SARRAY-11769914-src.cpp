using namespace std;
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <climits>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <queue>
typedef long long ll;
typedef unsigned long long ull;
//code
#define MAXN 200004
string sol,soll;
string cad="";
int len, SA[MAXN], LCP[MAXN], P[MAXN], pi[MAXN], n, m;
char b[MAXN];
struct NODE
{
    int a, b, id;
};

bool operator<(const NODE &a, const NODE &b)
{
    if(a.a==b.a)
    {
        return a.b<b.b;
    }
    return a.a < b.a;
}

NODE arr[MAXN];

void suffix_array()
{
    for(int i = 0; i < len; i++)
    {
        P[i] = cad[i];
    }

    for(int cont = 1; (cont>>1)<len; cont<<=1)
    {
        for(int i = 0; i < len; i++)
        {
            arr[i].id = i;
            arr[i].a = P[i];
            arr[i].b = (i+cont)<len?P[i+cont]:-1;
        }

        sort(arr, arr+len);
        for(int i = 0; i < len; i++)
        {
            P[arr[i].id] = (i>0 && arr[i].a == arr[i-1].a && arr[i].b == arr[i-1].b) ? P[arr[i-1].id]:i;
        }
    }
    for(int i = 0; i < len; i++)
    {
        SA[P[i]] = i;
    }
}


int main()
{
    int k;
    cin >> cad;
    //scanf("%d", &k);
    //cad+=cad;
    len = cad.size();
    suffix_array();
    for(int i = 0; i < len; i++)
    {
        printf("%d\n", SA[i]);
    }
    //cout << endl;
    /*sol = "";
    int cnt = 0;
    int hh = -1;
    for(int i = 0; i < len; i++)
    {
        if(SA[i] < len/2)
        {
            cnt++;
            hh = SA[i];
        }
        if(cnt==k) break;
    }
    for(int i = hh; i < hh+len/2;i++)
    {
        sol+=cad[i];
    }
    int pos = cad.find(sol);
    printf("%d %s\n", pos, sol.c_str());
    */
    return 0;
}
