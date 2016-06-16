#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
	char name[50];
	int roll;
	double cgpa;
	node *prev;
	node *next;
};
void insert(node *head,char n[],int r,double gpa)
{
	node *temp;
	temp=head;
	while(temp->next != NULL)
		temp=temp->next;
	temp->next=(node*)malloc(sizeof(node));
	temp->next->prev=temp;
	strcpy(temp->next->name,n);
	temp->next->roll=r;
	temp->next->cgpa=gpa;
	temp->next->next=NULL;
}
		
void insert1st(node *head,char n[],int r,double gpa)
{
	node *temp;
	temp=head;
	node *a;
	a=(node*)malloc(sizeof(node));
	strcpy(a->name,n);
	a->roll=r;
	a->cgpa=gpa;
	a->next=temp;
	temp->prev=a;
	a->prev=NULL;

}
void print1st(node *head)
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
	head->prev=NULL;
	int choice;
	char a[50];
	int rl;
	double cg;
	while(1)
	{
		printf("1.Insert\n2.Insert1st\n3.InsertLast\n4.InsertIntermediary\n5.print1st\n6.printlast\n6.Exit\n");
		scanf("%d",&choice);
		if(choice==1)
		{
			scanf("%s %d %lf",a,&rl,&cg);
			insert(head,a,rl,cg);

		}
		else if(choice==2)
		{
			scanf("%s %d %lf",a,&rl,&cg);
			insert1st(head,a,rl,cg);
		
		}
		else if(choice ==5)
			print1st(head);
		else if(choice==6)
			break;
	}


return 0;
}