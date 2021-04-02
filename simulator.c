#include <stdio.h>
#include <stdlib.h>
#define k 9000000000
#define G 0.00000000006674
#include <math.h>
#include <time.h>
int main() 
{

	double msec;
	int b;
	clock_t before = clock();

	//starting simulation part
	double q1, q2, r, m1, m2, someconstant1, someconstant2, s1, s2, s3, s4, a1, a2, position1=0, position2=1, u1=0, u2=0, t=0.00001, p1, p2, v;
	printf("enter value of charge  of first particle , charge of second particle , distance between them , mass of first particle and mass of second particle (warning:-please put values in order or it may give wrong results also keep in mind that input is less than 6 digit and if your value is more or less than that you may use other unit and output will also be in that also keep in mind that the distance which will come out would be relative to the point in between them)\n");
	scanf("%lf %lf %lf %lf %lf",&q1,&q2,&r,&m1,&m2);
	someconstant1=(k*q1*q2+G*m1*m2)/(m1);
	someconstant2=(k*q1*q2+G*m1*m2)/(m2);
	for(msec=0;position1<position2;)
	{
    	clock_t difference = clock() - before;
    	msec = difference * 1000 / CLOCKS_PER_SEC;
    	b=msec/1000;
    	u1=u1+someconstant1*t/(r*r);
		u2=u2+someconstant2*t/(r*r);
	    a1=someconstant1/(r*r);
		s1=u1*t+1/2*a1*t*t;
		a2=someconstant2/(r*r);
		s2=u2*t+1/2*a2*t*t;
		position1=s1-r/2;
		position2=r/2-s2;
   		{
   			system("cls");
			printf("\nobject1:- \npostion:- %lf\nvelocity:- %lf\ntime:- %lf\n",position1,u1,t);
			printf("\nobject2:- \npostion:- %lf\nvelocity:- %lf\ntime:- %lf\n",position2,u2,t);
			printf("\ntime done: %d\n",b);
		}
   		s3=s3+s1;
		s4=s4+s2;
		r=r-s1-s2;
		t=t+0.00001;		
	}
	printf("\nthe particles have crossed each others path or went through each other or just had a collision at t= %lf last position value we got was %lf of object 1 and %lf of object 2 with %lf time being passed since programn excuted",t,position1,position2,b);
	return 0;
}
