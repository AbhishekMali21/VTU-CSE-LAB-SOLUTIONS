#include <stdio.h>

int main()
{
	char operator;
	float num1, num2, result;
	printf("Simulation of a Simple Calculator\n\n");
	printf("Enter two numbers \n");
	scanf("%f %f", &num1,&num2);

	fflush(stdin);
	printf("\nEnter the operator [+,-,*,/] \n");
	scanf("%s", &operator);

	switch(operator)
	{
		case '+': result = num1 + num2;		break;
		case '-': result = num1 - num2;		break;
		case '*': result = num1 * num2;		break;
		case '/': result = num1 / num2;		break;
		default : printf("Error in operation");     break;
	}
	printf("\n%.2f %c %.2f = %.2f\n", num1, operator, num2, result);
}
