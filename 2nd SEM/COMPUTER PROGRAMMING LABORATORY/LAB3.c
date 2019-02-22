#include<stdio.h>
#include<conio.h>
#include<math.h>

void main()
{
	float a,b,c,disc;
	float root1,root2,realp,imagp;
	clrscr();
	printf("enter values of a,b,c\n");
	scanf("%f%f%f",&a,&b,&c);

	if(a==0 && b==0 && c==0)
	{
		printf("roots cannot be determined\n");
		exit(0);
	}
	else
	{
		disc=b*b-4*a*c;
		if(disc>0)
		{
			root1=(-b+sqrt(disc))/(2*a);
			root2=(-b-sqrt(disc))/(2*a);
			printf("roots are real and distinct\n");
			printf("root1=%f\n",root1);
			printf("root2=%f\n",root2);
		}

		else if(disc==0)
		{
			root1=-b/(2*a);
			root2=root1;
			printf("roots are real and equal\n");
			printf("root1=%f\n",root1);
			printf("root2=%f\n",root2);
		}
		
		else if(disc<0)
		{
			realp=-b/(2*a);
			imagp=sqrt(abs(disc)/(2*a));
			printf("roots are complex\n");
			printf("root1=%f+i%f\n",realp,imagp);
			printf("root2=%f-i%f\n",realp,imagp);
		}
	}
	getch();
}