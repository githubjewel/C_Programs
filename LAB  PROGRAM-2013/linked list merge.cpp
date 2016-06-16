#include <stdio.h>
#include <stdlib.h>
struct node
{
    int value;
    node *next;
};
void print(node *head)
{
    node *temp;
    temp=head->next;
    while(temp!=NULL)
    {
        printf("%d ", temp->value);
        temp=temp->next;
    }
    printf("\n");
}
void insertfirst(node *head, int x)
{
    node *temp;
    temp=(node*)malloc(sizeof(node));
    temp->next=head->next;
    head->next=temp;
    temp->value=x;
}
void insertlast(node *head, int x)
{
    node *temp;
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=(node*)malloc(sizeof(node));
    temp->next->value=x;
    temp->next->next=NULL;
}
void particularinsert(node *head, int x, int item)
{
    node *temp, *temp2;
    temp=head;
    while(temp->next!=NULL && temp->next->value!=item)
    {
        temp=temp->next;
    }
    if(temp->next==NULL)
    {
        printf("Not Found %d\n",item);
    }
    else
    {
        temp2=(node*)malloc(sizeof(node));
        temp2->value=x;
        temp2->next=temp->next;
        temp->next=temp2;
    }
}
void sortedinsert(node *head, int x)
{
    node *temp, *temp2;
    temp=head;
    if(temp->next!=NULL)
    while(temp->next->value<x)
    {
        temp=temp->next;
        if(temp->next==NULL) break;
    }
   temp2=(node*)malloc(sizeof(node));
   temp2->next=temp->next;
   temp->next=temp2;
   temp2->value=x;
}
void deleteparticular(node *head, int item)
{
    node *temp;
    temp=head;
    while(temp->next->value!=item)
    {
        temp=temp->next;
        if(temp->next==NULL)
        break;
    }
    if(temp->next!=NULL) temp->next=temp->next->next;
    else printf("Not Found\n");
}
void swap(node *head, int item)
{
    node *temp, *prev,*after;
    temp = head;
    int count = 0;
    while(count<item)
    {
        prev=temp;
        temp=temp->next;
        count++;
    }
    if(temp->next==NULL) printf("Nothing to swap\n");
    else
    {
        prev->next=temp->next;
        temp->next=temp->next->next;
        prev->next->next =temp;
    }
}
void sortedmerge(node *head1, node *head2, node *head3)
{
    node *temp1, *temp2, *temp3;
    temp1=head1->next;
    temp2=head2->next;
    //head3->next=(node*)malloc(sizeof(node));
    //head3->next->next=NULL;
    temp3=head3;
    while(temp1!=NULL && temp2!=NULL)
    {
        if(temp1->value<temp2->value)
        {
            temp3->next=(node*)malloc(sizeof(node));
            temp3->next->next=NULL;
            temp3=temp3->next;
            temp3->value=temp1->value;
            temp1=temp1->next;
        }
        else
        {
            temp3->next=(node*)malloc(sizeof(node));
            temp3->next->next=NULL;
            temp3 = temp3->next;
            temp3->value=temp2->value;
            temp2 = temp2->next;
        }
    }
    if(temp1!=NULL)
    {
        temp3->next=temp1;
    }
    else temp3->next=temp2;
}
int main()
{
    node *head1, *head2, *head,*head3;
    head1=(node*)malloc(sizeof(node));
    head1->next=NULL;
    head2=(node*)malloc(sizeof(node));
    head2->next=NULL;
    head3=(node*)malloc(sizeof(node));
    head3->next=NULL;
while(1)
{
    int n,x,item,n1;
    printf("1.insert first\n2.insert last\n3.insert before a particular element\n4.sorted insert\n5.delete first element\n6.delete last element\n7.delete a particular element\n8.swap\n9.merge\n10.print\n");
    scanf("%d",&n);
    if(n==1)
    {
        printf("Which list?\npress 1 to insert in 1st list\nAny other key to insert in 2nd list\n");
        scanf("%d",&n1);
        if(n1==1) head=head1;
        else head = head2;
        scanf("%d",&x);
        insertfirst(head,x);
    }
    else if(n==2)
    {
        printf("Which list?\npress 1 to insert in 1st list\nAny other key to insert in 2nd list\n");
        scanf("%d",&n1);
        if(n1==1) head=head1;
        else head = head2;
        scanf("%d",&x);
        insertlast(head,x);
    }
    else if(n==3)
    {
        printf("Which list?\npress 1 to insert in 1st list\nAny other key to insert in 2nd list\n");
        scanf("%d",&n1);
        if(n1==1) head=head1;
        else head = head2;
        scanf("%d %d", &item,&x);
        particularinsert(head, x, item);
    }
    else if(n==4)
    {
        printf("Which list?\npress 1 to insert in 1st list\nAny other key to insert in 2nd list\n");
        scanf("%d",&n1);
        if(n1==1) head=head1;
        else head = head2;
        scanf("%d",&x);
        sortedinsert(head,x);
    }
    else if(n==5)
    {
        printf("Which list?\npress 1 to delete from 1st list\nAny other key to delete from 2nd list\n");
        scanf("%d",&n1);
        if(n1==1) head=head1;
        else head = head2;
        if(head->next!=NULL)
        head->next=head->next->next;
        else printf("Linked list is empty.\n");
    }
    else if(n==6)
    {
        printf("Which list?\npress 1 to delete from 1st list\nAny other key to delete from 2nd list\n");
        scanf("%d",&n1);
        if(n1==1) head=head1;
        else head = head2;
        node *temp;
        temp=head;
        if(temp->next==NULL) printf("Nothing to delete\n");
        else
        {
            while(temp->next->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=temp->next->next;
        }
    }
    else if(n==7)
    {
        printf("Which list?\npress 1 to delete from 1st list\nAny other key to delete from 2nd list\n");
        scanf("%d",&n1);
        if(n1==1) head=head1;
        else head = head2;
        scanf("%d",&item);
        deleteparticular(head,item);
    }
    else if(n==8)
    {
        printf("Which list?\npress 1 to select 1st list\nAny other key to select 2nd list\n");
        scanf("%d",&n1);
        if(n1==1) head=head1;
        else head = head2;
        scanf("%d",&item);
        swap(head,item);
    }
    else if(n==9) sortedmerge(head1,head2, head3);
    else if(n==10)
    {
        printf("Which list?\npress 1 to print 1st list\npress 2 to print 2nd list\nAny other key to print 3rd list\n");
        scanf("%d",&n1);
        if(n1==1) head=head1;
        else if(n1==2) head=head2;
        else head = head3;
        print(head);
    }
    else if(!n) exit(1);
}
    return 0;
}

