#include<stdio.h>

int main()
{
   int n,m,rev,digit;
   printf("Enter the value of n\n");
   scanf("%d",&n);

   rev=0;
   m=n;
   while(n!=0)
   {
      digit=n%10;
      n=n/10;
      rev=digit+10*rev;
   }
   printf("Reverse of %d is %d\n",m,rev);

   if(m==rev)
	     printf("It is a palindrome\n");
   else
	     printf("It is not a palindrome\n");
}
