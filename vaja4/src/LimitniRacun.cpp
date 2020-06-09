#include "LimitniRacun.h"

#include <iostream>
using namespace std;

LimitniRacun::LimitniRacun() {
	// TODO Auto-generated constructor stub
	limit = 0;
}

double LimitniRacun::getLimit() const
{
    return limit;
}

LimitniRacun::LimitniRacun(double limit, string ime_osebe, double stanje) : Racun(ime_osebe, stanje)
{
	this->limit = limit;
}

LimitniRacun::LimitniRacun(LimitniRacun & lr) : Racun(lr.ime_osebe, lr.stanje)
{
	limit = lr.limit;
}

void LimitniRacun::setLimit(double limit)
{
    this->limit = limit;
}


LimitniRacun::~LimitniRacun() {
	// TODO Auto-generated destructor stub
}

double LimitniRacun::dvig(double vsota)
{
	double s = stanje + limit;
	if(s<vsota) {
		cout << "Napaka." << endl;
	} else {
		Racun::dvig(s);
	}
}



