#include<stdio.h>
int isprime(int n);

int main()
{
	int i,m1,m2;
	printf("enter range\n");
	scanf("%d%d",&m1,&m2);
	printf("prime num from %d to %d are:\n",m1,m2);
	for(i=m1;i<=m2;i++)
	{
		if(isprime(i))
			printf("%d\n",i);
	}
}

int isprime(int m)
{
	int i;
		for(i=2;i<=m/2;i++)
		{
			if(m%i==0)
			{
				return 0;
			}
		}
	return 1;
}
