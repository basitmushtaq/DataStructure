#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next,*prev;
};
struct node *head=NULL,*tail=NULL,*temp,*trav;
void create();
void view();
void insert(int);
void delete(int);
int main()
{
	int n,ch;
	while(1)
	{
		printf("\n1 to create\n2 to view\n3 to insert\n4 to delete\nother to exit\nYour Choice : ");
		scanf("%d",&ch);
		if(ch==1) create();
		else if (ch==2) view();
		else if (ch==3) 
		{
			printf("enter the number to be inserted");
			scanf("%d",&n);
			insert(n);
		}
		else if(ch==4)
		{
			printf("enter the node to be deleted");
			scanf("%d",&n);
			delete(n);
		}
		else break;
	}
}
void create()
{
	int i,n;
	printf("enter the number of nodes : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		temp=(struct node*)malloc(sizeof(struct node));
		temp->prev=temp->next=NULL;
		printf("enter the data for node %d : ",i+1);
		scanf("%d",&temp->data);
		if(head==NULL)
		{
			head=temp;
			tail=temp;
		}
		else
		{
			if(temp->data<=head->data)
			{
				temp->next=head;
				head->prev=temp;
				head=temp;
			}
			else if(temp->data>tail->data)
			{
				tail->next=temp;
				temp->prev=tail;
				tail=temp;
			}
			else
			{
				trav=head;
				while(trav!=NULL)
				{
					if(trav->data>=temp->data)
					{
						trav->prev->next=temp;
						temp->prev=trav->prev;
						temp->next=trav;
						trav->prev=temp;
						break;
					}
					else
						trav=trav->next;
				}
			}
		}
	}
}
void view()
{
	trav=head;
	if(head==NULL) printf("EMPTY LIST!\n");
	else
	{
		while(trav!=NULL)
		{
			printf("%d\t",trav->data);
			trav=trav->next;
		}
	}
}
void insert(int item)
{
	temp=(struct node*)malloc(sizeof(struct node));
	temp->next=temp->prev=NULL;
	temp->data=item;
	
			if(temp->data<=head->data)
			{
				temp->next=head;
				head->prev=temp;
				head=temp;
			}
			else if(temp->data>tail->data)
			{
				tail->next=temp;
				temp->prev=tail;
				tail=temp;
			}
			else
			{
				trav=head;
				while(trav!=NULL)
				{
					if(trav->data>=temp->data)
					{
						trav->prev->next=temp;
						temp->prev=trav->prev;
						temp->next=trav;
						trav->prev=temp;
						break;
					}
					else
						trav=trav->next;
				}
			}
}
void delete(int item)
{
	if(head->data==item)
	{
		head->next->prev=NULL;
		temp=head;
		head=head->next;
		free(temp);
	}
	else if(tail->data==item)
	{
		tail->prev->next=NULL;
		temp=tail;
		tail=tail->prev;
		free(temp);
	}
	else
	{
		trav=head;int flag=0;
		while(trav!=NULL)
		{
			if(trav->data==item)
			{
				flag=1;
				break;
			}
			else
				trav=trav->next;
		}
		if(flag==0)
		{
			printf("item Not Found");
		}
		else
		{
			trav->prev->next=trav->next;
			trav->next->prev=trav->prev;
			free(trav);
		}
	}
}


