#ifndef TOCKOVANJE_H_INCLUDED
#define TOCKOVANJE_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

class Tockovanje {
	private:
		string ime;
		int x;
		int y;
	public:
		Tockovanje(string ime);
		~Tockovanje();
		void operator>>(int a);
		void operator<<(int a);
		bool operator==(Tockovanje& druga);
		void operator--(); //prefix
		void operator--(int a); //postfix
};

#endif /* TOCKOVANJE_H_INCLUDED */
