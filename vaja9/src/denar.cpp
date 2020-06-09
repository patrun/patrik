#include "denar.h"

#include <sstream>
#include <cmath>

Denar::Denar() {
	vrednost = 1;
	vrstoValute = Valuta("EUR", 1);
}

Denar::Denar(int vrednost) {
	this->vrednost = vrednost;
	vrstoValute = Valuta("EUR", 1);
}

Denar::Denar(int vrednost, Valuta valuta) : vrstoValute(valuta) {
	this->vrednost = vrednost;
}

int Denar::getVrednost() const {
    return vrednost;
}

Valuta Denar::getVrstoValute() const {
    return vrstoValute;
}

void Denar::setVrednost(int vrednost) {
    this->vrednost = vrednost;
}

void Denar::setVrstoValute(Valuta vrstoValute) {
    this->vrstoValute = vrstoValute;
}

Denar::~Denar() {

}

string Denar::toString() const {
	stringstream ss;
	ss << vrednost << " (" << vrstoValute.getIme() << ")";

	return ss.str();
}

Denar Denar::operator-(Denar &drugi) const {
	Denar tmp = Denar(abs(vrednost/vrstoValute.getFaktorPretvorbe() - drugi.vrednost/drugi.vrstoValute.getFaktorPretvorbe()));

	return tmp;
}

Denar Denar::operator*(Denar &drugi) const {
	Denar tmp = Denar(abs(vrednost/vrstoValute.getFaktorPretvorbe() * drugi.vrednost/drugi.vrstoValute.getFaktorPretvorbe()));

	return tmp;
}

bool Denar::operator<(Denar &drugi) const {
	return (vrednost/vrstoValute.getFaktorPretvorbe()<drugi.vrednost/drugi.vrstoValute.getFaktorPretvorbe());
}

