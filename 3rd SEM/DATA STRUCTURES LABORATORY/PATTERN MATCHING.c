#include<stdio.h>

void main()
{
  char s[20],pat[20],rep[20],ans[30];
  int i,j,k,l,flag;
  printf("\nEnter string:");
  scanf("%s",s);
  printf("\nEnter pattern:");
  scanf("%s",pat);
  printf("\nEnter replacement:");
  scanf("%s",rep);
  for(i=0,k=0;s[i]!='\0';i++)
  {
    flag=1;
    for(j=0;pat[j]!='\0';j++)
      if(s[i+j]!=pat[j])
        flag=0;
    l=j;
    if(flag)
    {
      for(j=0;rep[j]!='\0';j++,k++)
        ans[k]=rep[j];
      i+=l-1;
    }
    else
      ans[k++]=s[i];
  }
  ans[k]='\0';
  printf("%s",ans);
}