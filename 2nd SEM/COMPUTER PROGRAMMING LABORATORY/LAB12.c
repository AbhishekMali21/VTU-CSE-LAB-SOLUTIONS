#include<stdio.h>
#include<conio.h>
#include<math.h>

main()
{
  float n,result;
  clrscr();
  printf("enter the value of n\n");
  scanf("%f",&n);

  result=pow(n,0.5);
  printf("square root of %f is %f\n",n,result);
  getch();
}