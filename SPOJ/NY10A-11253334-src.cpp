#include <cstdio>
#include <cmath>
using namespace std;
int t, c;
char cad[41];
int sol[9];


void funcion (char a, char b, char c)
{
	if(a == 'T' && b == 'T' && c == 'T')
	{
		++sol[0];
	}else
	{
		if(a == 'T' && b == 'T' && c == 'H')
		{
			++sol[1];
		}else
		{
			if(a == 'T' && b == 'H' && c == 'T')
			{
				++sol[2];
			}else
			{
				if(a == 'T' && b == 'H' && c == 'H')
				{
					++sol[3];
				}else
				{
					if(a == 'H' && b == 'T' && c == 'T')
					{
						++sol[4];
					}else
					{
						if(a == 'H' && b == 'T' && c == 'H')
						{
							++sol[5];
						}else
						{
							if(a == 'H' && b == 'H' && c == 'T')
							{
								++sol[6];
							}else
							{
								if(a == 'H' && b == 'H' && c == 'H')
								{
									++sol[7];
								}
							}
						}
					}
				}
			}
		}	
	}
}

int main()
{
	
	scanf("%d", &t);
	
	while(t--)
	{
		scanf("%d", &c);
		scanf("%s", cad);
		for (int i = 0; i < 8; i++)
		{
			sol[i] = 0;
		}
		
		for(int i = 0; i < 38; i++)
		{
			funcion(cad[i], cad[i+1], cad[i+2]);
		}
		printf("%d ", c);
		for(int i = 0; i < 8; i++)
		{
			printf("%d%c", sol[i], (i==7) ? '\n': ' ');
		}
		
	}
	return 0;
}

