#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

struct node
{
    int info;
    node *right;
    node *left;
};

void ins(node *head,int item)
{
    node *temp;
    temp = (node*)malloc(sizeof(node));
    temp->info = item;
    temp->left = NULL;
    temp->right = NULL;
    while(1)
    {
        if(head->info > item)
        {
            if(head->left == NULL)
            {
                head->left = temp;
                break;
            }
            head = head->left;
        }
        else{
            if(head->right == NULL)
            {
                head->right = temp;
                break;
            }
            head = head->right;
        }
    }
}

void print(node *head)
{
    if(head == NULL)
        return;
    print(head->left);
    printf("%d ",head->info);
    print(head->right);
}
/*void find(node *root,int item)
{
    node *ptr;
    if(root == NULL)
    {
        loc = NULL;
        par = NULL:
        return;
    }
    if(item < root->info)
    {
        ptr = ptr->left;
        par = root;
    }
    else
    {
        ptr = ptr->right;
        par = root;
    }
    while(ptr != NULL)
    {
        if(item == ptr->info)
        {
            loc = ptr;
        }
        if(item < ptr->info)
        {
            par = ptr;
            ptr = ptr->left;
        }
        else
        {
            par = ptr;
            ptr = ptr->right;
        }
    }
    if(ptr == NULL)
    {
        loc = NULL;
        return;
    }
}*/

int main()
{
    node *root;
    root = (node*)malloc(sizeof(node));
    root->right = NULL;
    root->left = NULL;
    int choice,item;
    while(true)
    {
        scanf("%d",&choice);
        if(choice == 1)
        {
            scanf("%d",&item);
            ins(root,item);
        }
        else
        {
            print(root);
        }

    }
    return 0;
}
