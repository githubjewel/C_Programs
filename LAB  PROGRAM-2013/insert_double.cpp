#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct node 
{
	int roll;
	node *next;
	node *pre;
};
void insert(struct node *head,int x)
{
    struct node *temp,*a;
    temp=head;
    if(head==NULL)
    {
        a=(struct node*)malloc(sizeof(struct node));
       	a->roll=x;
		a->next=NULL;
		head=a;
    }
    else
    {
		while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        a=(struct node*)malloc(sizeof(struct node));
		a->roll=x;
		a->pre=temp;
		a->next=NULL;
        temp->next=a;
    }
}
void print(struct node *head)
{
    struct node *temp;
    temp=head;
    while(temp->next!=NULL)
    {
        //printf("%d ",temp->data);
		printf("%d\n",temp->next->roll);
		
        temp=temp->next;
    }
	printf("\n\n");
}

int main()
{
    struct node *head;
	head=(struct node*)malloc(sizeof(struct node));
    head->next=NULL;
	head->pre=NULL;
    int n,i,num;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&num);
        insert(head,num);
    }
    print(head);
    return 0;
}
