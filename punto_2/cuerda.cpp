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
float dt=0.2;

float x;
float t;

float alpha=pow(dx/(c*dt),2);

int time=t_max/dt;
int distx=L/dx;

float **U= new float*[distx];
float **Uforw= new float*[distx];

for (int i=0;i<distx;i++)
{
	U[i]=new float[distx];
	Uforw[i]=new float[distx];
}

//Condiciones iniciales

for(int i=0; i<distx;i++){
	for(int j=0; j<time;j++){
	x=dx*i;	
				
	if(x<=0.8*L)
		 { U[i][0]=1.25*x/L; }

	else 
		{ U[i][0]=5.0-(5.0*x/L); }
	}
}					


//Solucion de la Ecuacion

for(int i=1; i<distx-1; i++){
	for(int j=1; j<time-1;j++){

		Uforw[i][j]=(alpha/(2.0*(alpha-1.0)))*(U[i][j+1]+U[i][j-1])-(1.0/(2.0*(alpha-1.0)))*(U[i+1][j]-U[i-1][j]);
		
		U[i][j]=Uforw[i][j];

	}
}

for(int i=1; i<distx-1; i++){
	for(int j=1; j<time-1;j++){
		double p=dx*i;

		cout<<p<<","<<U[i][j]<<endl;
	}
}

return 0;
}
