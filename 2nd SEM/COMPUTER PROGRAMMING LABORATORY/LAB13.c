#include<stdio.h>

struct stud
{
	int rollno, s1, s2, tot ;
	char name[10] ;
	float avg ;
}s[10] ;

float compute( struct stud S[], int n )
{
	int i;
	float sum=0 ;
	for ( i = 0 ; i < n ; i++ )
	{
		sum = sum + S[i].avg ;
	}
	return (sum/n);
}

void display( struct stud s )
{
	printf("%d \t %s \t\t %d \t %d \t %d \t %.2f \n", s.rollno,s.name,s.s1,s.s2,s.tot,s.avg);
}

void main()
{
	int i, n ;
	float mean;
	clrscr();
	printf("Enter the number of students : ") ;
	scanf("%d", &n) ;
	for(i = 0 ; i < n ; i++)
	{
		printf("\nEnter the roll number : ") ;
		scanf("%d", &s[i].rollno) ;
		printf("\nEnter the name : ") ;
		scanf("%s", s[i].name) ;
		printf("\nEnter the marks in 2 subjects : ") ;
		scanf("%d %d", &s[i].s1, &s[i].s2) ;

		s[i].tot = s[i].s1 + s[i].s2 ;
		s[i].avg = s[i].tot / 2.0 ;
	}

	mean = compute( s,n);
	printf("\nBelow Average Students\n");
	printf("\nRoll No. Name \t\tSub1\t Sub2\t Total\t Average\n\n") ;
	for(i = 0 ; i < n ; i++)
	{
		if( s[i].avg < mean )
			display(s[i]);
	}

	printf("\nAbove Average Students\n");
	printf("\nRoll No. Name \t\tSub1\t Sub2\t Total\t Average\n\n") ;
	for(i = 0 ; i < n ; i++)
	{
		if( s[i].avg >= mean )
			display(s[i]);
	}
	getch();
}