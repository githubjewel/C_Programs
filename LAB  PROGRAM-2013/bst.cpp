#include <cstdio>
#include <cstring>
#include <stdlib.h>
using namespace std;
struct node
{
    int value;

    node *left;

    node *right;
};
node *par, *loc,*root=NULL;

void find(int x)
{
    if(root==NULL)
    {
        par=NULL;

        loc = NULL;
    }
    else if(x==root->value)
    {
        par=NULL;

        loc=root;
    }
    else
    {
        node *ptr;

        if(x<root->value)

        ptr=root->left;

        else ptr = root->right;

        par=root;

        while(ptr!=NULL)
        {
            if(x==ptr->value)
            {
                break;
            }

            else if(x<ptr->value)
            {
                par=ptr;
                ptr=ptr->left;
            }

            else
            {
                par=ptr;
                ptr=ptr->right;
            }


        }

        loc=ptr;
    }
}
void insert(int x)
{
    if(root==NULL)
    {
        root=(node*)malloc(sizeof(node));

        root->left=NULL;

        root->right=NULL;

        root->value=x;
    }
    else
    {
        find(x);

        if(loc==NULL)
        {
            loc=(node*)malloc(sizeof(node));

            loc->value=x;

            loc->left=NULL;

            loc->right=NULL;

            if(par->value>x)

            par->left=loc;

            else par->right=loc;
        }
        else printf("Element exists\n");
}

}
void inorder(node *temp)
{
    if(temp!=NULL)
    {
        inorder(temp->left);

        printf("%d ",temp->value);

        inorder(temp->right);

    }
    printf("\n");
}
node* findmin(node *temp)
{
    while(temp->left!=NULL)

    temp=temp->left;

    return temp;
}
void delet(int x)
{
    find(x);

    if(loc==NULL)

    printf("Element doesn't exist\n");

    else
    {
        if(loc->left==NULL && loc ->right==NULL)
        {
            if(loc==par->left) par->left=NULL;

            else par->right=NULL;

        }
        else if(loc->left==NULL || loc->right==NULL)
        {
            node *child;

            if(loc->left==NULL)

            child=loc->right;

            else child = loc->left;

            if(loc==par->left)

             par->left=child;

            else par->right=child;
        }
        else
        {
            node *temp=loc->right;

            temp=findmin(temp);

            delet(temp->value);

            find(x);

            temp->left=loc->left;

            temp->right=loc->right;

            if(par!=NULL)
            {
                if(loc==par->left) par->left=temp;

                else par->right=temp;
            }
            else root=temp;
        }
    }
}
int main()
{

     root = (node*)malloc(sizeof(node));

     root = NULL;

     loc = NULL;

     par = NULL;

    while(1)
    {

        printf("Choose from following item\n");
        printf("Enter 1 forInsert\n");
        printf("Enter 2 for print\n");
        printf("Enter 3 for Delete\n");
        printf("Enter 4 for search\n");

        int choose;

        scanf("%d",&choose);

        if(choose==1)
        {
            printf("Insert item to add\n");

            int key;

            scanf("%d",&key);

            insert(key);
        }

        if(choose==2)
        {
            inorder(root);
        }

        if(choose==3)
        {
            printf("Insert item to delete\n");

            int key;

            scanf("%d",&key);

            delet(key);
        }

      if(choose==4)
      {
          printf("Insert item to search\n");

          int key;

          scanf("%d",&key);

          find(key);

          if(loc!=NULL)

          printf("\nThe item is in the tree\n");

          else printf("\nThe item is not in the tree\n");




      }




    }
}

