#include<stdio.h>
#include<stdlib.h>
 
typedef struct linklist
{
	int data;
	struct linklist * next;
}node;
 
void *create_node(int value)
{
	node *newnode = (node*)malloc(sizeof(node));
	newnode->data = value;
	newnode->next = NULL;
	return newnode;
}
 
void add_first(node ** head,int value)
{
	node* newnode = create_node(value);
	if(*head == NULL)
	*head = newnode;
	else
	{
		newnode->next = *head;
		*head = newnode;
	}
}
 
void add_last(node ** head ,int value)
{
	node * newnode = create_node(value);
	if(*head == NULL)
	*head = newnode;
	else
	{
		node *trav = *head;
		while(trav->next != NULL)
			trav = trav->next;
 
		trav->next = newnode;
	}
}
 
void at_position(node**head,int value,int pos)
{
	node * newnode = create_node(value);
	if(*head == NULL)
	*head = newnode;
	else
	{
		node *trav = *head;
		for(int i = 1;i<pos-1;i++)
			trav = trav->next;
 
		if(trav->next->next == NULL)
		{
			add_last(head,value);
			return;
		}
		newnode->next = trav ->next;
		trav->next = newnode;
	}
}
 
void print(node ** head)
{
	node *trav = *head;
	printf("List :");
	while(trav!=NULL)
	{
		printf(" %d",trav->data);
		trav = trav->next;
	}
	printf("\n");
}
 
void delete_begin(node ** head)
{
	if(*head == NULL)
	return;
	else
	{
		node *temp = *head;
		*head = temp->next;
		free(temp);
	}
}
 
void delete_end(node ** head)
{
	if(*head == NULL)
	return;
	else
	{
		node *trav = *head;
		while(trav->next->next != NULL)
		{
			trav = trav->next;
		}
		free(trav->next);
		trav->next = NULL;
	}
}
 
void delete_at(node **head,int pos)
{
	if(*head == NULL)
	return;
	if(pos == 1)
	{
		delete_begin(head);
	}
	else
	{
		node *trav = *head;
		for(int i = 1;i<pos-1;i++)
		trav = trav->next;
		if(trav->next->next == NULL)
		{
			delete_end(head);
			return;
		}
		node *temp = trav;
		temp = trav->next;
		trav->next = trav->next->next;
		free(temp);
	}
}
 
int main()
{
	node *head;
	head = NULL;
	int ch,value,pos;

	do
	{
		printf("0. Exit\n");
		printf("1.insert at begin\n");
		printf("2.intsert at end\n");
		printf("3.insert at postion \n");
		printf("4.Delete at begin\n");
		printf("5.Delete at end\n");
		printf("6.Delete at postion \n");
		printf("7. Print\n");
		printf("Enter the choice :");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1:
				printf("Enter the value :");
				scanf("%d",&value);
				add_first(&head,value);
				break;
			case 2:
				printf("Enter the value :");
				scanf("%d",&value);
				add_last(&head ,value);
				break;
			case 3:
				printf("Enter the value :");
				scanf("%d",&value);
				printf("Enter the position :");
				scanf("%d",&pos);
				at_position(&head,value,pos);
				break;
			
			case 4:
				delete_begin(&head);
				break;
			case 5:
				 delete_end(&head);
				break;
			case 6:
				printf("Enter the position :");
				scanf("%d",&pos);
				delete_at(&head,pos);
				break;
			case 7:
				print(&head);	
		}
		
		
	}while(ch!=0);
	
	add_first(&head,10);
	add_first(&head,5);	
	add_last(&head,20);
	add_last(&head,30);
	add_last(&head,40);
 
	print(&head);
	//delete_begin(&head);
	//delete_end(&head);
	delete_at(&head,3);
	delete_at(&head,4);
	print(&head);
	return 0;
}