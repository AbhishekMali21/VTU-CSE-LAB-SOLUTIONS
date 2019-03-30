#include<stdio.h>
#include<math.h>

void main ()
{
	float a[20], sum1 = 0, sum2 = 0, mean, var, dev;
	int i, n;
	printf ("Enter no of elements:");
	scanf ("%d", &n);
	printf ("Enter array elements:");
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
	printf ("Sum       :%f\n", sum1);
	printf ("Mean      :%f\n", mean);
	printf ("Variance  :%f\n", var);
	printf ("Deviation :%f\n", dev);
}
