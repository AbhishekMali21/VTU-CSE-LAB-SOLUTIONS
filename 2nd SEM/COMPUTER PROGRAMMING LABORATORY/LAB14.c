#include<stdio.h>
#include<math.h>

void main ()
{
	float a[20], sum1 = 0, sum2 = 0, mean, var, dev;
	int i, n;
	clrscr();
	printf ("enter no of ele\n");
	scanf ("%d", &n);
	printf ("enter array ele\n");
	for (i = 0; i < n; i++)
	{
		scanf ("%f", a + i);
		sum1 = sum1 + * (a + i);
	}

	mean = sum1 / n;
	for (i = 0; i < n; i++)
	{
		sum2 = sum2 + pow ((*(a + i) - mean), 2);
	}
	var = sum2 / n;
	dev = sqrt (var);
	
	printf ("sum is%f\n", sum1);
	printf ("mean is%f\n", mean);
	printf ("variance is%f\n", var);
	printf ("devn is%f\n", dev);
	getch();
}