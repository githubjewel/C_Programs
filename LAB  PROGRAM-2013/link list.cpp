#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct node
{
    char name[100];
    int roll;
    float grade;
	node *next;
};
void input(node *head)
{
	node *temp;
	temp = head;
	while ( temp->next != NULL )
	{
		temp = temp->next;
	}
	temp->next = (node*) malloc(sizeof(node));
	scanf("%s",&temp->next->name);
    scanf("%d",&temp->next->roll);
    scanf("%f",&temp->next->grade);
	temp->next->next = NULL;
}
void travers(node *head)
{
	node *b;
	b=head;
	while(b->next!=NULL){
		printf("name:%s\n",b->next->name);
		printf("roll:%d\n",b->next->roll);
		printf("grade:%f\n",b->next->grade);
		b = b->next;
	}
}

int main()
{
    printf("enter name:\nroll:\ngrade\n");
	node *head;
	head = (node*) malloc(sizeof(node));
	head->next = NULL;
    input(head);
	travers(head);


	return 0;
}



