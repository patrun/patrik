#ifndef VALUTA_H_INCLUDED
#define VALUTA_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

class Valuta {
	private:
		string ime;
		double faktorPretvorbe;
	public:
		Valuta();
		Valuta(string ime, double faktorPretvorbe);
		~Valuta();
		double getFaktorPretvorbe() const;
		string getIme() const;
		void setFaktorPretvorbe(double faktorPretvorbe);
		void setIme(string ime);
};

#endif /* VALUTA_H_INCLUDED */
