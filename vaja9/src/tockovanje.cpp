#include "tockovanje.h"

Tockovanje::Tockovanje(string ime) {
	this->ime = ime;
	x = 0;
	y = 0;
}

Tockovanje::~Tockovanje() {

}

void Tockovanje::operator>>(int a) {
	y += a;
	cout << ime << ".y" << " pove�alo za " << a << endl;
}

void Tockovanje::operator<<(int a) {
	x += a;
	cout << ime << ".x" << " pove�alo za " << a << endl;
}

bool Tockovanje::operator==(Tockovanje& druga) {
	return (druga.x == x && druga.y == y);
}

void Tockovanje::operator--() { //prefix
	x -= 1;
	cout << ime << ".x" << " zmanj�alo za 1" << endl;
}

void Tockovanje::operator--(int a) { //postfix
	y -= 1;
	cout << ime << ".y" << " zmanj�alo za 1" << endl;
}
