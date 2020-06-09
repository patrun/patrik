#ifndef RACUN_H_
#define RACUN_H_

#include <string>
using namespace std;

class Racun {
	protected:
		string ime_osebe;
		double stanje;
	public:
		Racun();
		Racun(string ime_osebe, double stanje);
		Racun(Racun &r);
		virtual ~Racun();
		string getImeOsebe() const;
		double getStanje() const;
		void setImeOsebe(string imeOsebe);
		void setStanje(double stanje);
		virtual string toString() const;
		virtual void polog(double kolicina);
		virtual double dvig(double vsota);
};

#endif /* RACUN_H_ */
