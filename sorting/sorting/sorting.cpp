// sorting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
using namespace std;

void generiraj(int *polje, int vel)
{
	for (int i = 0; i < vel; i++)
		polje[i] = rand() % 1000;
}

void countingSort(int *&polje, int vel)
{
	int *urejeno = new int[vel];
	int *seznam = new int[1000];

	for (int i = 0; i < 1000; i++)
		seznam[i] = 0;

	for (int i = 0; i < vel; i++)
		seznam[polje[i]]++;

	for (int i = 1; i < 1000; i++)
		seznam[i] += seznam[i - 1];

	for (int i = 0; i<vel; i++)
	{
		urejeno[seznam[polje[i]]-1] = polje[i];
		seznam[polje[i]]--;
	}

	polje = urejeno;
}

void romanSort(int *polje, int vel)
{
	int *C = new int[1000];

	for (int i = 0; i < 1000; i++)
		C[i] = 0;

	for (int i = 0; i < vel; i++)
		C[polje[i]]++;

	for (int i = 0, x = 0; i < 1000; i++)
		for (int j = 0; j < C[i]; j++, x++)
			polje[x] = i;
}

void zapisi(int *polje, int vel, string ime)
{
	ofstream file(ime);
	for (int i = 0; i < vel; i++)
		file << polje[i] << " ";

	file.close();
}

int _tmain(int argc, _TCHAR* argv[])
{
	srand((unsigned)time(0));
	clock_t zacetek,
			konec;
	double trajanje;
	int st;

	cout << "Vnesi stevilo nakljucnih stevil: ";
	cin >> st;

	cout << "\nCounting sort:\n";
	int *polje = new int[st];
	generiraj(polje, st);

	for (int i = 0; i < st; i++)
		cout << polje[i] << " ";
	cout << "\n\n";

	countingSort(polje, st);

	for (int i = 0; i < st; i++)
		cout << polje[i] << " ";
	cout << "\n\n";

	zapisi(polje, st, "counting_sort.txt");

	cout << "\nRoman sort:\n";
	
	generiraj(polje, st);

	for (int i = 0; i < st; i++)
		cout << polje[i] << " ";
	cout << "\n\n";

	romanSort(polje, st);

	for (int i = 0; i < st; i++)
		cout << polje[i] << " ";
	cout << "\n\n";

	zapisi(polje, st, "roman_sort.txt");

	system("pause");
	return 0;
}

