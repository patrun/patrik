#include "Oglas.h"
using namespace std;

#ifndef STANOVANJE_H_
#define STANOVANJE_H_

class Stanovanje : public Oglas {
	private:
		string hisniNaslov;
		int hisnaSt;
		int stSob;
	public:
		Stanovanje();
		Stanovanje(string hisniNaslov, int hisnaSt, int stSob);
		Stanovanje(int stSob);
		Stanovanje(Stanovanje &s);
		~Stanovanje();
		int getHisnaSt() const;
		string getHisniNaslov() const;
		int getStSob() const;
		void setHisnaSt(int hisnaSt);
		void setHisniNaslov(string hisniNaslov);
		void setStSob(int stSob);
		string toString() const;
		bool primerjaj(Stanovanje &drugi) const;
};

#endif /* STANOVANJE_H_ */
