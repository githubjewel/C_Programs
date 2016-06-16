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
void search(int x)
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
        search(x);
        if(loc==NULL)
        {
            loc=(node*)malloc(sizeof(node));
            loc->value=x;
            loc->left=NULL;
            loc->right=NULL;
            if(par->value>x)
                par->left=loc;
            else
                par->right=loc;
        }
        else
            printf("Present\n");
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
}
node* findmin(node *temp)
{
    while(temp->left!=NULL)
        temp=temp->left;
    return temp;
}
void delet(int x)
{
    search(x);
    if(loc==NULL)
    printf("Not Present\n");
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
            else
                child = loc->left;

            if(loc==par->left)
                par->left=child;
            else
                par->right=child;
        }
        else
        {
            node *temp=loc->right;
            temp=findmin(temp);
            delet(temp->value);
            search(x);
            temp->left=loc->left;
            temp->right=loc->right;
            if(par!=NULL)
            {
                if(loc==par->left)
                    par->left=temp;
                else
                    par->right=temp;
            }
            else
                root=temp;
        }
    }
}
int main()
{
    char c;
    while(c!='0')
    {
        printf("\t\t*****MENU ITEM*****\n\n");
        printf("\n1. Insert  2.Inorder Traverse  3.Delete 4.Search\n");
        fflush(stdin);
        scanf("%c",&c);
        switch(c){
            case '1':{
                int x;
                printf("What Number Do You Want to Insert?: ");
                scanf("%d",&x);
                insert(x);
                break;
            }

            case'2':{
                printf("Inordered List is\n");
                inorder(root);
                printf("\n");
                break;
            }

            case '3':{
                int x;
                printf("Item To Be Deleted Is: ");
                scanf("%d",&x);
                delet(x);
                break;
            }

            case'4':{
                int x;
                printf("Item To Be Searched Is: ");
                scanf("%d",&x);
                search(x);
                if(loc!=NULL) printf("Found\n");
                else printf("Not found\n");
                break;
            }
            default:
                printf("Ok");
                break;
        }

    }
    return 0;
}

