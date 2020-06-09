#include "exceptionHandler.h"

ExceptionHandler::ExceptionHandler() {
	// TODO Auto-generated constructor stub
}

ExceptionHandler::~ExceptionHandler() {
	// TODO Auto-generated destructor stub
}

ExceptionHandler::ExceptionHandler(string sporocilo) {
	this->sporocilo = sporocilo;
}

void ExceptionHandler::print() const {
	cout << sporocilo << endl;
}
