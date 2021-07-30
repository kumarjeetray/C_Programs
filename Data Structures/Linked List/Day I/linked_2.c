#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};


struct node *head,*newnode,*temp;

void insert()
{
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("Enter data:");
	scanf("%d",&newnode->data);
	newnode->next = NULL;
	if(head == NULL)
	{
		head=newnode;
		temp=newnode;
	}
	else
	{
		temp->next = newnode;
		temp=newnode;
	}
}

void traverse()
{
	temp=head;
	while(temp!=NULL)
	{
		printf("%d\n",temp->data);
		temp=temp->next;
	}
}

int main()
{
	head = NULL;
	int number,i;
	printf("Enter the no of nodes:");
	scanf("%d",&number);
	for(i=0;i<number;i++)
	{
		insert();
	}
	traverse();
	return 0;
}
