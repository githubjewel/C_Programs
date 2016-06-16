#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	char name[50];
	int roll;
	double cgpa;
	node *next;

};
void insert(node *head,char n[],int r,double gpa)
{
	node *temp;
	temp=head;
	while(temp->next != NULL)
		temp=temp->next;
	temp->next=(node*)malloc(sizeof(node));
	strcpy(temp->next->name,n);
	temp->next->roll=r;
	temp->next->cgpa=gpa;
	temp->next->next=NULL;
}
void insertbefore(node *head)
{
	int item;
	node *a;
	a=(node*)malloc(sizeof(node));
	printf("Insert the key\n");
	scanf("%d",&item);
	printf("Insert the info\n");
	scanf("%s %d %lf",a->name,&a->roll,&a->cgpa);
	node *temp2;
	temp2=head;
	while(temp2->next->roll != item)
		temp2=temp2->next;
    a->next=temp2->next;
	temp2->next=a;
    
}
void insertafter(node *head)
{
	node *b;
	b=(node*)malloc(sizeof(node));
	int item;
	printf("Insert the key\n");
	scanf("%d",&item);
	printf("Insert the info\n");
	scanf("%s %d %lf",b->name,&b->roll,&b->cgpa);
	node *temp3;
	temp3=head;
	while(temp3->next->roll != item)
		temp3=temp3->next;
	b->next=temp3->next->next;
	temp3->next->next=b;

}
void del(node *head)
{
	node *temp4;
	temp4=head;
	int item;
	printf("Write the key\n");
	scanf("%d",&item);
	while(temp4->next->roll != item)
		temp4=temp4->next;
	temp4->next = temp4->next->next;

}
void display(node *head)
{
	node *temp1;
	temp1=head;
	while(temp1->next != NULL)
	{
		printf("Name;%s\n",temp1->next->name);
		printf("Roll:%d\n",temp1->next->roll);
		printf("cgpa:%.2lf\n",temp1->next->cgpa);
		printf("\n");
		temp1=temp1->next;
	}

}
int main()
{
	node *head;
	head=(node*)malloc(sizeof(node));
	head->next=NULL;
	int choice;
	char a[50];
	int rl;
	double cg;
	while(1)
	{
		printf("1.Insert\n2.Display\n3.Insert by Key\n4.Delete\n5.Exit\n");
		scanf("%d",&choice);
		if(choice==1)
		{
			scanf("%s %d %lf",a,&rl,&cg);
			insert(head,a,rl,cg);

		}
		else if(choice==2)
		{
			display(head);

		}
		else if(choice==3)
		{
			int option;
			printf("1.Before Key\n2.After Key\n");
			scanf("%d",&option);
			if(option == 1)
			{
				insertbefore(head);
			    
			}
			else if(option == 2)
				insertafter(head);
		}
		else if(choice==4)
		{
			
			del(head);
		}
		else if(choice==5)
			break;

	}

return 0;
}
