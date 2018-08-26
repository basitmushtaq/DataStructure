#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
int i;
struct node *head=NULL, *tail=NULL, *temp1,*temp, *trav;
void insert();
void Delete();
void create();
void view();
main()
{
    int n;
    while(1)
    {
        printf("\nLinked Lists\n1 for create\n2 for view\n3 for delete\n4 for insert\nothers for exit\nyour choice : ");
        scanf("%d",&n);
    if(n==1) create();
    else if (n==2) view();
    else if (n==3) Delete();
    else if (n==4) insert();
    else break;
    }
}
    int m;
void create()
{
    printf("enter the number of nodes :");
    scanf("%d",&m);
    for(i=1;i<=m;i++)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        printf("enter the data\n");
        scanf("%d",&temp->data);
        temp->next=NULL;
        if(head==NULL)
        {
            head=temp;
            tail=temp;
        }
        else
        {
            tail->next=temp;
            tail=temp;
	    tail->next=head;
        }
    }
}
void view()
{
    if(head==NULL)
    {
        printf("Empty string\n");
    }
    else{
    trav=head;
    do
    {
        printf("%d\t",trav->data);
        trav=trav->next;
    }
while(trav!=tail->next);
    }
}
void Delete()
{
    int item,i=0,x=0;
    printf("enter the instances to be deleted : ");
    scanf("%d",&item);
    trav=head;
  if(item==head->data)
        {
            temp=head;
            head=head->next;
	    tail->next=head;
            free(temp);
        }
  else
{
    do
    {
        x=x+1;
        trav=trav->next;
    }
	while(trav!=head);
    while(i<x)
        {
      
        
        {
             trav=head;
            while(trav->next->data!=item&&trav->next!=tail)
            {
                trav=trav->next;
            }
            if(trav->next->data!=item)
            {
                if(i==0)
                {
                    printf("element not found\n");
                }
                break;
            }
            else
            if(trav->next==tail)
            {
                temp=tail;
                tail=trav;
                free(temp);
            }
            else
            {
                temp=trav->next;
                trav->next=trav->next->next;
                free(temp);
            }
        }
        i++;
    }
 }
}
void insert()
{   int item1,item2,n=0,f=1;
    printf("enter the element to be inserted:");
    scanf("%d",&item1);
    while(f!=2){
    printf("1 for pre-insertion\n2 for post-insertion\nYour choice :");
    scanf("%d",&n);
    if(n==1||n==2)
    {
        f=2;
    }
    else
        printf("invalid choice, try again\n");
    }
    printf("enter the element of node of point of insertion \n(the first instance of the entered element will be used): ");
    scanf("%d",&item2);
    trav=head;
    if(head==NULL)
    {
        printf("No linked list found\n");
    }
    else
    {
    while(trav->data!=item2&&trav!=tail)
    {
        trav=trav->next;
    }
    if(trav->data!=item2)
    {
        printf("entered element not found in the list\n");
    }
    else{
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=item1;
    if(n==1)
    {
        if(head->data==item2)
        {
            temp->next=head;
            head=temp;
        }
        else
        {
             trav=head;
             while(trav->next->data!=item2)
             {
                 trav=trav->next;
             }
            temp->next=trav->next;
            trav->next=temp;
        }
    }
    else if(n==2)
    {
        if(item2==tail->data)
        {
            tail->next=temp;
            temp->next=head;
            tail=temp;
        }
        else
        {
            trav=head;
            while(trav->data!=item2)
            {
                trav=trav->next;
            }
            temp->next=trav->next;
            trav->next=temp;
        }
    }
    }
    }
}
