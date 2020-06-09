#include <sstream>
#include "avto.h"
using namespace std;

Avto::Avto() {
	proizvajalec = model = "Prazno";
	letnik = 2013;
}

Avto::Avto(string proizvajalec, string model, int letnik) {
	this->proizvajalec = proizvajalec;
	this->model = model;
	this->letnik = letnik;
}

Avto::Avto(Avto *&avto) {
	this->letnik = avto->letnik;
	this->model = avto->model;
	this->proizvajalec = avto->proizvajalec;
}

void Avto::setLetnik(int letnik) {
	this->letnik = letnik;
}

void Avto::setProizvajalec(string proizvajalec) {
	this->proizvajalec = proizvajalec;
}

void Avto::setModel(string model) {
	this->model = model;
}

int Avto::getLetnik() const {
	return letnik;
}

string Avto::getProizvajalec() const{
	return proizvajalec;
}

string Avto::getModel() const {
	return model;
}

string Avto::toString() const {
	stringstream ss;
	ss << "Proizvajalec: " << proizvajalec << ", Model: " << model << ", Letnik: " << letnik;
	return ss.str();
}

ostream& operator<<(ostream &out, Avto avto) {
	out << "Proizvajalec: " << avto.proizvajalec << ", Model: " << avto.model << ", Letnik: " << avto.letnik;
	return out;
}
