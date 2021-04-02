#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#include <setjmp.h>
int main ()
{
	system("color 0A");
	int msec = 0, trigger,a;
	int t,t1,t2,t3=0,x,b;
	printf("please enter how many sec timer u need\n");
	scanf("%d",&b);
    char c = 177, d = 219;	
	trigger=b*1000;
	clock_t before = clock();
	int iterations;
	do {
  	clock_t difference = clock() - before;
    msec = difference * 1000 / CLOCKS_PER_SEC;
    t=msec/1000;
	if(a!=t)
   	{
   	    system("cls");	
   		int i;
   		t1=(t*100)/b;
   		t2=t1/2;
 	    printf("\n\t\t\t\t\tLoading...\n");
   	    printf("\t\t\t\t\t");
	    for (i=0;i<50;i++)
	    {
	    	printf("%c",c);
		}
		printf("\r");
	    printf("\t\t\t\t\t");
	    for (i=0;i<t2;i++)
		{
			printf("%c", d);
		}
   		printf("\n\t\t\t\t\t%d percent",t1,t);
   		t3=t3+1;
    }
	    a=t;
	    iterations++;
	} while ( msec < trigger );

	printf("\nTime taken %d seconds %d milliseconds (%d iterations)\n",
	msec/1000, msec%1000, iterations);
	return 0;
}
