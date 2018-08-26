#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *prev, *next;
};
void create();
void view();
void sort_link();
void sort_data();
void rev();
struct node *head=NULL,*tail=NULL,*trav,*temp;
int main()
{
	int ch;
	while(1)
	{
		printf("\nSorting and Reversing Doubly Linked list\n1 to create\n2 to view\n3 to sort by links\n4 to sort by data\n5 to reverse the list\nothers to exit\nYour Choice : ");
		scanf("%d",&ch);
		if(ch==1) create();
		else if (ch==2) view();
		else if (ch==3) sort_link();
		else if (ch==4) sort_data();
		else if (ch==5) rev();
		else break;
	}
}
int n;/* no of nodes*/
void create()
{
	head=NULL;
	printf("enter the number of nodes : ");
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		temp=(struct node*)malloc(sizeof(struct node));
		temp->next=NULL;temp->prev=NULL;
		printf("enter data for node %d :",i+1);
		scanf("%d",&temp->data);
		if(head==NULL)
		{
			head=temp;
			tail=temp;
		}
		else
		{
			tail->next=temp;
			temp->prev=tail;
			tail=temp;
		}
	}
}
void view()
{

	trav=head;
	if(trav==NULL)
	printf("Empty List!!");
	else
	{
		printf("Linked List : \n\n");
		while(trav!=tail->next)
		{
			printf("%d \t",trav->data);
			trav=trav->next;
		}
		printf(" \n\n");
	}
}
void sort_link()
{
	int i;struct node *trav1,*trav2;
	if(head==NULL)
		printf("Empty List\n");
	else if(head==tail)
		printf("Single Node, Already Sorted\n");
	else
	{
	
	for(i=0;i<n;i++)
	{
		trav1=head,trav2=head->next;
		while(trav2!=NULL)
		{
			if(trav1->data>trav2->data)
			{
				if(trav1==head)
				{
					trav1->next=trav1->next->next;
					trav2->next->prev=trav1;
					trav2->next=trav1;
					trav1->prev=trav2;
					trav2->prev=NULL;
					head=trav2;
					trav2=trav1->next;
				}
				else if(trav2==tail)
				{
					trav1->prev->next=trav2;
					trav2->next=trav1;
					trav2->prev=trav1->prev;
					trav1->prev=trav2;
					trav1->next=NULL;
					tail=trav1;
					trav2=trav1->next;
				}
				else
				{
					trav1->prev->next=trav2;
					trav2->next->prev=trav1;
					trav1->next=trav2->next;
					trav2->prev=trav1->prev;
					trav2->next=trav1;
					trav1->prev=trav2;
					trav2=trav1->next;
				}
			}
			else
			{
				trav1=trav1->next;
				trav2=trav2->next;
			}
		}
	}
	}
}
void sort_data()
{

	int i,t;struct node *trav1,*trav2;
	if(head==NULL)
		printf("Empty List\n");
	else if(head==tail)
		printf("Single Node, Already Sorted\n");
	else
	{
	
	for(i=0;i<n;i++)
	{
		trav1=head,trav2=head->next;
		while(trav2!=NULL)
		{
			if(trav1->data>trav2->data)
			{
				t=trav1->data;
				trav1->data=trav2->data;
				trav2->data=t;
			}
			trav1=trav1->next;
			trav2=trav2->next;
		}
	}
	}
}
void rev()
{
	struct node *tail2; int i,t;
	tail2=tail;
	for(i=0;i<n;i++)
	{
		trav=head;
		while(trav!=tail2)
		{
			t=trav->data;
			trav->data=trav->next->data;
			trav->next->data=t;
			trav=trav->next;
		}
		tail2=tail2->prev;
	}
}

