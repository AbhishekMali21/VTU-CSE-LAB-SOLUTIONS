%{
int flag=0;
%}

%%
" and " |
" or " |
" but " |
" because " |
" than "|
" nevertheless " {flag=1;}
%%
int main()
{
 printf("Enter the sentence:\n");
 yylex();
  if(flag==1)
  printf("compound statement");
  else
  printf("simple statements\n");
}
