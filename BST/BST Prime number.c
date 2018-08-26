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
void prime_no(struct node* toor)
{
	int flag=0,i;
	if(toor==NULL)
	return;
	else	
	{
		for(i=2;i<toor->data;i++)
		{
			if(toor->data%i==0)
			{
				flag=1;
				break;
			}
			
		}
		if (flag==0) printf("%d\n",toor->data);
		prime_no(toor->left);
		prime_no(toor->right);
	}

}
int main()
{
	printf("_____CREATE A BST___\n--------------------\n");
	create();
	printf("-------------------------------------------------------\nPrime Numbers :\n");
	prime_no(root);
}
