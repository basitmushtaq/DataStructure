#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL,*tail=NULL,*temp,*trav;
void create();
void view();
void insert(int);
void delete(int);
int main()
{
	int ch,n;
	while(1)
	{
		printf("\nLinked Lists\n1 to create\n2 to View\n3 to Insert\n4 to delete\nothers to exit\nYour Choice : ");
			scanf("%d",&ch);
		if(ch==1) create();
		else if(ch==2) view();
		else if(ch==3)
		{
			printf("enter the Number to be Inserted : ");
			scanf("%d",&n);
			insert(n);
		}
		else if(ch==4)
		{
			printf("enter the node to be deleted : ");
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
		temp->next=NULL;
		printf("enter data for node %d :",i+1);
		scanf("%d",&temp->data);
		if(head==NULL)
		{
			head=temp;
			tail=temp;
		}
		else if(temp->data<=head->data)
			{
				temp->next=head;
				head=temp;
			}
			else if(temp->data>=tail->data)
			{
				tail->next=temp;
				tail=temp;
			}
			else
			{
				trav=head;
				while(trav!=tail)
				{
					if(trav->next->data>=temp->data)
					{
						temp->next=trav->next;
						trav->next=temp;
						break;
					}
					else
						trav=trav->next;
				}
			}
	}
	}

	void view()
	{
		trav=head;
		while(trav!=NULL)
		{
			printf("%d\t",trav->data);
			trav=trav->next;
		}
	}
	void insert(int item)
	{
		temp=(struct node*)malloc(sizeof(struct node));
		temp->data=item;
		temp->next=NULL;

			if(temp->data<head->data)
			{
				temp->next=head;
				head=temp;
			}
			else if(temp->data>tail->data)
			{
				tail->next=temp;
				tail=temp;
			}
			else
			{
				trav=head;
				while(trav!=tail)
				{
					if(trav->next->data>temp->data)
					{
						temp->next=trav->next;
						trav->next=temp;
						break;
					}

					else
						trav=trav->next;
				}
			}
	}
	void delete(int item)
	{
        int flag=1;
        if (head==NULL)
        printf("empty list\n");
        else
        {
		if(head->data==item)
		{
			temp=head;
			head=head->next;
			free(temp);
		}
		else
		{
        trav=head;
		while(trav!=NULL)
		{
			if(trav->next->data==item)
			{
			flag=2;
			break;
			}
			else
			trav=trav->next;
		}

		if(flag==1)
		{
			printf("Node Not Found\n");
		}

		else
		{
			temp=trav->next;
			trav->next=temp->next;
			free(temp);
			if(trav->next==NULL)
			{
			tail=trav;
			}
        }
        }
    }
}




