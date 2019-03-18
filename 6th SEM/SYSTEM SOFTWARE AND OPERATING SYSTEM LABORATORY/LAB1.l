%{
#include<stdio.h>
int v=0,op=0,id=0,flag=0;
%}

%%
[a-zA-Z]+[0-9A-Za-z]* {id++;}
[0-9]+ {id++;}
[\+\-\*/\=] {op++;}
"(" {v++;}
")" {v--;}
";" {flag=1;}
.|\n {return 0;}
%%

int main()
{
        printf("Enter the expression:");
        yylex();
        if((op+1)==id && v==0 && flag==0)
        {
                printf("\n Expression is Valid\n");
                printf("No of identifier = %d \n No of Operators = %d \n",id,op);
        }
        else
                printf("\n Expression is Invalid\n");
return 0;
}
