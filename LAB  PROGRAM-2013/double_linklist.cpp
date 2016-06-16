#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node
{
    int id;
    char name[50];
    double cGpa;
    node *prev,*next;
};

void insert1( node *head , node *a )
{
    node *temp;
    temp = head;
    a->next = temp->next;
    a->prev = temp;
    temp->next = a;
}

void insert2( node *head , node *a )
{
    node *temp;
    temp = head;
    while( temp->next!= NULL )
    {
        temp = temp->next;
    }
    temp->next = a;
    a->prev = temp;
}

void insert3( node *head , node *a , int x )
{
    node *temp;
    temp = head;
    while( temp->next->id != x )
    {
        temp = temp->next;
    }
    a->next = temp->next;
    a->prev = temp;
    temp->next->prev = a;
    temp->next=a;
}

void print( node *head )
{
    node *temp;
    temp = head->next;
    while( temp != NULL )
    {
        printf("\nName : %s\nID : %d\ncGpa : %.2lf\n\n",temp->name,temp->id,temp->cGpa);
        temp = temp->next;
    }
}

int main()
{
    node *head;
    head->next = NULL;
    head->prev = NULL;
    int choice,option,id,op;
    while(1)
    {
        printf("1.insert\n2.delete\n3.print\n4.exit\n");
        scanf("%d",&choice);
        if( choice == 1 )
        {
            node *a;
            a = (node*)malloc(sizeof(node));
            a->prev = NULL;
            a->next = NULL;
            printf("1.first\n2.last\n3.by id\n");
            scanf("%d",&option);
            if( option == 1 )
            {
                printf("Enter new ID(name,id,cGpa):\n");
                scanf("%s %d %lf",a->name,&a->id,&a->cGpa);
                insert1( head , a );
            }
            else if( option == 2 )
            {
                printf("Enter new ID(name,id,cGpa):\n");
                scanf("%s %d %lf",a->name,&a->id,&a->cGpa);
                insert2( head , a );
            }
            else if( option == 3 )
            {
                printf("Enter the ID:\n");
                scanf("%d",&id);
                printf("Enter new ID(name,id,cGpa):\n");
                scanf("%s %d %lf",a->name,&a->id,&a->cGpa);
                insert3( head , a , id );
            }
        }
        else if( choice == 3 )
        {

        print( head );
        }

    }
    return 0;
}
