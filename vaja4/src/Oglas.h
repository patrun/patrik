#ifndef OGLAS_H_
#define OGLAS_H_

#include <iostream>
#include "Datum.h"
using namespace std;

class Oglas {
	protected:
		string naslov;
		Datum *datumObjave;
		double cena;
	public:
		Oglas();
		Oglas(string naslov, double cena, Datum *datumObjave);
		Oglas(Oglas &o);
		Oglas(string naslov);
		virtual ~Oglas();
		double getCena() const;
		Datum *getDatumObjave() const;
		string getNaslov() const;
		void setCena(double cena);
		void setDatumObjave(Datum *datumObjave);
		void setNaslov(string naslov);
		virtual string toString() const;
		virtual bool primerjaj(Oglas &drugi) const;
};

#endif /* OGLAS_H_ */
//turistièni - apartma, soba; kraj
