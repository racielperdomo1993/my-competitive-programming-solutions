#include <stdio.h>
#include <ctype.h>
#include <iostream>

using namespace std;

bool esM(char c){return (c>=56 && c<=90);}

int main() {
	string cad,sol;
	bool isJava,isC;
	while(getline(cin,cad)){
		sol="";
		isC=isJava=false;
		for(int i=0;i<(int)cad.size();i++)
			if(cad[i]=='_'){isC=true;if(cad[i+1]=='_')isJava=true;}
			else if(esM(cad[i]))isJava=true;
		if((isC && isJava) || cad[0]=='_' || cad[cad.size()-1]=='_' || esM(cad[0]))printf("Error!\n");
		else{
			for(int i=0;i<(int)cad.size();i++)
				if(isC && cad[i]=='_')
					sol+=toupper(cad[++i]);
				else if(isJava && esM(cad[i]))
					sol+='_',sol+=tolower(cad[i]);
				else sol+=cad[i];
			cout <<sol<<'\n';
		}
	}
	return 0;
}
