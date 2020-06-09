#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;


void vstaviSort(vector<float> &polje)
{
	for (int i = 1; i < polje.size(); i++)
	{
		int j = i;
		while (j > 0 && polje[j - 1] > polje[j])
		{
			float tmp = polje[j];
			polje[j] = polje[j - 1];
			polje[j - 1] = tmp;
			j--;
		}
	}
}

void bucketSort(vector<float> &polje)
{
	vector<float> tmp, izhod;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j<polje.size(); j++)
		{
			if (polje[j] > (float)i && polje[j] < (float)(i + 1))
				tmp.push_back(polje[j]);
		}
		vstaviSort(tmp);
		izhod.insert(izhod.end(), tmp.begin(), tmp.end());
		tmp.clear();
	}
	polje.clear();
	polje.insert(polje.end(), izhod.begin(), izhod.end());
}

void vDatoteko(vector<float> polje, string ime)
{
	ofstream file(ime);
	for (int i = 0; i < polje.size(); i++)
		file << polje[i] << " ";

	file.close();
}

int main(){

	int izbira = 0, vel;
	vector<float> polje, nesortirano;
	
	while (true){
	

		cout << "1) Generiraj nakljucno zaporedje" << endl;
		cout << "2) Uredi" << endl;
		cout << "3) Izpis" << endl;
		cout << "4) Izhod" << endl;
		cin >> izbira;

		switch (izbira)
		{
		case 1:

			cout << endl << "Vnesi velikost polja:";
			cin >> vel;

			polje.clear();
			nesortirano.clear();

			for (int i = 0; i<vel; i++)
			{
				float r = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
				polje.push_back(r);
				cout << polje[i] << " ";
			}

			nesortirano = polje;

			cout << endl << endl;

			system("cls");
			break;

		case 2:

			bucketSort(polje);
			system("cls");
			break;

		case 3:

			cout << "Nesortiran : " << endl;

			for (int i = 0; i<nesortirano.size(); i++)
			{
				cout << nesortirano[i] << " ";
			}

			cout << endl << endl << "Sortiran : " << endl;

			for (int i = 0; i<polje.size(); i++)
			{
				cout << polje[i] << " ";
			}

			cout << endl;

			vDatoteko(polje, "BucketSort.txt");

			system("pause");
			system("cls");
			break;

		case 4:

			return 0;
			break;

		default:
			system("cls");
			break;
		}
	}

}