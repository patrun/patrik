#include "Datum.h"

Datum::Datum() {
	dan = mesec = leto = 0;
}

Datum::Datum(int dan, int mesec, int leto) {
	this->dan = dan;
	this->mesec = mesec;
	this->leto = leto;
}

int Datum::getDan() const
{
    return dan;
}

int Datum::getLeto() const
{
    return leto;
}

int Datum::getMesec() const
{
    return mesec;
}

void Datum::setDan(int dan)
{
    this->dan = dan;
}

void Datum::setLeto(int leto)
{
    this->leto = leto;
}

void Datum::setMesec(int mesec)
{
    this->mesec = mesec;
}

Datum::~Datum() {
	// TODO Auto-generated destructor stub
}

