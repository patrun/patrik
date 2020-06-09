#include <iostream>
#include <fstream>
#include <string>
#include <time.h>

using namespace std;

void generiraj(int *polje, int vel)
{
	for (int i = 0; i < vel; i++)
		polje[i] = rand() % 1000;
}

void CountingSort(int* &polje, int vel){

	int *B = new int[vel];
	int *C = new int[1000];

	for (int i = 0; i < 1000; i++)
		C[i] = 0;

	for (int i = 0; i < vel; i++)
		C[polje[i]]++;

	for (int i = 1; i < 1000; i++)
		C[i] = C[i] + C[i - 1];

	for (int i = 0; i < vel; i++)
	{
		B[C[polje[i]] - 1] = polje[i];
		C[polje[i]]--;
	}

	polje = B;
}

void RomanSort(int *polje, int vel){

	int *C = new int[1000];

	for (int i = 0; i < 1000; i++)
		C[i] = 0;

	for (int i = 0; i < vel; i++)
		C[polje[i]]++;

	for (int i = 0, x = 0; i < 1000; i++)
	for (int j = 0; j < C[i]; j++, x++)
		polje[x] = i;


}

void vDatoteko(int *polje, int vel, string ime)
{
	ofstream file(ime);
	for (int i = 0; i < vel; i++)
		file << polje[i] << " ";

	file.close();
}

int main(){

	srand((unsigned)time(0));
	int vel;

	cout << "Vnesi stevilo nakljucnih stevil: ";
	cin >> vel;

	cout << endl << "Counting sort:   ";
	int *polje = new int[vel];
	generiraj(polje, vel);

	for (int i = 0; i < vel; i++)
		cout << polje[i] << " ";

	cout << endl << endl;


	CountingSort(polje, vel);

	vDatoteko(polje, vel ,"CountingSort.txt");

	for (int i = 0; i < vel; i++)
		cout << polje[i] << " ";

	cout << endl << endl;

	cout << endl << "Roman sort:   ";
	int *polje2 = new int[vel];
	generiraj(polje2, vel);

	for (int i = 0; i < vel; i++)
		cout << polje2[i] << " ";

	cout << endl << endl;

	RomanSort(polje2, vel);

	vDatoteko(polje2, vel, "RomanSort.txt");

	for (int i = 0; i < vel; i++)
		cout << polje2[i] << " ";

	cout << endl << endl;

	system("pause");
	return 0;
}