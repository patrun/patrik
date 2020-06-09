#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <algorithm>

using namespace std;

void abeceda(char abc[5][5]){
	
	fstream dat;
	dat.open("abeceda.txt");

	int i = 0, j = 0;

	while (dat.good())
	{
		char c = dat.get();
		abc[i][j] = c;
		j++;

		if (j == 5){
			j = 0;
			i++;
			if (i == 5)
				break;
		}

	}
	dat.close();

}

string  SpremeniVhod(char abc[5][5], string vhod){

	string izhod = "";
	char ADFGX[] = { 'A', 'D', 'F', 'G', 'X' };

	for (int a = 0; a < vhod.length(); a++){
		for (int i = 0; i < 5; i++){
			for (int j = 0; j < 5; j++){
				if (abc[i][j] == vhod[a]){
					izhod += ADFGX[i];
					izhod += ADFGX[j];
				}
			}
		}
	}
	
	return izhod;

}


string  SpremeniIzhod(char abc[5][5], string vhod){

	string izhod = "";
	char ADFGX[] = { 'A', 'D', 'F', 'G', 'X' };

	int x = 6, y = 6;
	for (int i = 0; i < 5; i++)
	{
		if (vhod[0] == ADFGX[i])
			x = i;
		if (vhod[1] == ADFGX[i])
			y = i;
	}
	if (x < 5 && y < 5)
		izhod = abc[x][y];

	if (izhod == "i")
		izhod = "(i/j)";

	return izhod;

}


string  sifrirajADFGX(char abc[5][5], string kljuc, string vhod){
	
	string izhod = "";
	string* K = new string[kljuc.length()];

	for (int i = 0; i < vhod.length(); i++){
		if (vhod[i] == 'j')
			vhod[i] = 'i';
	}

	izhod = SpremeniVhod(abc, vhod);

	for (int i = 0; i < kljuc.length(); i++)
		K[i] = "";

	int i = 0, j = 0;

	while (true){
		if (i == kljuc.length())
			i = 0;

		K[i] += izhod[j];
		i++;
		j++;
		
		if (j == izhod.length())
			break;
	}	

	/*for (int i = 0; i < kljuc.length(); i++)
		cout << K[i] << endl;*/

	string k = kljuc;
	sort(k.begin(), k.end());
	string *K2 = new string[kljuc.length()];

	for (int i = 0; i < kljuc.length(); i++)
	{
		for (int j = 0; j < kljuc.length(); j++)
		{
			if (k[i] == kljuc[j])
			{
				K2[i] = K[j];
				kljuc[j] = ' ';
				break;
			}
		}
	}

	/*cout << endl << endl;

	for (int i = 0; i < kljuc.length(); i++)
		cout << K2[i] << endl;*/

	string rez = "";

	for (int i = 0; i < kljuc.length(); i++)
		rez += K2[i];


	return rez;

}

string desifrirajADFGX(char abc[5][5], string kljuc, string vhod){

	int dolzina = ceil((double)vhod.length() / (double)kljuc.length());
	int stevilo = vhod.length() % kljuc.length();

	//cout << dolzina << endl << stevilo << endl << endl;

	string k = kljuc;
	sort(k.begin(), k.end());
	string *K2 = new string[kljuc.length()];

	for (int i = 0; i < kljuc.length(); i++)
		K2[i] = "";

	int st = 0;

	for (int i = 0; i < kljuc.length(); i++){
		for (int j = 0; j < kljuc.length(); j++){
			if (k[i] == kljuc[j]){
				if (j < stevilo){
					for (int a = 0; a < dolzina; a++){
						K2[i] += vhod[st];
						cout << vhod[st] << "   ";
						st++;
					}
					cout << endl;
				}
				else{
					for (int a = 0; a < dolzina - 1; a++){
						K2[i] += vhod[st];
						cout << vhod[st] << "   ";
						st++;
					}
					cout << endl;
				}
				k[i] = ' ';
			}
		}
	}

	k = kljuc;
	sort(k.begin(), k.end());
	string *K = new string[kljuc.length()];

	for (int i = 0; i < kljuc.length(); i++)
	{
		for (int j = 0; j < kljuc.length(); j++)
		{
			if (kljuc[i] == k[j])
			{
				K[i] = K2[j];
				k[j] = ' ';
				break;
			}
		}
	}
	
	cout << endl << endl;

	for (int i = 0; i < kljuc.length(); i++)
		cout << K[i] << endl;


	string rez = "";
	st = 0;

	for (int i = 0;; i++)
	{
		if (i == kljuc.length())
		{
			i = 0;
			st++;
		}

		if (i < stevilo && st < dolzina)
			rez += K[i][st];
		else if (st < dolzina - 1)
			rez += K[i][st];
		else
			break;
	}
	cout << rez << endl;

	string izhod = "";
	for (int i = 0; i < rez.length(); i += 2)
	{
		string x;
		x = rez[i];
		x += rez[i + 1];

		izhod += SpremeniIzhod(abc, x);
	}
	

	return izhod;

}

void abecedaPF(char abc[5][5], string kljuc){

	string abcd = "";
	int st = 0;

	for (int i = 0; i < kljuc.length(); i++)
	{
		if (kljuc[i] == 'j')
			kljuc[i] = 'i';
	}

	for (int i = 0; i < kljuc.length(); i++)
	{
		bool je = false;

		for (int j = 0; j < abcd.length(); j++)
		{
			if (kljuc[i] == abcd[j]){
				je = true;
				break;
			}
		}
		if (je == false)
			abcd += kljuc[i];
	}

	for (int a = 'a'; a <= 'z'; a++){
		if (a != 'j')
		{
			bool je = false;

			for (int j = 0; j < abcd.length(); j++)
			{
				if (abcd[j] == a){
					je = true;
					break;
				}
			}
			if (je == false)
				abcd += a;
		}
	}
	
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			abc[i][j] = abcd[st++];
		}
	}
}

string zamenjaj(char abc[5][5], string niz){

	int x1 = 5, y1 = 5, x2 = 5, y2 = 5;
	string r = "";

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (abc[i][j] == niz[0])
			{
				x1 = i;
				y1 = j;
			}
			if (abc[i][j] == niz[1])
			{
				x2 = i;
				y2 = j;
			}
		}
	}

	if (x1 == x2)
	{
		if (y1 < 4)
			r += abc[x1][y1 + 1];
		else
			r += abc[x1][0];

		if (y2 < 4)
			r += abc[x2][y2 + 1];
		else
			r += abc[x2][0];
	}
	else if (y1 == y2)
	{
		if (x1 < 4)
			r += abc[x1 + 1][y1];
		else
			r += abc[0][y1];

		if (x2 < 4)
			r += abc[x2 + 1][y2];
		else
			r += abc[0][y2];
	}
	else
	{
		r += abc[x1][y2];
		r += abc[x2][y1];
	}


	return r;
}

string zamenjajNazaj(char abc[5][5], string niz){

	int x1 = 5, y1 = 5, x2 = 5, y2 = 5;
	string r = "";

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (abc[i][j] == niz[0])
			{
				x1 = i;
				y1 = j;
			}
			if (abc[i][j] == niz[1])
			{
				x2 = i;
				y2 = j;
			}
		}
	}

	if (x1 == x2)
	{
		if (y1 > 1)
			r += abc[x1][y1 - 1];
		else
			r += abc[x1][4];

		if (y2 > 1)
			r += abc[x2][y2 - 1];
		else
			r += abc[x2][4];
	}
	else if (y1 == y2)
	{
		if (x1 > 1)
			r += abc[x1 - 1][y1];
		else
			r += abc[4][y1];

		if (x2 > 1)
			r += abc[x2 - 1][y2];
		else
			r += abc[4][y2];
	}
	else
	{
		r += abc[x1][y2];
		r += abc[x2][y1];
	}


	return r;
}

void pripraviVhod(string &niz){

	for (int i = 0; i < niz.length(); i++){
		if (niz[i] == 'j')
			niz[i] = 'i';
	}

	for (int i = 0; i < niz.length(); i++){
		if (niz[i] == niz[i + 1]){
			if (niz[i] != 'x'){
				niz.insert(i + 1, "x");
			}
			else
				niz.insert(i + 1, "y");
		}
	}

	if (niz.length() % 2 != 0){
		if (niz[niz.length() - 1] != 'x'){
			niz += "x";
		}
		else{
			niz += "y";
		}
	}

}

string  sifrirajPlayFair(char abc[5][5], string vhod){

	pripraviVhod(vhod);
	string izhod = "";

	for (int i = 0; i < vhod.length(); i++){
		string niz = "";
		niz = vhod[i++];
		niz += vhod[i];
		
		izhod += zamenjaj(abc, niz);
	}

	return izhod;
}

string  desifrirajPlayFair(char abc[5][5], string vhod){

	pripraviVhod(vhod);
	string izhod = "";

	for (int i = 0; i < vhod.length(); i++){
		string niz = "";
		niz = vhod[i++];
		niz += vhod[i];

		izhod += zamenjajNazaj(abc, niz);
	}
	string r = "";
	for (int i = 0; i < izhod.length(); i++){
		if (izhod[i] == 'i')
			r += "(i/j)";
		else
			r += izhod[i];
	}

	return r;
}


void parametri(string &beseda, string &kljuc){
	cout << "Vnesi besedo: " << endl;
	cin >> beseda;
	cout << "Vnesi kljuc: " << endl;
	cin >> kljuc;
}


int main(){

	int izbira = 0;

	while (true){


		string beseda, kljuc, h, k;
		char abc[5][5];

		cout << "Izberi algoritem: " << endl;
		cout << "1. ADFGX algoritem" << endl;
		cout << "2. PlayFair algoritem" << endl;
		cout << "3. Izhod" << endl;
		cin >> izbira;

		switch (izbira)
		{
		case 1:

			abeceda(abc);

			parametri(beseda, kljuc);
			
			h = sifrirajADFGX(abc, kljuc, beseda);

			cout << "Sifrirano:  " << h << endl << endl;

			k = desifrirajADFGX(abc, kljuc, h);

			cout << endl << "Desifrirano:  " << k << endl;

			system("PAUSE");
			system("cls");
			break;

		case 2:

			parametri(beseda, kljuc);
			abecedaPF(abc, kljuc);
			h = sifrirajPlayFair(abc, beseda);

			cout << "Sifrirano:  " <<h << endl << endl;

			cout << "Desifrirano:  " << desifrirajPlayFair(abc, h) << endl << endl;
			
			system("PAUSE");
			system("cls");
			break;

		case 3:

			return 0;
			break;

		default:
			system("cls");
			break;
		}
	}
	


	
}