#include<stdio.h>
#include<conio.h>

main()
{
   int a[20][20],b[20][20],c[20][20];
   int m,n,p,q,i,j,k;
   clrscr();
   printf("enter rows and columns of matrix a\n");
   scanf("%d%d",&m,&n);
   printf("enter rows and columns of matrix b\n");
   scanf("%d%d",&p,&q);

   if(n!=p)
   {
      printf("matrix multiplication not possible\n");
      return 0;
   }

   printf("enter elements of matrix a\n");
   for(i=0;i<m;i++)
   {
      for(j=0;j<n;j++)
      {
	        scanf("%d",&a[i][j]);
      }
   }

   printf("enter elements of matrix b\n");
   for(i=0;i<p;i++)
   {
      for(j=0;j<q;j++)
      {
	        scanf("%d",&b[i][j]);
      }
   }

   for(i=0;i<p;i++)
   {
      for(j=0;j<q;j++)
      {
      	c[i][j]=0;
      	for(k=0;k<n;k++)
      	{
      	   c[i][j]=c[i][j]+a[i][k]*b[k][j];
      	}
      }
   }

   printf("product of two matrices is\n");
   for(i=0;i<m;i++)
   {
      for(j=0;j<q;j++)
      {
	      printf("%d\n",c[i][j]);
      }
   }
   getch();
}