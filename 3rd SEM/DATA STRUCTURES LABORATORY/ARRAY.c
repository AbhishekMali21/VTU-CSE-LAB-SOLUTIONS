#include<stdio.h>
#include<stdlib.h>

int a[10],n,elem,i,pos;
void create();
void display();
void insert();
void delete();

void create()
{
	int i;
	printf("Enter the size of array\n");
	scanf("%d",&n);
	printf("Enter the elements of array\n");
	for(i=0; i<n; i++)
		scanf("%d",&a[i]);
}

void display()
{
	int i;
	printf("The array elements are:\n");
	for(i=0; i<n; i++)
		printf("%d\t",a[i]);
}

void insert()
{
	int i;
	printf("Enter the position for new element:\n");
	scanf("%d",&pos);
	printf("Enter the element to be inserted:\n");
	scanf("%d",&elem);
	for (i = n-1; i <=pos; i--)
		a[i+1]=a[i];
	a[pos]=elem;
	n=n+1;
}

void delete()
{
	printf("Enter  position of element to be deleted:\n");
	scanf("%d",&pos);
	elem=a[pos];
	for (int i = 0; i < n-1; i++)
		a[i]=a[i+1];
	n=n-1;
	printf("Deleted element is %d\n",elem );
}

int main()
{
	int ch;
	while(ch)
	{
		printf("\n\n______MENU_____\n");
		printf("1.Create\n2.Display\n3.Insert\n4.Delete\n5.Exit\n");
		printf("Enter Your Choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:create();break;
			case 2:display();break;
			case 3:insert();break;
			case 4:delete();break;
			case 5:exit(0);break;
			default :printf("INVALID CHOICE\n");
		}
	}return 0;
}
