#ifndef RACUNALNIKOGLAS_H_
#define RACUNALNIKOGLAS_H_

#include "Oglas.h"

class RacunalnikOglas : public Oglas {
	private:
		string vrsta;
		int starost;
		string ohranjenost;
	public:
		RacunalnikOglas();
		RacunalnikOglas(string vrsta, int starost, string ohranjenost, string n, int c, Datum *datum);
		RacunalnikOglas(RacunalnikOglas &ro);
		~RacunalnikOglas();
		string getOhranjenost() const;
		int getStarost() const;
		string getVrsta() const;
		void setOhranjenost(string ohranjenost);
		void setStarost(int starost);
		void setVrsta(string vrsta);
		string toString() const;
		bool primerjaj(RacunalnikOglas &drugi) const;
};

#endif /* RACUNALNIKOGLAS_H_ */
