#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    node *left;
    node *right;
}*loc,*par,*root;


void find(int item)
{
    node *save,*ptr;
    if(root == NULL)
    {
        loc = NULL;
        par = NULL;
        return;
    }
    if(root->value==item)
    {
        loc = root;
        par = NULL;
        return;
    }
    if(item<root->value)
    {
        save = root;
        ptr = root->left;
    }
    else
    {
        save = root;
        ptr = root->right;
    }
    while(ptr!=NULL)
    {
        if(item==ptr->value)
        {
            loc = ptr;
            par = save;
            return;
        }
        else if(item<ptr->value)
        {
            save = ptr;
            ptr = ptr->left;
        }
        else
        {
            save = ptr;
            ptr = ptr->right;
        }
    }
    par = save;
    loc = NULL;
    return;
}

void insert(int item)
{
    find(item);
    if(loc!=NULL)
    {
        printf("\nNumber already inserted\n");
        return;
    }
    node *temp;
    temp = (node*) malloc(sizeof(node));
    temp->value=item;
    if(par==NULL)
    {
        root = temp;
        temp->left=NULL;
        temp->right=NULL;
    }
    else if(par->value > temp->value)
    {
        temp->left = par->left;
        temp->right = NULL;
        par->left = temp;
    }
    else
    {
        temp->right = par->right;
        par->right = temp;
        temp->left = NULL;
    }
    return;
}

void preorder(node *root)
{
    if(root==NULL) return;
    printf("%d ",root->value);
    preorder(root->left);
    preorder(root->right);
}

int main()
{
    int c;
    root = (node*)malloc(sizeof(node));
    root = NULL;
    loc = NULL;
    par = NULL;
    for(;;)
    {
        printf("Choose:");
        printf("\n1. Insert\n");
        printf("2. Show\n");
        printf("3. Exit\n");
        scanf("%d",&c);
        if(c==1)
        {
            scanf("%d",&c);
            insert(c);
        }
        else if(c==2)
        {
            preorder(root);
        }
        else break;
    }
}
