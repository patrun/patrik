#include "Racun.h"

#include <iostream>
#include <sstream>
#include <sstream>

using namespace std;

Racun::Racun() {
	stanje = 0;
	ime_osebe = "John Doe";
}

Racun::Racun(Racun &r) {
	stanje = r.stanje;
	ime_osebe = r.ime_osebe;
}

Racun::Racun(string ime_osebe, double stanje) {
	this->ime_osebe = ime_osebe;
	this->stanje = stanje;
}

string Racun::getImeOsebe() const
{
    return ime_osebe;
}

double Racun::getStanje() const
{
    return stanje;
}

void Racun::setImeOsebe(string imeOsebe)
{
    ime_osebe = imeOsebe;
}

void Racun::setStanje(double stanje)
{
    this->stanje = stanje;
}

string Racun::toString() const {
	stringstream ss;
	ss << "Ime osebe: " << ime_osebe << endl;
	ss << "Stanje: " << stanje << endl;

	return ss.str();
}

void Racun::polog(double kolicina) {
	stanje += kolicina;
}

double Racun::dvig(double vsota) {
	double s = stanje - vsota;
	if(s < 0) {
		cout << "Napaka. Vaše stanje je prenizko.";
	} else {
		stanje = s;
	}
}

Racun::~Racun() {
	// TODO Auto-generated destructor stub
}

