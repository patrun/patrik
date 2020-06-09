#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

template <typename T = string>
class Tabela {
	private:
		static int zaporednoSteviloObjekta;
		string ime;
		vector<T> seznam;
	public:
		Tabela() {
			zaporednoSteviloObjekta += 1;
			ime = "privzeto";
		}

		Tabela(string ime) {
			zaporednoSteviloObjekta += 1;
			this->ime = ime;
		}

		~Tabela() {
			/*for(int i=0; i<seznam.size(); i+=1)
				delete seznam[i];*/

			seznam.clear();
		}

		void dodaj(T objekt) {
			seznam.push_back(objekt);
		}

		bool brisiX(unsigned int x) {
			if(x<seznam.size()) {
				seznam.erase(seznam.begin()+x);
				return true;
			}
			else
				return false;
		}

		T getX(int x) {
			return seznam.at(x);
		}

		int size() {
			return seznam.size();
		}

		vector<T> vrniSode() {
			vector<T> tmp;
			cout << seznam.size() << endl;

			for(unsigned int i=0; i<seznam.size(); i+=2)
				tmp.push_back(seznam[i]);

			return tmp;
		}

		list<T> vrniLihe() {
			list<T> tmp;

			for(unsigned int i=1; i<seznam.size(); i+=2)
				tmp.push_back(seznam[i]);

			return tmp;
		}
};

class NoviRazred {
	private:
		string ime;
		int maxStObjektov;
	public:
		NoviRazred() {
			ime = "NoviRazred";
			maxStObjektov = 10;
		}

		NoviRazred(string ime, int maxSt) {
			this->ime = ime;
			maxStObjektov = maxSt;
		}

		~NoviRazred() {

		}

		string getIme() const {
			return ime;
		}

		int getMaxStObjektov() const {
			return maxStObjektov;
		}
};

template <typename T>
int Tabela<T>::zaporednoSteviloObjekta = 0;

int main() {
	Tabela<NoviRazred*> *ena = new Tabela<NoviRazred*>("NoviRazred");
	ena->dodaj(new NoviRazred("prvi", 10));
	ena->dodaj(new NoviRazred("drugi", 20));
	ena->dodaj(new NoviRazred("tretji", 33));
	ena->dodaj(new NoviRazred("cetrti", 42));
	ena->dodaj(new NoviRazred("peti", 59));
	ena->dodaj(new NoviRazred("sesti", 66));

	cout << "Velikost vektorja: " << ena->size() << endl;
	cout << "Element na 4. mestu: " << ena->getX(3)->getIme() << " " << ena->getX(3)->getMaxStObjektov() << endl;

	vector<NoviRazred*> s = ena->vrniSode();
	list<NoviRazred*> l = ena->vrniLihe();

	cout << endl;

	for(unsigned int i=0; i<s.size(); i+=1)
		cout << s[i]->getIme() << endl;

	cout << endl;

	for(unsigned int i=0; i<l.size(); i+=1) {
		cout << l.front()->getIme() << endl;
		l.pop_front();
	}

	ena->brisiX(3);

	cout << endl;

	for(int i=0; i<ena->size(); i+=1)
		cout << ena->getX(i)->getIme() << " " << ena->getX(i)->getMaxStObjektov() << endl;

	return 0;
}
