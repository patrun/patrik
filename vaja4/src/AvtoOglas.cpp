#include "AvtoOglas.h"
#include <sstream>
using namespace std;

AvtoOglas::AvtoOglas() : Oglas() {
	letnik = 0;
	proizvajalec = model = "neznano";
}

AvtoOglas::AvtoOglas(string model, string proizvajalec, int letnik) : Oglas() {
	this->model = model;
	this->proizvajalec = proizvajalec;
	this->letnik = letnik;
}

AvtoOglas::AvtoOglas(string naslov, Datum *datumObjave, double cena, string proizvajalec, string model, int letnik) : Oglas(naslov, cena, datumObjave) {
	this->model = model;
	this->proizvajalec = proizvajalec;
	this->letnik = letnik;
}

AvtoOglas::AvtoOglas(AvtoOglas &ao) : Oglas() {
	model = ao.model;
	proizvajalec = ao.proizvajalec;
	letnik = ao.letnik;
}

int AvtoOglas::getLetnik() const
{
    return letnik;
}

string AvtoOglas::getModel() const
{
    return model;
}

string AvtoOglas::getProizvajalec() const
{
    return proizvajalec;
}

void AvtoOglas::setLetnik(int letnik)
{
    this->letnik = letnik;
}

void AvtoOglas::setModel(string model)
{
    this->model = model;
}

void AvtoOglas::setProizvajalec(string proizvajalec)
{
    this->proizvajalec = proizvajalec;
}

AvtoOglas::~AvtoOglas() {

}

string AvtoOglas::toString() const {
	stringstream ss;
	/*ss << "Naslov: " << naslov << endl;
	ss << "Datum objave: " << datumObjave->getDan() << "." << datumObjave->getMesec() << "." << datumObjave->getLeto() << endl << endl;
	ss << "Cena: " << cena << endl;*/
	ss << Oglas::toString() << endl;
	ss << "Proizvajalec: " << proizvajalec << endl;
	ss << "Model: " << model << endl;
	ss << "Letnik: " << letnik << endl;

	return ss.str();
}

bool AvtoOglas::primerjaj(AvtoOglas &drugi) const {
	if(this->toString().compare(drugi.toString()) == 0)
		return true;
	else
		return false;
}

