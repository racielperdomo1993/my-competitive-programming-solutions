#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int t, n;
int arr[200][200];
int sol[200][200];
int solucion;
int maxi(int a, int b){
	return (a > b) ? a : b;
}
int main()
{
	scanf("%d", &t);
	while(t--)
	{
		solucion = 0;
		memset(sol, 0, sizeof(sol));
		memset(arr, 0, sizeof(arr));
		scanf("%d", &n);
		int cant = 1;
		for (int i = 0; i < n; i++)
		{
			for(int j = 0; j < cant; j++){
				scanf("%d", &arr[i][j]);
				arr[i][j] = arr[i][j] + maxi(arr[i-1][j], arr[i-1][j-1]);
			}
			cant++;
		}
		for(int a = 0; a < n; a++){
			if(arr[n-1][a] > solucion){
				solucion = arr[n-1][a];
			}
		}
		printf("%d\n", solucion);
	}
	return 0;
}

