#include<stdio.h>
#include<conio.h>

main()
{
   int n,m,rev,digit;
   clrscr();
   printf("enter the value of n\n");
   scanf("%d",&n);

   rev=0;
   m=n;
   while(n!=0)
   {
      digit=n%10;
      n=n/10;
      rev=digit+10*rev;
   }
   printf("reverse of %d is %d\n",m,rev);

   if(m==rev)
	     printf("It is a palindrome\n");
   else
	     printf("It is not a palindrome\n");
   getch();
}