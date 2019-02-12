#include <stdio.h>
#include <stdlib.h>
#define max 5
int q[max],f=-1,r=-1;
void ins()
{
    if(f==(r+1)%max)
        printf("\nQueue overflow");
    else
    {
        if(f==-1)
            f++;
        r=(r+1)%max;
        printf("\nEnter element to be inserted:");
        scanf("%d",&q[r]);
    }
}
void del()
{
    if(r==-1)
        printf("\nQueue underflow");
    else
    {
        printf("\nElemnt deleted is:%d",q[f]);
        if(f==r)
            f=r=-1;
        else
            f=(f+1)%max;
    }
}
void disp()
{
    if(f==-1)
        printf("\nQueue empty");
    else
    {
        int i;
        printf("\nQueue elements are:\n");
        for(i=f;i!=r;i=(i+1)%max)
            printf("%d\t",q[i]);
        printf("%d",q[i]);
        printf("\nFront is at:%d\nRear is at:%d",q[f],q[r]);
    }
}
int main()
{
    printf("\nCircular Queue operations");
    printf("\n1.Insert");
    printf("\n2.Delete");
    printf("\n3.Display");
    printf("\n4.Exit");
    int ch;
    do{
        printf("\nEnter choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:ins();break;
            case 2:del();break;
            case 3:disp();break;
            case 4:exit(0);
            default:printf("\nInvalid choice...!");
        }
   }while(1);
    return 0;
}
