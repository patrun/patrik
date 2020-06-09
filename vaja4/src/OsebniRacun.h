#ifndef OSEBNIRACUN_H_INCLUDED
#define OSEBNIRACUN_H_INCLUDED

#include "LimitniRacun.h"

#include <string>
#include <vector>
using namespace std;

class OsebniRacun : public LimitniRacun {
	private:
		vector<string> seznam;
	public:
		OsebniRacun();
		//double dvig(double vsota);
		~OsebniRacun();
};

#endif
