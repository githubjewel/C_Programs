#include <stdio.h>
int num_element,n;
void insert_heap(int tree[],int item)
{
    num_element++;
    int ptr=num_element-1;
    int par ;
    while(ptr>0)
    {
        par = (ptr-1)/2;
        if(item<=tree[par])
        {
            tree[ptr]=item;
            return;
        }
        else
        {
            tree[ptr]=tree[par];
            ptr=par;
        }
    }
    tree[0]=item;
}
void print_tree(int tree[], int numelement)
{
    for(int i=0;i<numelement;i++)
    {
        printf("%d ",tree[i]);
    }
    printf("\n");
}
int delet(int tree[])
{
    int item=tree[0];
    int last=tree[num_element-1];
    num_element--;
    int ptr=0, left=1, right=2;
    while(right<num_element)
    {
        if(last>=tree[left] && last >= tree[right])
        {
            tree[ptr]=last;
            return item;
        }
        if(tree[right]<=tree[left])
        {
            tree[ptr]=tree[left];
            ptr=left;
        }
        else
        {
            tree[ptr]=tree[right];
            ptr=right;
        }
        left=2*ptr+1;
        right=left+1;
    }
    if(left==num_element-1 && last<tree[left])
    {
        tree[ptr]=tree[left];
        ptr=left;
    }
    tree[ptr]=last;
    return item;
}
int main()
{
   int item,choice;
    scanf("%d",&n);
    num_element=0;
    int tree[n+2];
    int i;
    for(i=0;i<n;i++)
    {
        int k;
        scanf("%d",&k);
        insert_heap(tree,k);
    }
    for(i=0;i<n;i++)
    {
        tree[n-1-i]=delet(tree);
    }
    print_tree(tree,n);
   return 0;
}

