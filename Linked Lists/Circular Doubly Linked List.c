#include<stdlib.h>
#include<stdio.h>
struct node
{
    int data;
    struct node *prev,*next;
};
struct node *head=NULL,*tail=NULL,*temp,*trav;
void create();
void view();
void insert();
void del();
main()
{
    int n;
    while (1)
    {
        printf("\n1 to create\n2 to view\n3 to insert\n4 to delete\n5 to exit\nYour Choice :");
        scanf("%d",&n);
        if(n==1) create();
        else if(n==2) view();
        else if(n==3) insert();
        else if (n==4) del();
        else if(n==5) break;
        else printf("invalid choice");
    }

}
void create()
{
    int i,n;
    printf("enter the number of nodes :");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        printf("enter the data for node %d :",(i+1));
        scanf("%d",&temp->data);
        temp->prev=temp->next=NULL;
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
	    tail->next=head;
	    head->prev=tail;
        }
    }
}
void view()
{
    trav=head;
    if (head==NULL)
    printf("Empty Linked List\n");
    else
    {
    do
    {
        printf("%d\t",trav->data);
        trav=trav->next;
    }
    while(trav!=tail->next);
    }
}
void insert()
{
    int c,item;
    temp=(struct node*)malloc(sizeof(struct node));
    trav=head;

    printf("enter the node of insertion :");
    scanf("%d",&item);
    printf("enter the new node :");
    scanf("%d",&temp->data);


     while(item!=trav->data)
        {
            trav=trav->next;
        }
    printf("1 for pre-insertion\n2 for post insertion :");
    scanf("%d",&c);
    if(c==1)
    {
        if(trav==head)
      {
          temp->next=head;
          head->prev=temp;
          head=temp;
      }
      else
      {
          temp->next=trav;
      temp->prev=trav->prev;
      trav->prev->next=temp;
      trav->prev=temp;
      }

    }
    else if(c==2)
    {
         if(trav==tail)
        {
            tail->next=temp;
            temp->prev=tail;
            tail=temp;
        }
        else
        {
        temp->next=trav->next;
        temp->prev=trav;
        temp->next->prev=temp;
        trav->next=temp;
        }

    }
}
void del()
{
    trav=head; int item;
    printf("enter the node to be deleted :");
    scanf("%d",&item);
    while(item!=trav->data)
    {
        trav=trav->next;
    }
    trav->next->prev=trav->prev;
    trav->prev->next=trav->next;
    if (trav==head)
    {
        head=head->next;
    }
    else if(trav==tail)
    {
        tail=tail->prev;
    }
    free(trav);
}
