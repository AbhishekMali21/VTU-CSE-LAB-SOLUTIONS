#include<stdio.h>
#include<string.h>

void stringlength(char a[100],char b[100]);
void concatenate(char a[100],char b[100]);
void stringcompare(char a[100],char b[100]);

void main()
{
	char p[100],q[100],ch[100];
	int len1,len2;
	printf("Enter the first string:\n");
	gets(p);
	printf("Enter the second string:\n");
	gets(q);
	stringlength(p,q);
	stringcompare(p,q);
	concatenate(p,q);
}

void stringlength(char a[100], char b[100])
{
	int len1,len2;
	len1=strlen(a);
	len2=strlen(b);
	printf("First string length is :%d \nSecond string lenght is: %d",len1,len2);
}

void concatenate(char a[100], char b[100])
{
	printf("The concatenated String is :%s ", strcat(a,b));
}

void stringcompare(char a[100], char b[100])
{
	if(strcmp(a,b)==0)
		printf("\nSTRINGS ARE EQUAL\n");
	else
 		printf("\nSTRINGS ARE NOT EQUAL\n");
}
