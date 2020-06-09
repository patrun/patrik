#include "TuristicniOglas.h"

#include <sstream>
using namespace std;

TuristicniOglas::TuristicniOglas() : Oglas() {
	vrsta = "Apartma";
	kraj = "Maribor";
}

TuristicniOglas::TuristicniOglas(string v, string k, string n, double c, Datum *datum) : Oglas(n, c, datum), vrsta(v), kraj(k) {
	/*this->vrsta = vrsta;
	this->kraj = kraj;
	this->naslov = naslov;
	this->cena = cena;
	datumObjave = datum;*/
}

TuristicniOglas::TuristicniOglas(string kraj) {
	this->kraj = kraj;
	vrsta = "Apartma";
	naslov = "TuristicniOglas";
	cena = 400;
	datumObjave = new Datum(29,1,2013); //naslov, cena, datum
}

TuristicniOglas::TuristicniOglas(TuristicniOglas &tOglas) : Oglas(tOglas.naslov, tOglas.cena, tOglas.datumObjave) {
	vrsta = tOglas.vrsta;
	kraj = tOglas.kraj;
}

string TuristicniOglas::getKraj() const
{
    return kraj;
}

string TuristicniOglas::getVrsta() const
{
    return vrsta;
}

void TuristicniOglas::setKraj(string kraj)
{
    this->kraj = kraj;
}

void TuristicniOglas::setVrsta(string vrsta)
{
    this->vrsta = vrsta;
}

TuristicniOglas::~TuristicniOglas() {

}

string TuristicniOglas::toString() const {
	stringstream ss;
	//ss << Oglas::toString() << endl;
	ss << "Vrsta: " << vrsta << endl;
	ss << "Kraj: " << kraj << endl;

	return ss.str();
}

bool TuristicniOglas::primerjaj(TuristicniOglas &drugi) const {
	if(this->toString().compare(drugi.toString()) == 0)
		return true;
	else
		return false;
}
