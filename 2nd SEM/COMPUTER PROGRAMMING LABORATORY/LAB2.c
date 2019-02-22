#include<stdio.h>
#include<conio.h>
void main()
{
    int a,b;
    int op;
    clrscr();

    printf(" 1.Addition\n 2.Subtraction\n 3.Multiplication\n 4.Division\n 5.Remainder\n");
    printf("Enter the values of a & b: ");
    scanf("%d %d",&a,&b);
    
    printf("Enter your Choice : ");
    scanf("%d",&op);
    
    switch(op)
    {
        case 1  :
    	   printf("Sum of %d and %d is : %d",a,b,a+b);
    	   break;
        case 2  :
    	   printf("Difference of %d and %d is : %d",a,b,a-b);
    	   break;
        case 3  :
    	   printf("Multiplication of %d and %d is : %d",a,b,a*b);
    	   break;
        case 4  :
    	   printf("Division of Two Numbers is %d : ",a/b);
    	   break;
        case 5:
    	   printf("Remainder of %d and %d is : %d",a,b,a%b);
    	   break;
        default :
    	   printf(" Enter Your Correct Choice.");
    	   break;
    }
    getch();
}