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
queue<node*>q;
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
}}
void print()
{
    while(!q.empty())
    {
        node *ptr= q.front();
        printf("%d ",ptr->value);
        if(ptr->left!=NULL) q.push(ptr->left);
        if(ptr->right!=NULL) q.push(ptr->right);
        q.pop();
    }
}
node *sucfind(node *ptr)
{
    if(ptr==root) return NULL;
    if(ptr==ptr->parent->left) return ptr->parent;
    return sucfind(ptr->parent);
}
void finder(int x)
{
    find(x);
    if(loc==NULL) printf("Element does not exist\n");
    else if(loc->right!=NULL)
    {
        node *ptr=loc->right;
        while(ptr->left!=NULL)
        {
            ptr=ptr->left;
        }
        printf("inorder successor is %d\n",ptr->value);
    }
    else
    {
        node *ptr=sucfind(loc);
        if(ptr!=NULL) printf("inorder successor is %d\n",ptr->value);
        else printf("Successor does not exist\n");
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
node* minimum(node *temp)
{
    while(temp->left!=0)
        temp=temp->left;
    return temp;
}
void delet(int x)
{
    find(x);
    if(loc!=0 && loc->left==0 && loc->right==0)
    {
        if(x<par->value) par->left=0;
        else par->right=0;
    }
    else if(loc!=0 && loc->left==0)
    {
        if(x<par->value) par->left=loc->right;
        else par->right=loc->right;
    }
    else if(loc!=0 && loc->right==0)
    {
        if(x<par->value) par->left=loc->left;
        else par->right=loc->left;
    }
    else if(loc!=0)
    {
        node *kk=loc->right;
        delet(kk->value);
        find(x);
        kk->left=loc->left;
        kk->right=loc->right;
        if(x<par->value) par->left=kk;
        else par->right=kk;
    }
}
int main()
{
    while(true)
    {
        printf("1. insert  2.levelwise print  3.in-order successor finder  4.delete\n");
        int n;
        scanf("%d",&n);
        if(n==0) break;
        else if(n==1)
        {
            int x;
            scanf("%d",&x);
            insert(x);
        }
        else if(n==2)
        {
            q.push(root);
            //print();
            printf("\n");
        }
        else if(n==3)
        {
            int x;
            scanf("%d",&x);
            //finder(x);
        }
        else if(n==4)
        {
            int x;
            scanf("%d",&x);
            delet(x);
        }
        else if(n==5)
            inorder(root);
    }
    return 0;
}

