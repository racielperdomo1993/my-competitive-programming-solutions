using namespace std;
#include <cstdio>
#include <cstring>
#include <stack>


stack<char> Pila;

int prec(char m){
    if(m == '('){
        return 0;
	}
    if(m == '+' || m == '-'){
            return 0;
	}
    if(m == '*' || m == '/'){
		 return 1;
	}
	if(m == '^'){
		return 2;
	}
	return -1;
}

bool isOperator(char m){
    return (m == '+' || m == '-' || m == '*' || m == '/' || m == '^');
}

     


int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        char frase[400];
        scanf("%s", frase);
        int len = strlen(frase);
        frase[len] = ')';
        Pila.push('(');
        for(int i = 0; i <= len; i++){
            if(frase[i] == '('){
                Pila.push(frase[i]);
            }
            else if(isOperator(frase[i])){
                    while(prec(frase[i]) < prec(Pila.top())){
						
							printf("%c", Pila.top());
							Pila.pop();
						
					}
					Pila.push(frase[i]);
				}
                else if(frase[i] == ')'){
                        while(Pila.top() != '('){
							printf("%c", Pila.top());
							Pila.pop();
						}
						Pila.pop();
					}
				else{
                        printf("%c", frase[i]);
                        }
                            
                        }
                        printf("\n");
                    }
                
    
    

    return 0;
}