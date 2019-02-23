%{
#include<stdio.h>
int v=0,op=0,id=0,flag=0;
%}
%%
[a-zA-Z]+[0-9A-Za-z]* {id++;printf("\n Identifier:");ECHO;}
[\+\-\*/\=]{op++;printf("\n Operator:");ECHO;}
"(" {v++;}
")" {v--;}
";" {flag=1;}
.|\n {;}
%%

main()
{
	printf("Enter the expression:");
	yylex();
		if((op+1)==id && v==0 && flag==0)
			printf("\n Expression is Valid\n");
		else
			printf("\n Expression is Invalid\n");
}			