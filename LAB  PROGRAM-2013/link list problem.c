#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct node
{
    char name[100];
	int roll;
	float mark;
	node *next;
};
void traverse(node *head)
{
	node *temp;
	temp = head;
	while ( temp->next != NULL )
	{
		temp = temp->next;
	}
	temp->next = (node*) malloc(sizeof(node));
	temp->next->value = x;
	temp->next->next = NULL;
}
void print(node *head)
{
	node *b;
	b=head;
	while(b->next!=NULL){
		printf("%d\n",b->next->value);
		b = b->next;
	}
}

int main()
{
	node *head;
	int i,a,n;
	scanf("%d",&n);

	head = (node*) malloc(sizeof(node));
	head->next = NULL;
	for(i=0;i<n;i++){
		scanf("%d",&a);
		insert(head,a);
	}
	print(head);


	return 0;
}



