// avto.h
#include <string>
using namespace std;

#ifndef AVTO_H_INCLUDED
#define AVTO_H_INCLUDED

class Avto {
	private:
		string proizvajalec, model;
		int letnik;
	public:
		Avto();
		Avto(Avto *&avto);
		Avto(string proizvajalec, string model, int letnik);
		void setProizvajalec(string proizvajalec);
		void setModel(string model);
		void setLetnik(int letnik);
		string getProizvajalec() const;
		string getModel() const;
		int getLetnik() const;
		string toString() const;

		friend ostream& operator<<(ostream &out, Avto avto);
};
#endif /* AVTO_H_INCLUDED */
