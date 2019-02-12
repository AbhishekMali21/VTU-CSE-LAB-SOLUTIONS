#include<string.h>
#include<stdio.h>
#include<stdlib.h>
struct stud
{
    char usn[11],name[15],branch[4],phno[11];
    int sem;
    struct stud *next;
}*f=NULL,*r=NULL,*t=NULL;
void ins(int ch)
{
    t=(struct stud*)malloc(sizeof(struct stud));
    printf("\nEnter USN:");
    scanf("%s",t->usn);
    printf("Enter Name:");
    scanf("%s",t->name);
    printf("Enter Branch:");
    scanf("%s",t->branch);
    printf("Enter Sem:");
    scanf("%d",&t->sem);
    printf("Enter Phno:");
    scanf("%s",t->phno);
    t->next=NULL;
    if(!r)
        f=r=t;
    else
    {
        if(ch)
        {
            r->next=t;
            r=t;
        }
        else
        {
            t->next=f;
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
            for(t=f;t->next!=r;t=t->next)
                r=t;
            r->next=NULL;
        }
        else
        {
            t1=f;
            f=f->next;
        }
        printf("\nElement deleted is:\n");
        printf("USN:%s\nName:%s\nBranch:%s\nSem:%d\nPhno:%s\n",t1->usn,t1->name,t1->branch,t1->sem,t1->phno);
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
        printf("\nUSN:%s\nName:%s\nBranch:%s\nSem:%d\nPhno:%s\n",t->usn,t->name,t->branch,t->sem,t->phno);
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