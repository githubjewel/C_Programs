#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int num_element;

struct node
{
    string name;
    int priority;
};
node tree[99];
void insert_heap(node tree[],node item)
{
    num_element++;
    int ptr=num_element-1;
    int par ;
    while(ptr>0)
    {
        par = (ptr-1)/2;
        if(item.priority<=tree[par].priority)
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
node delet(node tree[])
{
    node item=tree[0];
    node last=tree[num_element-1];
    num_element--;
    int ptr=0, left=1, right=2;
    while(right<num_element)
    {
        if(last.priority>=tree[left].priority && last.priority>= tree[right].priority)
        {
            tree[ptr]=last;
            return item;
        }
        if(tree[right].priority<=tree[left].priority)
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
    if(left==num_element-1 && last.priority<tree[left].priority)
    {
        tree[ptr]=tree[left];
        ptr=left;
    }
    tree[ptr]=last;
    return item;
}
void print_tree(node tree[], int num_element)
{
    for(int i=0;i<num_element;i++)
    {
         cout<<tree[i].name<<endl;
    }
    printf("\n");
}
int main()
{
   while(true)
   {
        int choice;
        node item;
        printf("please insert your choice : \n\t1.Insert item\n\t2.Print tree\n\t3.delete\n\t");
        scanf("%d",&choice);
        if(choice==1)
        {
            printf("Please insert the item : ");
            cin>>item.name;
            scanf("%d",&item.priority);
            insert_heap(tree,item);
        }
        else if(choice==2)
        {
            print_tree(tree,num_element);
        }
        else if(choice==3)
        {
            if(num_element>0) cout<<delet(tree).name<<endl;
            else printf("underflow\n");
        }
   }
   return 0;
}
