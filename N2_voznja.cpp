#include <iostream>
using namespace std;

int main(){
	
	int hitrost;
	int trajanje;
	int dolzina_poti;
	int manjkajoca_pot;
	int odt;
	
	cout<<"Vnesi dolzino proge v metrih: ";
	cin>>dolzina_poti;
	
	cout<<"Vnesi hitrost voznje v m/s: ";
	cin>>hitrost;
	
	cout<<"Vnesi cas voznje v sekundah: ";
	cin>>trajanje;
	
	cout<<"Dolzina proge je "<<dolzina_poti<<endl;
	cout<<"Hitrost voznje je "<<hitrost<<endl;
	cout<<"Cas voznje je "<<trajanje<<endl;
	
	manjkajoca_pot = dolzina_poti - trajanje * hitrost;
	if(manjkajoca_pot >=0)
	cout<<"Preostale poti v metrih je se: "<<manjkajoca_pot<<endl;
	
	else 
	cout<<"Kolesar je ze mimo cilja"<<endl;
	

	
	
		
	
	return 0;
	
}
