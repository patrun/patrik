// vaja5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;


struct povezava {
  int p;
  int q;
  double cena;
};

//seznam povezav
povezava p[1124250];

//seznam sprejetih povezav
povezava r[1500];

//matrika
int *C;

int stVoz,stPov;

void beri(string f){
  fstream dat(f.c_str(), fstream::in);
	dat >> stVoz;
  int i=0;
  while(!dat.eof()){
    dat >> p[i].p >> p[i].q >> p[i].cena; 
    i++;
  }
  stPov=i;
  dat.close();
}

int deli(povezava *polje, int dno, int vrh)
{
	povezava pe;
	int	l = dno,                   //levi index
		d = vrh,                   //desni index
		mediana = (dno+vrh)/2;

	povezava temp = polje[dno];
	polje[dno] = polje[mediana];
	polje[mediana] = temp;

	pe = polje[dno];

	while(l < d)
	{
		while(polje[l].cena <= pe.cena && l < vrh)
		{
			l += 1;
		}
		while(polje[d].cena >= pe.cena && d > dno)
		{
			d -= 1;
		}

		if(l < d)
		{
			temp = polje[l];
			polje[l] = polje[d];
			polje[d] = temp;
		}
	}

	temp = polje[dno];
	polje[dno] = polje[d];
	polje[d] = temp;

	return d;
}

void hitro_uredi(povezava *polje, int dno, int vrh)
{
	if(dno < vrh)
	{
		int temp = deli(polje, dno, vrh);
		//cout << temp << endl;
		hitro_uredi(polje, dno, temp-1);
		hitro_uredi(polje, temp+1, vrh);
	}
}

void generiraj()
{
	stPov = stVoz*(stVoz-1)/2;
	int st = 0;

	for(int i=0; i<stVoz; i++)
	{
		for(int j=0; j<=stVoz; j++)
		{
			if(i!=j)
			{
				p[st].p = i;
				p[st].q = j+1; 
				p[st].cena = (rand()%30)+1;
				st++;
				//cout << "p = " << p[st].p << " | q = " << p[st].q << " | st = " << st << endl;
			}
		}
	}
}

void zdruzi(int i)
{
	int tmp = C[p[i].q];

	for(int j=0; j<stVoz; j++)
	{
		if(C[j] == tmp)
		{
			C[j] = C[p[i].p];
		}
	}
}

void pridruzi(int i)
{
	if(C[p[i].q] == 0)
	{
		C[p[i].q] = C[p[i].p];
	}
	else if(C[p[i].p] == 0)
	{
		C[p[i].p] = C[p[i].q];
	}
}

void ustvari(int i)
{
	int max = 0;

	for(int j=0; j<stVoz; j++)
	{
		if(C[j] > max)
		{
			max = C[j];
		}
	}
	C[p[i].q] = max+1;
	C[p[i].p] = max+1;
}

void kruskal()
{
	hitro_uredi(p, 0, stVoz-1);

	bool koncano = false;
	int i = 1,
		st_sprej_pov = 0;
	
	C = new int[stVoz];
	for(int j=0; j<stVoz; j++)
	{
		C[j] = 0;
	}

	while(koncano == false)
	{
		if(!(C[p[i].p] == C[p[i].q] && C[p[i].p] != 0 && C[p[i].q] != 0)) // pogoj 1
		{
			if(C[p[i].p] != C[p[i].q] && C[p[i].p] != 0 && C[p[i].q] != 0) // pogoj 2
			{
				r[st_sprej_pov] = p[i];
				st_sprej_pov++;
				zdruzi(i);
				cout << "a" << endl;
			}
			else if((C[p[i].p] == 0 && C[p[i].q] != 0) || (C[p[i].p] != 0 && C[p[i].q] == 0)) // pogoj 3
			{
				r[st_sprej_pov] = p[i];
				st_sprej_pov++;
				pridruzi(i);
				cout << "b" << endl;
			}
			else if(C[p[i].p] == 0 && C[p[i].q] == 0) // pogoj 4
			{
				r[st_sprej_pov] = p[i];
				st_sprej_pov++;
				ustvari(i);
				cout << "c" << endl;
			}
		}
		if(st_sprej_pov == stVoz-1)
		{
			koncano = true;
		}
		else
		{
			i++;
		}
	}

	cout<<"Stevilo izhodiscnih povezav: "<<stPov<<endl;
	cout<<"Stevilo izhodiscnih vozlisc: "<<stVoz<<endl;
	cout<<"Stevilo sprejetih povezav: "<<st_sprej_pov<<endl;
	cout<<endl;

}

void izpis()
{
	for(int i=0; i<stVoz-1; i++)
	{
		cout << i+1 << ") p : " << r[i].p << " q : " << r[i].q << " cena : " << r[i].cena << endl;
	}
}

void meni()
{
	cout << "Kruskalov algoritem - izbira:" << endl << endl;
	cout << "1) Preberi graf iz datoteke" << endl;
	cout << "2) Generiraj nakljucni graf" << endl;
	cout << "3) Pozeni" << endl;
	cout << "4) Izpis sprejetih povezav" << endl;
	cout << "5) Konec" << endl << endl;
	cout << "Izbira: ";
}

int _tmain(int argc, _TCHAR* argv[])
{
	srand((unsigned)time(0));
	int izbira;
	clock_t start, finish;

	for(;;)
	{
		meni();
		cin >> izbira;
		system ("cls");
		if(izbira == 1)
		{
			beri("graf.txt");
			cout << "Stevilo povezav: " << stPov << endl;
			system ("pause");
			system ("cls");
		}
		else if(izbira == 2)
		{
			do {
			cout << "Vnesi stevilo povezav (0 do 1500):";
			cin >> stVoz;
			} while( stVoz < 0 || stVoz > 1499);
			generiraj();
			
			cout << "Koncano" << endl;
			system ("pause");
			system ("cls");
		}
		else if(izbira == 3)
		{
			start = clock();
			kruskal();
			finish = clock();
			cout << "Cas: " << (double)(finish - start)/CLOCKS_PER_SEC << "s";
			cout << endl;
			system ("pause");
			system ("cls");
		}
		else if(izbira == 4)
		{
			izpis();
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