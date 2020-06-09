#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <new>
using namespace std;

struct izp{
	string ime;
	double mera;
	double znesek;
	int mesec;
	double kred;
};

void vnos(int n, izp *polje){	

	string ime;
	int mesec;
	double mera, znesek;
	
	for(int i=0; i<n; i++){
		
		cout<<"Vnesi ime izposojevalnice "<<i+1<<endl;
		cin>>ime;
		cout<<"Vnesi obrestno mero izposojevalnice "<<i+1<<endl;
		cin>>mera;
		cout<<"Vnesi znesek kredita izposojevalnice "<<i+1<<endl;
		cin>>znesek;
		cout<<"Vnesi trajanje kredita v mesecih izposojevalnice "<<i+1<<endl;
		cin>>mesec;
		
		polje[i].ime = ime;
		polje[i].mera = mera;
		polje[i].znesek = znesek;
		polje[i].mesec = mesec;
		
	}
}

double izracun(double kred, double mera, int mes){
	double rez;
	
	if(mes==0)
	return kred;
	else
	return (1+mera/100)*izracun(kred,mera,mes-1);
}

void write(izp *polje,int n){
	
	
	ofstream dat ("nekaj.txt");
	dat<<	"Podatki o izposojevalnicah \n\n";
			for(int i=0;i<n;i++){
			dat<<i+1<<". Izposojevalnica \nIme: "<<polje[i].ime<<"\n"
			"Cena kredita: "<<polje[i].kred<<"€\n"
			"Trajanje kredita : "<<polje[i].mesec<<"\n"
			"Meseèni obrok kredita : "<<polje[i].kred/polje[i].mesec<<"€\n"
			"Razlika med plaèanem in najet kreditu je: "<<polje[i].kred-polje[i].znesek<<"€\n\n";
			
			}
			
	dat.close();
}


int main(){
	izp *polje;
	int n=0;
	double rez;
	
	cout<<"Vnesite stevilo izposojevalnic ";
	cin>>n;
	
	//rezerviranje pomnilnika za polje
	polje = new izp[n];
	
	//vnos podatkov
	vnos(n, polje);
	
	//izraèun kreditov
	for(int i=0; i<n; i++){
		polje[i].kred = izracun(polje[i].znesek,polje[i].mera,polje[i].mesec);
		cout<< "Izposojevalnica " << i+1 << " znesek kredita: "<<polje[i].kred<<endl; 
	}
	//pisanje v datoteko
	write(polje,n);
	
	
	//sprostitev pomnilnika
	delete [] polje;
	
	return 0;
}
