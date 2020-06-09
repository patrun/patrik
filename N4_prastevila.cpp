#include <iostream>
#include <cmath>
using namespace std;

void Prastevilo(int st,bool &pra_st)
{
	pra_st=false;
	
	if(st==0 || st==1)
		pra_st=true;
	
	else{
		for(int i=st-1; i>1; i--){
	
		if(st%i==0)
			pra_st=true;
		}
	}
	
}

void st_prastevil(int &x)
{
	for(int st=0;st<=9001;st++){
	bool pra_st=false;
	
	if(st==0 || st==1)
		pra_st=true;
	
	else if(st>1){
		for(int i=st-1; i>1; i--){
	
		if(st%i==0)
			pra_st=true;
		}
	}
	
	if(!pra_st){
		x++;
		}	
	}
}

int povprecna(int polje[], int a){
	
	int st=1, k;
	int f=0;
	
	for(int x=0;x<20;x++ ){
	for(;st<=20;){
	k=0;
	
		if(a==0 || a==1)
		k=1;
	
	else{
		for(int i=a-1; i>1; i--){
	
		if(a%i==0)
			k=1;
		}
	}
	
	if(k==0){
		polje[x]=a;
		st++;
		f=f+polje[x];
		
		}
	a++;
	}
	}
	
	return (f/20);
}

int main(){
	
	int st, x=0, b,c,d,f,g;
	bool pra_st;
	int polje[20];	
	
	cout<<"Vnesi stevilo : ";
	cin>>st;
	
	Prastevilo(st,pra_st);
	if(pra_st){
		cout<<"Stevilo "<<st<< " ni prastevilo"<<endl;
		}
	else{
		cout<<"Stevilo "<<st<< " je prastevilo"<<endl;
		}
	st_prastevil(x);
	cout<<"Prastevil od -217 do 9001 je : "<<x<<endl;
	cout<<"Vnesi stevilo : ";
	cin>>b;
	cout<<"Povprecje prvih 20 prastevil ki so vecja ali enaka stevilu "<<b<<" je "<<povprecna(polje,b)<<endl;
	cout<<"Vnesi stevilo : ";
	cin>>c;
	
	c = sqrt(c);
	if(c>polje[0])
		g=c-polje[0];
	else{
		g=polje[0]-c;
	}
	for(int j=0;j<20;j++){
	if(c>polje[j])
		d=c-polje[j];
	else{
		d=polje[j]-c;
	}
		if(g>d)
		{
			if(c>polje[j])
				g=c-polje[j];
			else{
				g=polje[j]-c;
			}
			
			f=polje[j];
		}
	}
	cout<<f;
	
	return 0;
}
