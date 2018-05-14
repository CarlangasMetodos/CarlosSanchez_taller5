#include <iostream>
#include <math.h>

using namespace std;



int main(){

float L=100.0;
float p=10.0;
float T=40.0;
float c=sqrt(T/p);
int t_max=200;

float dx=1.0;
float dt=1.0;

float **U= new float*[t_max];
float **Uforw= new float*[t_max];

float x;
float t;

float alpha=pow(dx/(c*dt),2);

for(int i=0; i<L;i++){

	x=dx*i;	
				
	if(x<=0.8*L) { U[i][0]=1.25*x/L; }

	else { U[i][0]=5.0-(5.0*x/L); }
}					

for(int i=1; i<L; i++){
	for(int j=1; j<t_max;j++){

		Uforw[i][j]=alpha*(U[i][j+1]-2.0*U[i][j]+U[i][j-1])+2.0*U[i][j]-U[i-1][j];

		cout<<U[i][j]<<endl;

		U[i][j]=Uforw[i][j];
	}
}







return 0;
}
