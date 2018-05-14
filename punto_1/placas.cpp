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

//float **Vforw = new float*[dim];
float **V = new float*[dim];
float **Ex = new float*[dim];
float **Ey = new float*[dim];


for(int i=0;i<dim;i++)
{
	//Vforw[i]=new float[dim];
	V[i]= new float[dim];
	Ex[i]= new float[dim];
	Ey[i]= new float[dim];
	
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
		
		Ex[i][j]=0.0;
		Ey[i][j]=0.0;
	}
	
}

//Calcula los valores de V

//for(int k=0;k<N;k++)
//{
	for (int i=1;i<dim-1;i++)
	{
		for (int j=1;j<dim-1;j++)
		{
			V[i][j]=(V[i][j+1]+V[i-1][j]+V[i][j-1]+V[i+1][j])/4.0;
			Ex[i][j]=-(V[i+1][j]-V[i-1][j])/(2.0*h);
			Ey[i][j]=-(V[i][j+1]-V[i][j-1])/(2.0*h);	

			cout<<V[i][j]<<","<<Ex[i][j]<<","<<Ey[i][j]<<endl;

		}
	}
//}






return 0;
}

