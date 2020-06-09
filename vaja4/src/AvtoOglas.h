#include "Oglas.h"
using namespace std;

#ifndef AVTOOGLAS_H_
#define AVTOOGLAS_H_

class AvtoOglas : public Oglas {
	private:
		string model;
		string proizvajalec;
		int letnik;
	public:
		AvtoOglas();
		AvtoOglas(string model, string proizvajalec, int letnik);
		AvtoOglas(string naslov, Datum *datumObjave, double cena, string proizvajalec, string model, int letnik);
		AvtoOglas(AvtoOglas &ao);
		~AvtoOglas();
		int getLetnik() const;
		string getModel() const;
		string getProizvajalec() const;
		void setLetnik(int letnik);
		void setModel(string model);
		void setProizvajalec(string proizvajalec);
		bool primerjaj(AvtoOglas &drugi) const;
		string toString() const;
};

#endif /* AVTOOGLAS_H_ */
