#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<string, bool> mapa;
map<string, int> hasheo;

int hash(string key)
{
	int sol = 0;
	for(int i = 0; i < (int)key.size(); i++)
	{
		sol= (sol+ ((int)(key[i])*(i+1)));
	}
	return (19*sol);
}

int Hash(string key)
{
	int val = hash(key)%101;
	hasheo[key] = val;
	//if(key == "marsz") cout << val << endl;
	return val;
}

struct Table{
	string cad;
	Table(){}
	Table(string cad): cad(cad){}
} tabla[106];


int t, n;
string cad,cad2;
int contador;
void add(string cadena)
{
	int hashi = Hash(cadena);
	//cout << cadena << ": " << hashi << endl;
	for(int j = 0; j <= 19; j++)
	{
		int val = (hashi + (j*j) + (23*j))%101;
		if(tabla[val].cad == "")
		{
			tabla[val] = Table(cadena);
			contador++;
			return;
		}
	}
}
vector<int> id;

void del(string cadena)
{
	for(int i = 0; i < 101; i++)
	{
		if(tabla[i].cad == cadena)
		{
			tabla[i] = Table(string(""));
			contador--;
		}
	}
}

int main()
{
	cin >> t;
	while(t--)
	{
		for(int i = 0; i < 101; i++)
		{
			tabla[i] = Table(string(""));
		}
		contador = 0;
		hasheo.clear();
		mapa.clear();
		id.clear();
		map<int,int> real;
		real.clear();
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> cad;
			cad2 = "";
			if(cad[0] == 'A' || cad[0] == 'a')
			{
				for(int j = 4; j < (int)cad.size(); j++)
				{
					cad2+=cad[j];
				}
				if(!mapa[cad2] && cad2!="")
				{
					add(cad2);
					mapa[cad2] = true;
				}
			}else{
				for(int j = 4; j < (int)cad.size(); j++)
				{
					cad2+=cad[j];
				}
				if(mapa[cad2] && cad2 != ""){
					del(cad2);
					mapa[cad2] = false;
				}
			}
		}
		cout << contador << endl; 
		/*for(int i = 0; i < 101; i++)
		{
			if(tabla[i].cad.size()>0)
			{
				id.push_back(hasheo[tabla[i].cad]);
				real[hasheo[tabla[i].cad]] = i;
			}
		}*/
		/*sort(id.begin(), id.end());
		for(int i = 0; i < (int)id.size(); i++)
		{
			cout << id[i] << ":"<<tabla[real[id[i]]].cad << endl;
		}*/
		for(int i = 0; i < 101; i++)
		{
			if(tabla[i].cad!="")
				cout << i << ":" << tabla[i].cad << endl;
		}
		
		
	}
	return 0;
}

