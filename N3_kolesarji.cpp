#include <iostream>
using namespace std;

int main(){
	
	double hitrost[6];
	double trajanje[6];
	double dolzina_poti;
	double manjkajoca_pot[6];
	double odt[6], a[6];
	int n;
	
	cout<<"Vnesi dolzino proge v metrih: ";
	cin>>dolzina_poti;
	
	
	for(int b=1;b<=5;b++){
	
		cout<<"Vnesi hitrost voznje tekmovalca "<<b<<" v m/s: ";
		cin>>hitrost[b];
		
		cout<<"Vnesi cas voznje tekmovalca "<<b<<" v sekundah: ";
		cin>>trajanje[b];
				
		manjkajoca_pot[b] = dolzina_poti - trajanje[b] * hitrost[b];
		odt[b]=manjkajoca_pot[b]/dolzina_poti*100;
		a[b]=100-odt[b];
		
	}
	
	cout<<"Vnesite stevilo izrisov";
	cin>>n;
	
	
	for(int b=1;b<=5;b++){
				
		cout<<"Tekmovalec "<<b<<" ("<<a[b]<<"%)"<<endl;
		
		for(int m=1;m<=n;m++){
			
			for(int d=0;d<a[b];d++){
				cout<<"*";
			}
			for(int f=0;f<odt[b];f++){
				cout<<".";
			}
			cout<<endl;
		}
		cout<<endl;
		
	}
	
		
	
	return 0;
	
}
