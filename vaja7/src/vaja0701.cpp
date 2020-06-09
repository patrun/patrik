#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <time.h>
using namespace std;

const int VELIKOST = 11;

double generirajNakljucnaStevila(double min, double max) {
	double random = min + (double)rand()/((double)RAND_MAX/(max-min));
	return random;
}

void napolni(int polje[], int n) {
	for(int i=0; i<n; i+=1) {
		polje[i] = (int)generirajNakljucnaStevila(-n*1000, n*1000);
	}
}

void napolni(double polje[], int n) {
	for(int i=0; i<n; i+=1) {
		polje[i] = generirajNakljucnaStevila(-n*1000, n*1000);
	}
}

void napolni(string polje[], int n) {
	for(int i=0; i<n; i+=1) {
		stringstream ss;
		ss << "Ime" << (int)generirajNakljucnaStevila(1000, 9999);
		polje[i] = ss.str();
	}
}

template <typename T>
void uredi(T* polje, int n) {
	for(int i=0; i<n; i+=1) {
		for(int j=0; j<n-1; j+=1) {
			if(polje[j]<polje[j+1]) {
				T tmp = polje[j];
				polje[j] = polje[j+1];
				polje[j+1] = tmp;
			}
		}
	}
}

template <typename T>
void izpisiPolje(T* polje, int n) {
	for(int i=0; i<n; i+=1) {
		cout << polje[i] << " ";
	}

	cout << endl;
}

template <int N, typename T>
T najvecjiX(T* polje) {
	uredi(polje, VELIKOST);
	T shrani;

	if(N>=1 && N<=VELIKOST) {
		shrani = polje[N-1];
	}

	return shrani;
}

/*template <>
void zrcali(string* polje, int N) {
	for (int i=0; i < N/2; i += 1) {
		string tmp = polje[i];
		polje[i] = polje[N-1-i];
		polje[N-1-i] = tmp;
	}
}*/

template <int N, typename T>
T zrcali(T* polje) {
	for(int i=0; i<N/2; i+=1) {
		T tmp = polje[i];
		polje[i] = polje[N-1-i];
		polje[N-1-i] = tmp;
	}
}

int main() {
	srand(time(NULL));
	double *doublePolje = new double[VELIKOST];
	int *polje = new int[VELIKOST];
	string *stringPolje = new string[VELIKOST];

	napolni(doublePolje, VELIKOST);
	napolni(polje, VELIKOST);
	napolni(stringPolje, VELIKOST);

	cout << "Neurejeno (double): ";
	izpisiPolje(doublePolje, VELIKOST);
	cout << "Neurejeno (int): ";
	izpisiPolje(polje, VELIKOST);
	cout << "Neurejeno (string): ";
	izpisiPolje(stringPolje, VELIKOST);
	cout << endl;

	uredi(doublePolje, VELIKOST);
	uredi(polje, VELIKOST);
	uredi(stringPolje, VELIKOST);
	zrcali<VELIKOST, double>(doublePolje);
	zrcali<VELIKOST>(polje);
	//zrcali(stringPolje, VELIKOST);

	cout << "Urejeno (double): ";
	izpisiPolje(doublePolje, VELIKOST);
	cout << "Urejeno (int): ";
	izpisiPolje(polje, VELIKOST);
	cout << "Urejeno (string): ";
	izpisiPolje(stringPolje, VELIKOST);

	cout << endl;
	cout << "2. najvecji X (double) je: " << najvecjiX<2>(doublePolje) << endl;
	cout << "2. najvecji X (int) je: " << najvecjiX<2>(polje) << endl;
	cout << "2. najvecji X (string) je: " << najvecjiX<2>(stringPolje) << endl;

	delete doublePolje;
	delete polje;
	delete stringPolje;

	return 0;
}
