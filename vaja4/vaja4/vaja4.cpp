// vaja4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

struct Vozlisce {
	int ime;
	int predhodnik;
	int dolzina;
	int status;
};

int vel = 0;
int C[30][30];
Vozlisce *G = new Vozlisce[150];
Vozlisce *H = new Vozlisce[150];
int st_H = 0;
int glava_H = 0;

void beri(string f)
{
	fstream dat(f.c_str(), fstream::in);
	dat >> vel;
	int x, y, c;
	while(!dat.eof())
	{
		dat >> x >> y >> c;
		C[x-1][y-1] = c;
		C[y-1][x-1] = c;
	}
	dat.close();
}

void PUSH(Vozlisce x)
{
	bool preveri = true;

	for(int i=0; i<st_H; i++)
	{
		if(H[i].ime == x.ime)
		{
			preveri = false;
		}
	}

	if(preveri == true)
	{
		H[st_H] = x;
		st_H++;
	}
}

void iskanje_v_globino(Vozlisce *s, Vozlisce *d)
{
	for(int i=0; i<vel; i++)//narejde graf
	{
		G[i].ime = i;
		G[i].status = 0;
		G[i].dolzina = std::numeric_limits<int>::max();
		G[i].predhodnik = -1;
	}

	s->status = 1;
	s->dolzina = 0;
	s->predhodnik = -1;

	PUSH(*s);

	while(st_H-glava_H!=0)
	{
		Vozlisce x = H[glava_H];
		glava_H++;
		for(int i=0; i<vel; i++)//ide skoz graf
		{
			if(C[x.ime][i] == 1)//prevere, èe je sosed
			{
				if(G[i].status==0)
				{
					G[i].status=1;
					G[i].dolzina = x.dolzina+1;
					G[i].predhodnik = x.ime;
					PUSH(G[i]);
				}
			}
		}
		x.status =2;
	}

}

void izpis_poti(Vozlisce s, Vozlisce v, int c)
{
	if(s.ime == v.ime)
	{
		cout << "Dolzina poti do " << s.ime << " je " << c << endl;
	}
	else
	{
		if(v.predhodnik == -1)
		{
			cout << "Med " << s.ime << " in " << v.ime << " ni poti." << endl;
		}
		else
		{
			izpis_poti(s, G[v.predhodnik], c);
			cout << v.ime << " ";
		}
	}
}

void meni()
{
	cout << "Iskanje v globino - izbira:" << endl << endl;
	cout << "1) Preberi graf iz datoteke" << endl;
	cout << "2) Pozeni iskanje iz vozlisca s do d" << endl;
	cout << "3) Konec" << endl << endl;
	cout << "Izbira: ";
}

int _tmain(int argc, _TCHAR* argv[])
{
	int izbira, a, b;

	for(;;)
	{
		meni();
		cin >> izbira;
		system ("cls");
		if(izbira == 1)
		{
			beri("graf.txt");
			cout << "Velikost: " << vel << endl;
			for(int j=0;j<vel;j++)
			{
				for(int i=0;i<vel;i++)
				{
					cout << C[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;
			
			system ("pause");
			system ("cls");
		}
		else if(izbira == 2)
		{
			if(vel == 0)
			{
				cout << "Najprej je potrebno prebrati graf." << endl;
			}
			else
			{
				cout << "Vnesi stevilo vozlisca s (Med 0 in " << vel << "):";
				cin >> a;
				cout << "Vnesi stevilo vozlisca d (Med 0 in " << vel << "):";
				cin >> b;
				
				st_H = 0;
				glava_H = 0;

				iskanje_v_globino(&G[a], &G[b]);
				izpis_poti(G[a], G[b], G[b].dolzina);
			}
			cout << endl;
			system ("pause");
			system ("cls");
		}
		else
		{
			break;
		}
	}

	return 0;
}
