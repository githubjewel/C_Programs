#include <cstdio>
#include <cstring>
#include <queue>
#include <stdlib.h>
using namespace std;
struct node
{
    int value;
    node *left;
    node *right;
    node *parent;
};
node *par, *loc,*root=NULL;
//queue<node*>q;
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
        root->parent=NULL;
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
            loc->parent=par;
        }
        else printf("Element exists\n");
    }
}


void inorder(node* temp)
{
    if(temp!=0)
    {
        inorder(temp->left);
        printf("%d ",temp->value);
        inorder(temp->right);
    }
}
int main()
{
    while(true)
    {
        printf("1. insert 2. print inorder\n");
        int n;
        scanf("%d",&n);
        if(n==0) break;
        else if(n==1)
        {
            int x;
            scanf("%d",&x);
            insert(x);
        }
        //else if(n==2)
        //inorder();

    }
    return 0;
}

