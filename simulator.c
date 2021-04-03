#include <stdio.h>
#include <stdlib.h>
#define k 9000000000
#define G 0.00000000006674
#include <math.h>
#include <time.h>
#include <conio.h>
#include <windows.h>
#include <graphics.h>
#include <unistd.h>
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGNETA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"
int main() 
{
	lol:
	double msec;
	int a,b,c,d,e;
	int iterations;
	clock_t before = clock();
	//starting simulation part
	double q1, q2, r, m1, m2, someconstant1, someconstant2, s1, s2, s3, s4, a1, a2, position1=0, position2=1, u1=0, u2=0, t=0, t1, p1, p2, v;
	system("cls");
	printf(GREEN"WELCOME\npress some thing to continue");
	getch();
	system("cls");
	printf("press 1 for default system \npress 2 to manualy select all settings");
	scanf("%d",&e);
	if(e==2)
	{
		printf("please select text colour for interface ");
		printf("Sorry but this part of simulator is still in development press h to go to home");
		if(kbhit())
		{
			char ch=getch();
			if(ch=='h')
			{
				goto lol;
			}
		}
	}
	system("cls");
	printf("which forces do you want\npress 1 for only gravity\npress 2 for only electromagnetism\npress 3 for both\n");
	scanf("%d",&c);
	printf("%d",c);
	if(c==1)
	{
		system("cls");
		q1=0;
		q2=0;
		printf("plz enter mass of object1\n");
		scanf("%lf",&m1);
		printf("\nplz enter mass of object2\n");
		scanf("%lf",&m2);
	}
	if(c==2)
	{
		system("cls");
		m1=0;
		m2=0;
		printf("plz enter charge of object1\n");
		scanf("%lf",&q1);
		printf("\nplz enter charge of object2\n");
		scanf("%lf",&q2);	
	}
	if(c==3)
	{
		system("cls");
		printf("plz enter mass of object1\n");
		scanf("%lf",&m1);
		printf("\nplz enter mass of object2\n");
		scanf("%lf",&m2);
		printf("\nplz enter charge of object1\n");
		scanf("%lf",&q1);
		printf("\nplz enter charge of object2\n");
		scanf("%lf",&q2);
	}
	printf("\nplz enter distance between objects\n");
		scanf("%lf",&r);
		if(r<=100)
		t1=0.0000001;
		else if(r<=1000)
		t1=0.000001;
		else if(r<=10000)
		t1=0.00001;
		else if(r<=100000)
		t1=0.0001;
		else if(r<=1000000)
		t1=0.001;
		else if(r<=10000000)
		t1=0.01;
	someconstant1=(k*q1*q2+G*m1*m2)/(m1);
	someconstant2=(k*q1*q2+G*m1*m2)/(m2);
	for(msec=0;position1<position2;)
	{
		t=t+t1;
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
   			printf("%lf",t1);
			printf("\nobject1:- \npostion:- %lf\nvelocity:- %lf\ntime:- %lf\n",position1,u1,t);
			printf("\nobject2:- \npostion:- %lf\nvelocity:- %lf\ntime:- %lf\n",position2,u2,t);
			printf("\ntime done: %d\n",b);
			printf("press p to pause \ne to end  \npress h to go to home(remember this program will be executed)");
			if(kbhit()) {
				char ch=getch();
				if(ch=='p') {
				
				printf("simulation paused, press any key to continue");
				getch();
				}
				if(ch=='h')
				{
					goto lol;
				}
				if(ch=='e') 
				{
					printf("ending simulation in 10 seconds");
					system("cls");
					msec=0;
					for(a=0;a<10;iterations++)
					{
						clock_t difference = clock() - before;
    					msec = difference * 1000 / CLOCKS_PER_SEC;
    					a=msec/1000;
    					a=a-b;
						if(a!=d)
						{
							printf("ending simulation in %d seconds\n",a);	
						}
    					d=a;
					}
					return 0;
				}
			}
		}
			
			
		
   		s3=s3+s1;
		s4=s4+s2;
		r=r-s1-s2;	
	}
	printf("\nthe particles have crossed each others path or went through each other or just had a collision at t= %lf last position value we got was %lf of object 1 and %lf of object 2 with %lf time being passed since programn excuted",t,position1,position2,b);
	printf("press h to go to home page\npress e to exit");
	if(kbhit())
		{
			char ch=getch();
			if(ch=='h')
			{
				goto lol;
			}
			if(ch=='e')
			{
				return 0;
			}
		}
}
