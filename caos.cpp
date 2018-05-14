#include <iostream>
#include <math.h>

using namespace std;

const float E=0.001;
float dq1(float p1);
float dq2(float p2);
float dp1(float q1);
float dp2(float q1, float q2);

int main() {

float dt=0.006;
int t=3000;
float a=1.0/(2.0*sqrt(2.0));
int dim=t/dt;

float *q1= new float[dim];
float *p1= new float[dim];
float *q2= new float[dim];
float *p2= new float[dim];

float k1_q1,k2_q1,k3_q1,k4_q1,q1new;
float k1_q2,k2_q2,k3_q2,k4_q2,q2new;
float k1_p1,k2_p1,k3_p1,k4_p1,p1new;
float k1_p2,k2_p2,k3_p2,k4_p2,p2new;

//Metodo de Runge-Kutta 4th order 


for(int i=0;i<t;i++){

q1[0]=a;
q2[0]=-a;
p1[0]=0.0;
p2[0]=0.0;


//Para q1

k1_q1=dq1(p1[i]);
k2_q1=dq1(p1[i]+dt*k1_q1/2.0);
k3_q1=dq1(p1[i]+dt*k2_q1/2.0);
k4_q1=dq1(p1[i]+dt*k3_q1);

q1new=q1[i]+(dt*(k1_q1+2.0*k2_q1+2.0*k3_q1+k4_q1)/6.0);

//Para q2

k1_q2=dq2(p2[i]);
k2_q2=dq2(p2[i]+dt*k1_q2/2.0);
k3_q2=dq2(p2[i]+dt*k2_q2/2.0);
k4_q2=dq2(p2[i]+dt*k3_q2);

q2new=q2[i]+(dt*(k1_q2+2.0*k2_q2+2.0*k3_q2+k4_q2)/6.0);

//Para p1

k1_p1=dp1(q1[i]);
k2_p1=dp1(q1[i]+dt*k1_p1/2.0);
k3_p1=dp1(q1[i]+dt*k2_p1/2.0);
k4_p1=dp1(q1[i]+dt*k3_p1);

p1new=p1[i]+(dt*(k1_p1+2.0*k2_p1+2.0*k3_p1+k4_p1)/6.0);

//Para p2

k1_p2=dp2(q1[i],q2[i]);
k2_p2=dp2(q1[i]+dt*k1_p2/2.0,q2[i]+dt*k1_p2/2.0);
k3_p2=dp2(q1[i]+dt*k2_p2/2.0,q2[i]+dt*k2_p2/2.0);
k4_p2=dp2(q1[i]+dt*k3_p2,q2[i]+dt*k3_p2);

p2new=p2[i]+(dt*(k1_p1+2.0*k2_p1+2.0*k3_p1+k4_p1)/6.0);


//Condicion dada de impresiones

if((q1[i]<0.0 && q1new>0.0) || (q1[i]>0.0 && q1new<0.0))
{ cout<< q2[i] << "," << p2[i] << endl; }

else{
cout<<q1[i]<<","<<q2[i] <<","<< p1[i] <<","<< p2[i]<<endl;}

//Actualizar los valores

q1[i]=q1new;
q2[i]=q2new;
p1[i]=p1new;
p2[i]=p2new;

dt=dt*i;
}

return 0;
}


float dq1(float p1)
{ return p1; }

float dq2(float p2)
{ return p2; }

float dp1(float q1)
{ 
	float value=-(2.0*q1)/pow(4.0*pow(q1,2)+(pow(E,2)/4.0),1.5);
	return value;
}

float dp2(float q1, float q2)
{
	float a=q1-q2;
	float b=q1+q2;
	float part1=a/pow(pow(a,2)+(pow(E,2)/4.0),1.5);
	float part2=b/pow(pow(b,2)+(pow(E,2)/4.0),1.5);
	
	float value=part1-part2;
	return value;
}











