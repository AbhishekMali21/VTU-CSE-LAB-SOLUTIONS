#include<string.h>
#include<stdio.h>
#include<stdlib.h>
struct stud
{
    char ssn[11],name[15],desg[15],phno[11],dept[15];
    float sal;
    struct stud *next,*prev;
}*f=NULL,*r=NULL,*t=NULL;
void ins(int ch)
{
    t=(struct stud*)malloc(sizeof(struct stud));
    printf("\nEnter SSN:");
    scanf("%s",t->ssn);
    printf("Enter Name:");
    scanf("%s",t->name);
    printf("Enter Dept:");
    scanf("%s",t->dept);
    printf("Enter desg:");
    scanf("%s",t->desg);
    printf("Enter Phno:");
    scanf("%s",t->phno);
    printf("Enter salary:");
    scanf("%f",&t->sal);
    t->next=t->prev=NULL;
    if(!r)
        f=r=t;
    else
    {
        if(ch)
        {
            r->next=t;
            t->prev=r;
            r=t;
        }
        else
        {
            t->next=f;
            f->prev=t;
            f=t;
        }
    }
}
void del(int ch)
{
    if(!f)
        printf("\nList Empty");
    else
    {
        struct stud *t1;
        if(f==r)
        {
            t1=f;
            f=r=NULL;
        }
        else if(ch)
        {
            t1=r;
            r=r->prev;
            r->next=NULL;
        }
        else
        {
            t1=f;
            f=f->next;
            f->prev=NULL;
        }
        printf("\nElement deleted is:\n");
        printf("\nSSN:%s\nName:%s\nDept:%s\nDesg:%s\nPhno:%s\nSalary:%f\n",t1->ssn,t1->name,t1->dept,t1->desg,t1->phno,t1->sal);
        free(t1);
    }
}
void disp()
{
    if(!f)
        printf("\nList Empty!!!");
    else
        printf("\nList elements are:\n");
    for(t=f;t;t=t->next)
       printf("\nSSN:%s\nName:%s\nDept:%s\nDesg:%s\nPhno:%s\nSalary:%f\n",t->ssn,t->name,t->dept,t->desg,t->phno,t->sal);
}
void main()
{
    int ch,n,i;
    printf("\n........Menu..........,\n");
    printf("1.Create\n");
    printf("2.Display\n");
    printf("3.Insert at end\n");
    printf("4.Delete at end\n");
    printf("5.Insert at beg\n");
    printf("6.Delete at beg\n");
    printf("7.Exit\n");
    while(1)
    {
        printf("\nEnter choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nEnter no. of nodes:");
                    scanf("%d",&n);
                    for(i=0;i<n;i++)
                        ins(0);
                    break;
            case 2:disp();break;
            case 3:ins(1);break;
            case 4:del(1);break;
            case 5:ins(0);break;
            case 6:del(0);break;
            case 7:exit(0);
            default:printf("\nInvalid choice!!!!");
        }
    }
}