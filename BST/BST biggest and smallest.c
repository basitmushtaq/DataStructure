#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left,*right;
};
struct node *trav,*root=NULL,*temp;
void create()
{
	int n,i;
	printf("enter the number of nodes : ");
	scanf("%d",&n);
	printf("_______________________________\n");
	for(i=0;i<n;i++)
	{
		temp=(struct node*)malloc(sizeof(struct node));
		temp->right=NULL;temp->left=NULL;
		printf("enter the data for node %d : ",i+1);
		scanf("%d",&temp->data);
		if(root==NULL)
		{
			root=temp;
		}
		else
		{
			trav=root;
			while(1)
			{
				if(temp->data>trav->data)
				{
					if(trav->right==NULL)
					{
						trav->right=temp;
						break;
					}
					else
						trav=trav->right;
				}
				else if(temp->data<trav->data)
				{
					if(trav->left==NULL)
					{
						trav->left=temp;
						break;
					}
					else
						trav=trav->left;
				}
				else
				{
					printf("duplicate entry");
					break;
				}
			}
		}
	}
}
int smallest(struct node* toor)
{

	if(toor->left==NULL)
	{
		return toor->data;
	}
	else
	{
		smallest(toor->left);
	}
}
int greatest(struct node* toor)
{

	if(toor->right==NULL)
	{
		return toor->data;
	}
	else
	{
		greatest(toor->right);
	}
}
int main()
{
	int small,large;	
	printf("_____CREATE A BST___\n--------------------\n");
	create();
	small=smallest(root);
	large=greatest(root);
	printf("-------------------------------------------------------\n");
	printf("Largest NUmber is %d and Smallest Number is %d\n__________________________________________________\n",large,small);
}
