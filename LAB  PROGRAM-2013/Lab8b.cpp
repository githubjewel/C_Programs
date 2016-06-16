#include<stdio.h>
#include<stdlib.h>

typedef struct treeNode
{
        int data;
        struct treeNode *left;
        struct treeNode *right;

}treeNode;

treeNode* FindMin(treeNode *node)
{
        if(node==NULL)
        {
                /* There is no element in the tree */
                return NULL;
        }
        if(node->left) /* Go to the left sub tree to find the min element */
                return FindMin(node->left);
        else
                return node;
}
treeNode* FindMax(treeNode *node)
{
        if(node==NULL)
        {
                /* There is no element in the tree */
                return NULL;
        }
        if(node->right) /* Go to the left sub tree to find the min element */
                FindMax(node->right);
        else
                return node;
}

treeNode * Insert(treeNode *node,int data)
{
        if(node==NULL)
        {
                treeNode *temp;
                temp = (treeNode *)malloc(sizeof(treeNode));
                temp -> data = data;
                temp -> left = temp -> right = NULL;
                return temp;
        }

        if(data >(node->data))
        {
                node->right = Insert(node->right,data);
        }
        else if(data < (node->data))
        {
                node->left = Insert(node->left,data);
        }
        /* Else there is nothing to do as the data is already in the tree. */



		return node;

}

treeNode * Delete(treeNode *node, int data)
{
        treeNode *temp;
        if(node==NULL)
        {
                printf("Element Not Found\n");
        }
        else if(data < node->data)
        {
                node->left = Delete(node->left, data);
        }
        else if(data > node->data)
        {
                node->right = Delete(node->right, data);
        }
        else
        {
                /* Now We can delete this node and replace with either minimum element
                   in the right sub tree or maximum element in the left subtree */
                if(node->right && node->left)
                {
                        /* Here we will replace with minimum element in the right sub tree */
                        temp = FindMin(node->right);
                        node -> data = temp->data;
                        /* As we replaced it with some other node, we have to delete that node */
                        node -> right = Delete(node->right,temp->data);
                }
                else
                {
                        /* If there is only one or zero children then we can directly
                           remove it from the tree and connect its parent to its child */
                        temp = node;
                        if(node->left == NULL)
                                node = node->right;
                        else if(node->right == NULL)
                                node = node->left;
                        free(temp); /* temp is longer required */
                }
        }
        return node;

}

treeNode * Find(treeNode *node, int data)
{
        if(node==NULL)
        {
                /* Element is not found */
                return NULL;
        }
        if(data > node->data)
        {
                /* Search in the right sub tree. */
                return Find(node->right,data);
        }
        else if(data < node->data)
        {
                /* Search in the left sub tree. */
                return Find(node->left,data);
        }
        else
        {
                /* Element Found */
                return node;
        }
}

void PrintInorder(treeNode *node)
{
        if(node==NULL)
        {
                return;
        }
        PrintInorder(node->left);
        printf("%d ",node->data);
        PrintInorder(node->right);
}

void PrintPreorder(treeNode *node)
{
        if(node==NULL)
        {
                return;
        }
        printf("%d ",node->data);
        PrintPreorder(node->left);
        PrintPreorder(node->right);
}

void PrintPostorder(treeNode *node)
{
        if(node==NULL)
        {
                return;
        }
        PrintPostorder(node->left);
        PrintPostorder(node->right);
        printf("%d ",node->data);
}

int main()
{
        treeNode *root = NULL;




		while(1)
		{
		int x=0;
		char n;
		printf("\n1.Insert node\n2.Preorder print\n3.Inorder print\n4.Postorder print\n5.Searching a node\n6.Deleting a node\n7.Exit\n");
		printf("Enter your choice:\n");
		n=getchar();
			switch(n)
		{
		case'1':
		{
			int p;
			printf("Enter value:");
			scanf("%d",&p);
		    root=Insert(root, p);
			break;
		}



		/*root = Insert(root, 5);
        root = Insert(root, -1);
        root = Insert(root, 3);
        root = Insert(root, -14);
        root = Insert(root, 8);
        root = Insert(root, 10);
        root = Insert(root, 9);
        root = Insert(root, 6);
        PrintInorder(root);
        printf("\n");*/



        case'2':
		{

				PrintPreorder(root);
                printf("\n");

			    break;
		}
		case'3':
		{

				PrintInorder(root);
                printf("\n");

			    break;
		}
        case'4':
		{

				PrintPostorder(root);
                printf("\n");

			    break;
		}





		case'5':
		{

				int p;
				printf("Which data do you want to search?\n");
				scanf("%d",&p);


			    treeNode * temp;
			    temp = FindMin(root);
			    printf("Minimum element is %d\n",temp->data);
			    temp = FindMax(root);
			    printf("Maximum element is %d\n",temp->data);
				temp = Find(root,p);


			if(temp==NULL)
        {
                printf("Element %d not found\n",p);
        }
        else
        {
                printf("Element %d Found\n",p);
        }

			    break;
		}
		case'6':
			{
                int p;


				printf("Which data do you want to delete:");
			    scanf("%d",&p);


				root = Delete(root,p);
		        PrintInorder(root);
				break;
			}

		case'7':
			{
				exit(0);
				break;
			}

			}

		}

getchar();
}
