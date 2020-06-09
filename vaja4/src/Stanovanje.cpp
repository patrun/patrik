#include <sstream>
#include "Stanovanje.h"

using namespace std;

Stanovanje::Stanovanje() : Oglas() {
	//Oglas();
	stSob = hisnaSt = 0;
	hisniNaslov = "hisni naslov";
}

Stanovanje::Stanovanje(string hisniNaslov, int hisnaSt, int stSob) : Oglas() {
	this->hisniNaslov = hisniNaslov;
	this->hisnaSt = hisnaSt;
	this->stSob = stSob;
	//Oglas();
}

Stanovanje::Stanovanje(int stSob) : Oglas() {
	this->hisniNaslov = "hisni naslov";
	this->hisnaSt = 0;
	this->stSob = stSob;
	//Oglas("StanovanjeOglas", 200, new Datum(27,3,2013));
}

Stanovanje::Stanovanje(Stanovanje &s) {
	hisniNaslov = s.hisniNaslov;
	hisnaSt = s.hisnaSt;
	stSob = s.stSob;
	//Oglas(s.naslov, s.cena, s.datumObjave);
}

int Stanovanje::getHisnaSt() const
{
    return hisnaSt;
}

string Stanovanje::getHisniNaslov() const
{
    return hisniNaslov;
}

int Stanovanje::getStSob() const
{
    return stSob;
}

void Stanovanje::setHisnaSt(int hisnaSt)
{
    this->hisnaSt = hisnaSt;
}

void Stanovanje::setHisniNaslov(string hisniNaslov)
{
    this->hisniNaslov = hisniNaslov;
}

void Stanovanje::setStSob(int stSob)
{
    this->stSob = stSob;
}

Stanovanje::~Stanovanje() {

}

string Stanovanje::toString() const {
	stringstream ss;
	/*ss << "Naslov: " << naslov << endl;
	ss << "Datum objave: " << datumObjave->getDan() << "." << datumObjave->getMesec() << "." << datumObjave->getLeto() << endl << endl;
	ss << "Cena: " << cena << endl;*/
	//ss << Oglas::toString() << endl;
	ss << "Hisni naslov: " << hisniNaslov << " " << hisnaSt << endl;
	ss << "St. sob: " << stSob << endl;

	return ss.str();
}

bool Stanovanje::primerjaj(Stanovanje &drugi) const {
	if(this->toString().compare(drugi.toString()) == 0)
		return true;
	else
		return false;
}

