#include<stdio.h>
#include<stdlib.h>
void create();
void insert();
void del();
void view();
int n=-1,A[100],i;
int main()
{
	int ch;
	while(1)
	{
		printf("\nArrays :\n1 to Create\n2 to View\n3 to Insert\n4 to Delete\nOthers to exit\nYour Choice : ");
		scanf("%d",&ch);
		if (ch==1)
		{
			printf("enter the number of nodes(max=100) : ");
			scanf("%d",&n);
			create();
		}
		else if (ch==2) view();
		else if(ch==3) insert();
		else if(ch==4) del();
		else break;
	}
}
void create()
{
	if(n>100)
		printf("Value Not Allowed");
	else
	{
	for(i=0;i<n;i++)
	{
		printf("enter value for node %d : ",i+1);
		scanf("%d",&A[i]);
	}
	}
}
void view()
{
	if(n<0)
		printf("empty array");
	else
	{
	printf("ARRAY\n\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t",A[i]);
	}
	printf("\n\n");
	}
}
void del()
{
	int item,flag=0;
	printf("enter the element to be deleted : ");
	scanf("%d",&item);
	if(n==-1)
	{
		printf("empty Array");
	}
	else
	{
	for(i=0;i<n;i++)
	{
		if(A[i]==item)
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		printf("element not found!!");
	}
	else
	{
		for(i;i<n-1;i++)
		{
			A[i]=A[i+1];
		}
		n=n-1;
	}
	}
}
void insert()
{
	int item,target,ch,j,flag=0;
	if(n>100)
	{
		printf("Max Size Reached, Can't Insert");
	}
	else
	{
		printf("enter the new element : ");
		scanf("%d",&item);
		printf("Enter the target element : ");
		scanf("%d",&target);
		for(i=0;i<n;i++)
		{
			if(A[i]==target)
			{
				flag=1;
				break;
			}
		}
		if(flag==0) printf("target not found");
		else
		{
		printf("Do you want to insert :\n1) Before or 2) After the target\n Your Choice(1/2)");
		scanf("%d",&ch);
		if(ch==1)
		{
			for(j=n;j>=i;j--)
			{
				A[j+1]=A[j];
			}
			A[i]=item;
			n=n+1;
		}
		else if(ch==2)
		{
			for(j=n;j>i;j--)
			{
				A[j+1]=A[j];
			}
			A[i+1]=item;
			n=n+1;
		}
		}
	}
}

