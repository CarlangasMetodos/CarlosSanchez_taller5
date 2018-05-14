#include <iostream>
#include <math.h>

using namespace std;




int main()
{

float L=5.0;
float l=2.0;
float d=1.0;
float h=5.0/512.0;
float V0=100.0;
int N=2.0*pow((L/h),2);
int dim=L/h;

float **Vforw = new float*[dim];
float **V = new float*[dim];

for(int i=0;i<dim;i++)
{
	Vforw[i]=new float[dim];
	V[i]= new float[dim];
}


//Condiciones iniciales para el potencial entre las placas

for (int i=0;i<dim;i++)
{
	for (int j=0;j<dim;j++)
	{
		if(i>=154 && i<=359 && j==307)
		{ V[i][j] = V0/2.0; }
		
		if(i>=154 && i<=359 && j==205)
		{ V[i][j] = -V0/2.0; }
		
		if(i>=154 && i<=359 && j>205 && j<307)
		{ V[i][j] = V0; }
			
		else
		{ V[i][j] = 0.0; }

	//cout<<V[i][j]<<endl;
	}
	
}


for(int k=0;k<N;k++)
{
	for (int i=1;i<dim;i++)
	{
		for (int j=1;j<dim;j++)
		{

		Vforw[i][j]=4.0*V[i][j]-V[i+1][j]-V[i-1][j]-V[i][j-1];

		V[i][j]=Vforw[i][j];
		
		cout<<V[i][j]<<endl;
		}
	}
}

//Falta calcular el campo electrico, hacer los plots con cada uno y el makefiles





return 0;
}

