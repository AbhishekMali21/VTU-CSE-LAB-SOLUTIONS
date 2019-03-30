#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void  main()
{
	int x,n,i;
	float rad, res, sum=0;
	printf("Enter degree\n");
	scanf("%d",&x);
	printf("Enter number of terms\n");
	scanf("%d",&n);

	rad=x*3.14/180;
	for(i=1;i<=n;i+=2)
	{
		if ((i-1)%4==0)
		    sum=sum+pow(rad,i)/fact(i);
		else
		    sum=sum-pow(rad,i)/fact(i);	
	}
	printf("Calculate sin(%d) = %f", x,sum);
	printf("\nLibrary sin(%d) = %f", x,sin(rad));
}

int fact(int m)
{
	int i,f=1;
	for(i=1;i<=m;i++)
	{
	   f=f*i;
	}
	return 1;
}
