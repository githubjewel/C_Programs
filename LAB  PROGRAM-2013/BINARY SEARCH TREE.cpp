#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct tree
{
    int item;

    tree *left_pointer;

    tree *right_pointer;


}*Parent,*Location,*Root;



void search_valu(int key)
{
    tree *store,*pointer;

      int i,j,k;

    if(Root == NULL)
    {
        Location= NULL;    Parent = NULL;

                           return;
    }

    if(key==Root->item)
    {
        Location = Root;   Parent = NULL;

                    return;
    }
    if(key<Root->item)
    {
        store= Root;

        pointer = Root->left_pointer;
    }
    else
    {
        store = Root;

        pointer = Root->right_pointer;
    }

    for(; pointer!=NULL;)
    {
        if(key==pointer->item)
        {
            Location = pointer;

            Parent = store;

            return;
        }
        else if(key<pointer->item)
        {
            store= pointer;

            pointer = pointer->left_pointer;
        }
        else
        {
            store = pointer;

            pointer = pointer->right_pointer;
        }
    }

    Parent = store;

    Location= NULL;

    return;
}

void node_insert(int key)
{
    tree *new_node,*b;

    int i,j;

    search_valu(key);

    if(Location!=NULL)
    {
        printf("\nThe item is in the tree\n");

         return;
    }


    new_node = (tree*) malloc(sizeof(tree));

    new_node->item=key;

    if(Parent==NULL)
    {
        Root = new_node;

        new_node->left_pointer=NULL;

        new_node->right_pointer=NULL;
    }
    else if(Parent->item > new_node->item)
    {
        new_node->left_pointer = Parent->left_pointer;

        new_node->right_pointer = NULL;

        Parent->left_pointer = new_node;
    }
    else
    {
        new_node->right_pointer = Parent->right_pointer;

        Parent->right_pointer = new_node;

        new_node->left_pointer = NULL;
    }
    return;
}

void print_inorder(tree *Root)
{

    if(Root==NULL)
    {
        printf("\n\n");
        return;}

    print_inorder(Root->left_pointer);

    printf("%d ",Root->item);

    print_inorder(Root->right_pointer);
}
/*void preorder(node *root)
{
    if(root==NULL) return;
    printf("%d ",root->value);
    preorder(root->left);
    preorder(root->right);
}*/
tree* FindMin(tree *new_node)
{
    while(new_node->left_pointer!=NULL)

    new_node=new_node->left_pointer;

    return new_node;
}

void delete_node(int key)
{
    search_valu(key);

    if(Location==NULL)

    printf("Element doesn't exist\n");

    else
    {
        if(Location==Root)
        {

            Parent=NULL;
        }
        if(Location->left_pointer==NULL && Location ->right_pointer==NULL)
        {
            if(Location==Parent->left_pointer)

            Parent->left_pointer=NULL;

            else Parent->right_pointer=NULL;
        }
        else if(Location->left_pointer==NULL || Location->right_pointer==NULL)
        {
            tree *new_node;

            if(Location->left_pointer==NULL)

            new_node=Location->right_pointer;

            else new_node = Location->left_pointer;

            if(Location==Parent->left_pointer)

            Parent->left_pointer=new_node;

            else Parent->right_pointer=new_node;
        }
        else
        {
            tree *new_node=Location->right_pointer;

            new_node=FindMin(new_node);

            delete_node(new_node->item);

            search_valu(key);

            new_node->left_pointer=Location->left_pointer;

            new_node->right_pointer=Location->right_pointer;

            if(Parent!=NULL)
            {
                if(Location==Parent->left_pointer)

                Parent->left_pointer=new_node;

                else Parent->right_pointer=new_node;
            }
            else Root=new_node;
        }
    }
}
int main()
{

     Root = (tree*)malloc(sizeof(tree));

     Root = NULL;

     Location = NULL;

     Parent = NULL;

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

            node_insert(key);
        }

        if(choose==2)
        {
            print_inorder(Root);
        }

        if(choose==3)
        {
            printf("Insert item to delete\n");

            int key;

            scanf("%d",&key);

            delete_node(key);
        }

      if(choose==4)
      {
          printf("Insert item to search\n");

          int key;

          scanf("%d",&key);

          search_valu(key);

          if(Location!=NULL)

          printf("\nThe item is in the tree\n");

          else printf("\nThe item is not in the tree\n");




      }




    }
}
