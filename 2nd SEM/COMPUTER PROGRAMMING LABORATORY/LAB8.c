#include<stdio.h>

int main()
{
   int a[20][20],b[20][20],c[20][20];
   int m,n,p,q,i,j,k;

   printf("Enter rows and columns of matrix A\n");
   scanf("%d%d",&m,&n);
   printf("Enter rows and columns of matrix B\n");
   scanf("%d%d",&p,&q);

   if(n!=p)
   {
      printf("Matrix multiplication not possible\n");
      return 0;
   }

   printf("Enter elements of matrix A\n");
   for(i=0;i<m;i++)
   {
      for(j=0;j<n;j++)
      {
	        scanf("%d",&a[i][j]);
      }
   }

   printf("Enter elements of matrix B\n");
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

   printf("Product of two matrices is\n");
   for(i=0;i<m;i++)
   {
      for(j=0;j<q;j++)
      {
	      printf("%d\n",c[i][j]);
      }
   }
}
