#ifndef LIMITNIRACUN_H_
#define LIMITNIRACUN_H_

#include "Racun.h"

#include <string>
using namespace std;

class LimitniRacun : public Racun {
	protected:
		double limit;
	public:
		LimitniRacun();
		LimitniRacun(double limit, string ime_osebe, double stanje);
		LimitniRacun(LimitniRacun &lr);
		~LimitniRacun();
		double getLimit() const;
		void setLimit(double limit);
		double dvig(double vsota);
};

#endif /* LIMITNIRACUN_H_ */
