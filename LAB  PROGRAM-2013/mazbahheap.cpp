#include <stdio.h>
int num_element=0;
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
void print_tree(int tree[], int num_element)
{
    for(int i=0;i<num_element;i++)
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
   while(true)
   {
        int item,tree[1000],choice;
        printf("please insert your choice : \n\t1.Insert item\n\t2.Print tree\n\t3.delete\n\t");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("Please insert the item : ");
            scanf("%d",&item);
            insert_heap(tree,item);
        }
        else if(choice==2)
        {
            print_tree(tree,num_element);
        }
        else if(choice==3)
        {
            if(num_element>0)printf("just deleted: %d\n",delet(tree));
            else printf("underflow\n");
        }
   }
   return 0;
}
