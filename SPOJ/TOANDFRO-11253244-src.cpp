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
typedef long long ll; 
typedef unsigned long long ull;

int n;
char arr[201];

int main() {
	
	while(scanf("%d", &n) && n != 0){
		scanf("%s", arr);
		int len = strlen(arr) / n;
		int cant = 0;
		char decode[len][n];
		for(int i = 0; i < len; i++){
			for(int j = 0; j < n; j++){
				if(i % 2 == 0){
					decode[i][j] = arr[cant++];
				}else{
					decode[i][n-1-j] = arr[cant++];
				}
			}
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < len; j++){
				printf("%c", decode[j][i]);
			}
		}printf("\n");
	}
	
	return 0;
}