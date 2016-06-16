#include <stdio.h>
#include <stdlib.h>
struct node
{
    int valu;
    node *next;
};
void print(node *head)
{
    node *temp;
    temp=head;
    while(temp->next!=NULL)
    {
        printf("%d",temp->valu);
        temp=temp->next;
    }
}
void pop(node *head)
{
    node *temp;
    temp=head;
    temp->next=temp->next->next;

}
void push(node *head,int p)
{
    node *temp,*a;
    temp=head;
    a=(node*)malloc(sizeof(node));
    a->valu=p;
    a->next=temp->next;
    temp->next=a;
}
int main()
{
    long long int i,j,n,a,p,choose;
    node *head;
    head=(node*)malloc(sizeof(node));
    head->next=NULL;
    for(; ;)
    {
        scanf("%lld",&choose);
        if(choose==1)
        {
            scanf("%lld",&a);
            push(head,a);
        }
        if(choose==2)
        {
            pop(head);

        }
        if(choose==3)
        {
            print(head);

        }
        if(choose==4) break;
    }
    printf("\n");
}
