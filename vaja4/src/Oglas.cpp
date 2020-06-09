#include "Oglas.h"

#include <sstream>
using namespace std;

Oglas::Oglas() {
	naslov = "privzeto";
	datumObjave = new Datum(0,0,0);
	cena = 0;
}
Oglas::Oglas(string naslov, double cena, Datum *datumObjave) {
	this->naslov = naslov;
	this->cena = cena;
	this->datumObjave = datumObjave;
}

double Oglas::getCena() const
{
    return cena;
}

Datum *Oglas::getDatumObjave() const
{
    return datumObjave;
}

string Oglas::getNaslov() const
{
    return naslov;
}

void Oglas::setCena(double cena)
{
    this->cena = cena;
}

void Oglas::setDatumObjave(Datum *datumObjave)
{
    this->datumObjave = datumObjave;
}

Oglas::Oglas(Oglas &o)
{
	datumObjave = o.datumObjave;
	naslov = o.naslov;
	cena = o.cena;
}

Oglas::Oglas(string naslov)
{
	this->naslov = naslov;
	cena = 0;
	datumObjave = new Datum(29,3,2013);
}

void Oglas::setNaslov(string naslov)
{
    this->naslov = naslov;
}

Oglas::~Oglas() {
	delete datumObjave;
}

string Oglas::toString() const {
	stringstream ss;
	ss << "Naslov: " << naslov << endl;
	ss << "Datum objave: " << datumObjave->getDan() << "." << datumObjave->getMesec() << "." << datumObjave->getLeto() << endl;
	ss << "Cena: " << cena << "€" << endl;

	return ss.str();
}

bool Oglas::primerjaj(Oglas &drugi) const {
	if(this->toString().compare(drugi.toString()) == 0)
		return true;
	else
		return false;
}
