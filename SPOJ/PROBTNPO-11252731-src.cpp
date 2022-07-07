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

void f(int a, int b) {
    int lenght = 1, array[abs(a-b)], c = 0, max = 0;
    int a_2 = a, b_2 = b;
    if(a > b) swap(a,b);
    for(int i = a; i <= b; i++) {
        int n = i;
        while(n != 1) {
            if(n%2!=0) {
                n = (n*3)+1;
            }
            else {
                n /= 2;
            }
            lenght++;
        }
        array[c++] = lenght;
        lenght = 1;
    }
    for(int i = 0; i < c; i++) {
        if(max < array[i]) {
            max = array[i];
        }
    }
    printf("%d %d %d\n",a_2, b_2, max);
}

int  main()
{
    int a, b;
       while(scanf("%d%d",&a,&b)!=EOF) {

           f(a,b);
       }
    return 0;
}
