#include <iostream>
#include "Oglas.h"
#include "AvtoOglas.h"
#include "Stanovanje.h"
#include "TuristicniOglas.h"
#include "RacunalnikOglas.h"

#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include "exceptionHandler.h"

using namespace std;

vector<AvtoOglas*> seznamAvtoOglas;

struct vsebinaOglasa {
	string ime;
	string datum;
	double cena;
	string proizvajalec;
	string model;
	int letnik;
};

/*void reset(vsebinaOglasa &vo) {
	vo.ime = "\0";
	vo.datum = "\0";
	vo.cena = -1;
	vo.proizvajalec = "\0";
	vo.model = "\0";
	vo.letnik = -1;
}*/

void dodajVSeznam(vsebinaOglasa vo) {
	int dan = atoi(vo.datum.substr(0,2).c_str());
	int mesec = atoi(vo.datum.substr(2,2).c_str());
	int leto = atoi(vo.datum.substr(4,4).c_str());

	Datum *d = new Datum(dan, mesec, leto);
	AvtoOglas *ao = new AvtoOglas(vo.ime, d, vo.cena, vo.proizvajalec, vo.model, vo.letnik);

	seznamAvtoOglas.push_back(ao);
}

void beriDatoteko(string datoteka) {
	ifstream dat;
	dat.open(datoteka.c_str());

	if(dat.is_open()) {
		while(!dat.eof()) {
			vsebinaOglasa vo;

			dat >> vo.ime;
			dat >> vo.datum;
			dat >> vo.cena;
			dat >> vo.proizvajalec;
			dat >> vo.model;
			dat >> vo.letnik;

			dodajVSeznam(vo);
		}
	}

	dat.close();
}

string spremeniDatum(Datum* datum) {
	stringstream ss;
	int dan = datum->getDan();
	int mesec = datum->getMesec();
	int leto = datum->getLeto();

	if(dan<10) {
		ss << "0";
	}
	ss << dan;

	if(mesec<10) {
		ss << "0";
	}
	ss << mesec;
	ss << leto;

	return ss.str();
}

void ustvariDatoteko(string datoteka) {
	ofstream dat;
	dat.open(datoteka.c_str());

	if(dat.is_open()) {
		for(unsigned int i=0; i<seznamAvtoOglas.size(); i+=1) {
			dat << seznamAvtoOglas[i]->getNaslov() << " ";
			dat << spremeniDatum(seznamAvtoOglas[i]->getDatumObjave()) << " ";
			dat << seznamAvtoOglas[i]->getCena() << " ";
			dat << seznamAvtoOglas[i]->getProizvajalec() << " ";
			dat << seznamAvtoOglas[i]->getModel() << " ";
			dat << seznamAvtoOglas[i]->getLetnik() << endl;
		}
	}
	dat.close();
}

bool primerjaj(AvtoOglas *a, AvtoOglas *b) {
	return (a->getCena()<b->getCena());
}

int main() {
	beriDatoteko("oglasi.txt");

	sort(seznamAvtoOglas.begin(), seznamAvtoOglas.end(), primerjaj);

	for(unsigned int i = 0; i<seznamAvtoOglas.size(); i+=1) {
		cout << seznamAvtoOglas[i]->toString() << endl;
	}

	ustvariDatoteko("urejen.txt");

	seznamAvtoOglas.clear();
	return 0;
}
