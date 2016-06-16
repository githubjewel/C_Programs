#include <stdio.h>
#include <stdlib.h>
struct node
{
    int value;
    node *next;
};
void insert(node *head,int x)
{
    node *temp;
    temp=head;
    while(temp->next!=0)
    {
        temp=temp->next;
    }
    temp->next=(node*)malloc(sizeof(node));
    temp->next->value=x;
    temp->next->next=0;
}
void print(node *head)
{
    node *temp;
    temp=head->next;
    while(temp!=0)
    {
        printf("%d\n",temp->value);
        temp=temp->next;
    }
}
void delet(node *head,int y)
{
    node *temp;
    temp=head;
    while(temp->next!=0)
    {
        if(temp->next->value==y)
        {
            temp->next=temp->next->next;
            break;
        }
        else temp=temp->next;
    }
}
int main()
{
    int n,p,i,y;
    node *head;
    head=(node*)malloc(sizeof(node));
    head->next=0;
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        scanf("%d",&p);
        insert(head,p);
    }
    print(head);
    scanf("%d",&y);
    delet(head,y);
    print(head);
    return 0;
}
