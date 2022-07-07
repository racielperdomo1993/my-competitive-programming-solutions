#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <bitset>
#include <utility>
#include <set>
#include <math.h>

using namespace std;


int main ()
{
    float n;
    while(scanf("%f", &n) && n){
		float cont = 2.0;
		int lleva = 1;
		float i = 1.0/cont;  // 1/2 
		while(i < n){
			i += 1.0/++cont;
			lleva++;
		}printf("%d card(s)\n", lleva);
	}
 
    return 0;
}