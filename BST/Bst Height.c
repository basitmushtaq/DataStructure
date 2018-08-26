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


int disph(struct node *toor)
{
	if(toor==NULL)
		return 0;
	else
	{
		int l=disph(toor->left);
		int r=disph(toor->right);
		if(l>r)
		return(l+1);
		else
		return(r+1);
	}
}
int main()
{
	printf("_____CREATE A BST___\n--------------------\n");
	create();
	printf("-------------------------------------------------------\n Height Of Tree :\n");
	int h=disph(root);
	printf("%d\n",h);
}
