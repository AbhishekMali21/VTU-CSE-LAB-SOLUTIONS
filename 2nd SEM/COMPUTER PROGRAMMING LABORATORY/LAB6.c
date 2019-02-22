#include<stdio.h>
#include<conio.h>
#include<string.h>

void main()
{
	char name[50][50],key[50];
	int n,i,low,high,mid,found=0;
	printf("How many names to Read:\n");
	scanf("%d",&n);
	printf("Enter the Names in ascending order:\n");
	for(i=0;i<n;i++)
	{
		scanf("%s",name[i]);
	}
	printf("\nType the name to be searched:");
	scanf("%s",key);

	low=0;
	high=n-1;
	while(low<=high && !found)
	{
		mid=(low+high)/2;
		if(strcmp(name[mid],key)==0)
			found=1;
	    else if(strcmp(name[mid],key)<0)
			low=mid+1;
	    else
			high=mid-1;
	}

	if(found==1)
		printf("\nSearch successful and Name found in the list at  position:%d",mid+1);
	else
		printf("Name not found and search Unsuccessful....!");
	getch();
}