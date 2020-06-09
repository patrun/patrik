#ifndef EXCEPTIONHANDLER_H_
#define EXCEPTIONHANDLER_H_

#include <iostream>
#include <string>
using namespace std;

class ExceptionHandler {
	private:
		string sporocilo;
	public:
		ExceptionHandler();
		ExceptionHandler(string sporocilo);
		~ExceptionHandler();
		void print() const;
};

#endif
