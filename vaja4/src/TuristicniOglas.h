#include "Oglas.h"

#ifndef TURISTICNIOGLAS_H_
#define TURISTICNIOGLAS_H_

class TuristicniOglas : public Oglas {
	private:
		string vrsta;
		string kraj;
	public:
		TuristicniOglas();
		TuristicniOglas(string v, string k, string n, double c, Datum *datum);
		TuristicniOglas(string kraj);
		TuristicniOglas(TuristicniOglas &tOglas);
		~TuristicniOglas();
		string getKraj() const;
		string getVrsta() const;
		void setKraj(string kraj);
		void setVrsta(string vrsta);
		string toString() const;
		bool primerjaj(TuristicniOglas &drugi) const;
};

#endif /* TURISTICNIOGLAS_H_ */
