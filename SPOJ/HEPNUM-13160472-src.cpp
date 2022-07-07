#include <cstdio>
#include <stack>
#include <cmath>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;


    
int main() {
    
	char a[1000000], b[1000000];
	while(scanf("%s%s", a, b) && (a[0] != '*' || b[0] != '*')){
		int lenA = strlen(a);
		int lenB = strlen(b);
		int realA = 0, realB = 0;
		int pos1 = 0, pos2 = 0;
		while(a[pos1] == '0' && pos1 < lenA){
			pos1++;
		}
		while(b[pos2] == '0' && pos2 < lenB){
			pos2++;
		}
		if(pos1 == lenA && pos2 == lenB){
			printf("=\n");
		}else{
			realA = lenA - pos1;
			realB = lenB - pos2;
			if(realA > realB){
				printf(">\n");
			}else{
				if(realA < realB){
					printf("<\n");
				}else{
					if(strcmp(a,b) == 0){
						printf("=\n");
					}else{
						bool ok1 = true;
						bool ok2 = true;
						int i = pos1, j = pos2;
						while(i < lenA && j < lenB && (ok1 && ok2)){
							if(a[i] > b[j]){
								ok1 = false;
								break;
							}else{
								if(a[i] < b[j]){
									ok2 = false;
									break;
								}
							}
							i++, j++;
						}
						if(!ok1 && ok2){
							printf(">\n");
						}else{
							if(ok1 && !ok2){
								printf("<\n");
							}else{
								printf("=\n");
							}
						}
					}
				}
			}
		}
	}
    return 0;

}
