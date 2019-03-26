#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    int num;
    struct node* next;
}node;

node* create(int n)
{
    int i,a;
    node *head,*p,*q,*x,*y,*z;
    head=(node*)malloc(sizeof(node));
    head->next=NULL;
    for(i=0;i<n;i++)
    {
        printf("请输入第%d个人的密码:",i+1);
        scanf("%d",&a);
        p=(node*)malloc(sizeof(node));
        p->data=a;
        p->num=i+1;
        p->next=head->next;
        head->next=p;
    }
    q=head;
    while(q->next!=NULL)
    {
        q=q->next;
    }
    q->next=head->next;
    free(head);
    z=q;
    x=z;
    y=NULL;
    z=NULL;
    while(x)
    {
        y=x->next;
        x->next=z;
        z=x;
        x=y;
    }
    return q;
}

void main()
{
    int n,i,j;
    int m=20;
    node *list,*p,*q;
    printf("请输入参与游戏的人数:");
    scanf("%d",&n);
    list=create(n);
    p=list;
    for(i=1;i<n-1;i++)
    {
        for(j=1;j<m;j++)
        {
            p=p->next;
        }
        m=p->data;
        printf("%d\n",p->num);
        q=p;
        while(q->next!=p)
        {
            q=q->next;
        }
        q->next=p->next;
        free(p);
        p=q->next;
    }
    for(i=1;i<m;i++)
    {
        p=p->next;
    }
    q=p->next;
    printf("%d\n%d\n",p->num,q->num);
    free(p);
    free(q);
}
