#include <iostream>
using namespace std;

#include "denar.h"
#include "avto.h"
#include "tockovanje.h"
#include <iostream>
using namespace std;

int main() {
	Denar a(3); //default je EUR s faktorjem 1.0
	cout<<a.toString()<<endl;
	Valuta usa("DOLAR",1.3);
	cout<<"-"<<endl;
	Denar b(13, usa);
	cout<<b.toString()<<endl;
	Denar c=a-b; //- vrne vedno EUR (3/1.0-13/1.3)
	cout<<"="<<endl;
	cout<<c.toString()<<endl; //izpiše 7

	Avto avto = Avto("ProizvajalecAvta", "ModelAvta", 2013);
	cout << endl;
	cout << avto << endl << endl;

	Tockovanje prva("prva"), druga("druga");
	prva >> 2;
	prva << 1;
	prva--;
	--prva;
	prva << 3;
	prva >> 1;

	druga >> 5;
	druga << 2;
	druga--;
	druga--;
	druga--;
	--druga;
	--druga;
	druga << 3;

	cout << endl;

	if(prva==druga) {
		cout << "Rezultata sta enaka." << endl;
	} else {
		cout << "Rezultata nista enaka." << endl;
	}

	cout << "Manjše je: ";
	if(a<b) {
		cout << a.toString();
	} else if(b<a) {
		cout << b.toString();
	} else {
		cout << "Rezultata sta enaka.";
	}

	return 0;
}
