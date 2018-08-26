#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left,*right;
};
struct node *root=NULL,*temp,*trav;
void create();
void pre_order(struct node*);
void in_order(struct node*);
void post_order(struct node*);
void insert();
void search();
int main()
{
	int ch;
	while(1)
	{
		printf("\n1 to create BST\n2 for pre order traverse\n3 for in-order traverse\n4 for post-order traverse\n5 for insert\n6 to search\nany other to exit : ");
		scanf("%d",&ch);
		if (ch==1)create();
		else if(ch==2)pre_order(root);
		else if(ch==3)in_order(root);
		else if(ch==4)post_order(root);
		else if(ch==5)insert();
		else if(ch==6)search();
		else break;
	}
	return 0;
}
void create()
{
	int n,i;
	printf("enter the number of nodes : ");
	scanf("%d",&n);
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
trav=root;
}
void pre_order(struct node* trav)
{
	if(trav==NULL)
		return;
	else
	{
		printf("%d\n",trav->data);
		pre_order(trav->left);
		pre_order(trav->right);
	}
trav=root;
}

void in_order(struct node* trav)
{
	if(trav==NULL)
		return;
	else
	{
		pre_order(trav->left);
		printf("%d\n",trav->data);
		pre_order(trav->right);
	}
trav=root;
}
void post_order(struct node* trav)
{
	if(trav==NULL)
		return;
	else
	{
		pre_order(trav->left);
		pre_order(trav->right);
		printf("%d\n",trav->data);
	}
trav=root;
}
void insert()
{

        temp=(struct node*)malloc(sizeof(struct node));
		temp->right=NULL;temp->left=NULL;
		printf("enter the data for node : ");
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
void search()
{
	int num,flag=0,count=0;
	printf("enter the number to search : ");
	scanf("%d",&num);
	trav=root;
	while(trav!=NULL)
	{
		if(num>trav->data)
		{
			trav=trav->right;
			count++;
		}
		else if(num<trav->data)
		{
			trav=trav->left;
			count++;
		}
		else if(trav->data==num)
		{
		flag=1;
		break;
		}
	}
	if(flag==1)
	{
		printf("entered number is present at level %d\n",count);
	}
	else
	{
		printf("entered number not found");
	}
}


