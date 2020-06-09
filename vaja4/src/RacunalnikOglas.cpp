#include "RacunalnikOglas.h"

#include <sstream>

RacunalnikOglas::RacunalnikOglas() : Oglas() {
	vrsta = "Laptop";
	starost = 3;
	ohranjenost = "V dobri kondiciji";
}

RacunalnikOglas::RacunalnikOglas(string vrsta, int starost, string ohranjenost, string n, int c, Datum *datum) : Oglas(n, c, datum) {
	this->vrsta = vrsta;
	this->starost = starost;
	this->ohranjenost = ohranjenost;
}

RacunalnikOglas::RacunalnikOglas(RacunalnikOglas &ro) : Oglas(ro.naslov, ro.cena, ro.datumObjave) {
	vrsta = ro.vrsta;
	starost = ro.starost;
	ohranjenost = ro.ohranjenost;
}

string RacunalnikOglas::getOhranjenost() const
{
    return ohranjenost;
}

int RacunalnikOglas::getStarost() const
{
    return starost;
}

string RacunalnikOglas::getVrsta() const
{
    return vrsta;
}

void RacunalnikOglas::setOhranjenost(string ohranjenost)
{
    this->ohranjenost = ohranjenost;
}

void RacunalnikOglas::setStarost(int starost)
{
    this->starost = starost;
}

void RacunalnikOglas::setVrsta(string vrsta)
{
    this->vrsta = vrsta;
}

string RacunalnikOglas::toString() const {
	stringstream ss;
	//ss << Oglas::toString() << endl;
	ss << "Naslov: " << naslov << endl;
	ss << "Datum objave: " << datumObjave->getDan() << "." << datumObjave->getMesec() << "." << datumObjave->getLeto() << endl;
	ss << "Cena: " << cena << endl;
	ss << "Vrsta: " << vrsta << endl;
	ss << "Starost: " << starost << endl;
	ss << "Ohranjenost: " << ohranjenost << endl;

	return ss.str();
}

bool RacunalnikOglas::primerjaj(RacunalnikOglas &drugi) const {
	if(this->toString().compare(drugi.toString()) == 0)
		return true;
	else
		return false;
}

RacunalnikOglas::~RacunalnikOglas() {

}

