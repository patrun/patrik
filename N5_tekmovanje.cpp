#include <iostream>
#include <stdio.h> 
#include <time.h>
#include <stdlib.h>
using namespace std;

void random(int a[5][5]){
	
	
	srand(time(NULL));
	
	for(int i=0;i<5;i++){
		for(int j=1;j<4;j++){
			a[i][0]=i+1;
			a[i][j]=rand()%10+1;
		}
	}
	for(int i=0;i<5;i++){
		cout<<a[i][0]<<". ";
		for(int j=1;j<4;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
		
	}
}

void uredi(int a[5][5]){
	
	
	int d;
	for(int i=0;i<5;i++){
		a[i][4]=a[i][1]+a[i][2]+a[i][3];
	}
	for(int p=0;p<4;p++){
	for(int i=0;i<4;i++){
		if(a[i][4]<a[i+1][4]){
		for(int j=0;j<5;j++){	
				d=a[i][j];
				a[i][j]=a[i+1][j];
				a[i+1][j]=d;
			}
		}
	}
	}
	
	for(int i=0;i<5;i++){
		cout<<a[i][0]<<". ";
		for(int j=1;j<5;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
		
	}
}

int main(){

	int polje[5][5];
	
	random(polje);
	cout<<endl;
	uredi(polje);
	cout<<endl<<"2. uvrsceni je bil tekmovalec: "<<endl;
	cout<<polje[1][0]<<". ";
	for(int i=1;i<5;i++){
		cout<<polje[1][i]<<" ";
	}
	return 0;

}
