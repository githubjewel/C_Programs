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
    node *a;
    a=(node*)malloc(sizeof(node));
    a->value=x;
    a->next=temp->next;
    temp->next=a;
    while(1)
    {
        temp=temp->next;
        printf("%d",temp->value);
        if(temp->next==0) break;
    }
    printf("\n");
}
int main()
{
    int i,n,p;
    node *head;
    head=(node*)malloc(sizeof(node));
    head->next=0;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d",&p);
        insert(head,p);
    }
    return 0;
}
