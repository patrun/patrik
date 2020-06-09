#include "valuta.h"

Valuta::Valuta() {
	ime = "EUR";
	faktorPretvorbe = 1;
}

Valuta::Valuta(string ime, double faktorPretvorbe) {
	this->ime = ime;
	this->faktorPretvorbe = faktorPretvorbe;
}

double Valuta::getFaktorPretvorbe() const {
    return faktorPretvorbe;
}

string Valuta::getIme() const {
    return ime;
}

void Valuta::setFaktorPretvorbe(double faktorPretvorbe) {
    this->faktorPretvorbe = faktorPretvorbe;
}

void Valuta::setIme(string ime) {
    this->ime = ime;
}

Valuta::~Valuta() {

}

