#ifndef DENAR_H_INCLUDED
#define DENAR_H_INCLUDED

#include "valuta.h"

class Denar {
	private:
		int vrednost;
		Valuta vrstoValute;
	public:
		Denar();
		Denar(int vrednost);
		Denar(int vrednost, Valuta valuta);
		~Denar();
		int getVrednost() const;
		Valuta getVrstoValute() const;
		void setVrednost(int vrednost);
		void setVrstoValute(Valuta vrstoValute);
		string toString() const;
		Denar operator-(Denar &drugi) const;
		Denar operator*(Denar &drugi) const;
		bool operator<(Denar &drugi) const;
};

#endif /* DENAR_H_INCLUDED */
