#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct cas{
	int zac;
	int kon;
};

struct Naslov{
	string nas1;
	string nas2;
};

struct restavracija{
	string ime;
	Naslov naslov;
	cas odpiralni;
	int cena;
	double ocena;
};

void vnos(restavracija *polje[10]){
     string ime, naslov1, naslov2;
     int cena, zac, kon;
     double ocena;

    for(int i=0; i<10; i++){
    		polje[i] = new restavracija;
    		
    		cout<<i+1<<". restavracija "<<endl;
            cout<<"Vnesi ime restavracije "<<endl;
            cin>>ime;
            cout<<"Vnesi naslov restavracije "<<endl;
			cin>>naslov1;
			cin>>naslov2;
			cout<<"Vnesi zacetni odpiralni cas "<<endl;
			cin>> zac;
			cout<<"Vnesi koncni odpiralni cas"<<endl;
			cin>> kon;
			cout<<"Vnesi ceno bona "<<endl;
			cin>> cena;
			cout<<"Vnesi povprecno oceno med (0-5)"<<endl;
			cin>> ocena;

            polje[i]->ime = ime;
            polje[i]->naslov.nas1 = naslov1;
            polje[i]->naslov.nas2 = naslov2;
			polje[i]->odpiralni.zac = zac;
            polje[i]->odpiralni.kon = kon;
            polje[i]->cena = cena;
            polje[i]->ocena = ocena;
            cout<<endl;

    }
}

void izpis(restavracija *polje[10]){

     for(int i=0; i<10; i++){

            cout<<"Ime  "<<polje[i]->ime<<endl;
            cout<<"Naslov  "<<polje[i]->naslov.nas1<<" "<<polje[i]->naslov.nas2<<endl;
            cout<<"Odpiralni cas   "<<polje[i]->odpiralni.zac<<"h - "<<polje[i]->odpiralni.kon<<"h"<<endl;
            cout<<"Cena bona  "<<polje[i]->cena<<endl;
            cout<<"Povprecna ocena  "<< polje[i]->ocena<<endl<<endl;

    }
}

void oceni(restavracija *polje[10]){
    restavracija *d;

    for(int j=0;j<9;j++){
    for(int i=0; i<9; i++){
            if(polje[i]->ocena < polje[i+1]->ocena){
                              d = polje[i];
                              polje[i] = polje[i+1];
                              polje[i+1] = d;
            }
    }
    }
}

void ceni(restavracija *polje[10]){
    restavracija *d;

    for(int j=0;j<9;j++){
    for(int i=0; i<9; i++){
            if(polje[i]->cena < polje[i+1]->cena){
                              d = polje[i];
                              polje[i] = polje[i+1];
                              polje[i+1] = d;
            }
    }
    }
}

int main(){
	restavracija *polje[10];
	double p=0, r;

    vnos(polje);

	cout<<"Urejen izpis po povprecni oceni : "<<endl;
	oceni(polje);
	izpis(polje);

	cout<<"Urejen izpis po ceni : "<<endl;
	ceni(polje);
	izpis(polje);
	
	for(int j=0; j<10; j++){
		p=p+polje[j]->ocena;
	}
	r=p/10;
	cout<<"povprecje vseh ocen je "<<r<<endl;
	
	ofstream dat("tabela.html");
	dat<<"<html>";
	dat<<"<head>";
	dat<<"<meta http-equiv='Content-Type' content='text/html; charset=utf-8'>";
	dat<<"<title>Naloga N6: prehrana</title>";
	dat<<"<style>.a {background-color:#ffbbbb;}.b {background-color:#e0ffff;}.c {background-color:#aaaaff;}</style>";
	dat<<"</head>";
	dat<<"<body>";
	dat<<"<div class='c'>";
	dat<<"<span style='width:250px;display:table-cell;'>Ime restavracije</span>";
	dat<<"<span style='width:200px;display:table-cell;'>Naslov</span>";
	dat<<"<span style='width:100px;display:table-cell;'>Odpiralni èas med tednom</span>";
	dat<<"<span style='width:80px;display:table-cell;'>Cena bona</span>";
	dat<<"<span style='width:80px;display:table-cell;'>Povpreèna ocena</span>";
	dat<<"</div>";
	for(int i=0, st=1; i<10; st++, i++){
	
		if(st%2!=0)	{
			dat<<"<div class='a'>";
			dat<<"<span style='width:250px;display:table-cell;'>"<<polje[i]->ime<<"</span>";
			dat<<"<span style='width:200px;display:table-cell;'>"<<polje[i]->naslov.nas1<<" "<<polje[i]->naslov.nas2<<"</span>";
			dat<<"<span style='width:100px;display:table-cell;'>"<<polje[i]->odpiralni.zac<<"h - "<<polje[i]->odpiralni.kon<<"h</span>";
			dat<<"<span style='width:80px;display:table-cell;'>"<<polje[i]->cena<<"</span>";
			dat<<"<span style='width:80px;display:table-cell;'>"<<polje[i]->ocena<<"</span>";
			dat<<"</div>";
		}
		else{
			dat<<"<div class='b'>";
			dat<<"<span style='width:250px;display:table-cell;'>"<<polje[i]->ime<<"</span>";
			dat<<"<span style='width:200px;display:table-cell;'>"<<polje[i]->naslov.nas1<<" "<<polje[i]->naslov.nas2<<"</span>";
			dat<<"<span style='width:100px;display:table-cell;'>"<<polje[i]->odpiralni.zac<<"h - "<<polje[i]->odpiralni.kon<<"h</span>";
			dat<<"<span style='width:80px;display:table-cell;'>"<<polje[i]->cena<<"</span>";
			dat<<"<span style='width:80px;display:table-cell;'>"<<polje[i]->ocena<<"</span>";
			dat<<"</div>";
		}
	}
	dat<<"</body>";
	dat<<"</html>";
	dat.close();
	

	return 0;
}
