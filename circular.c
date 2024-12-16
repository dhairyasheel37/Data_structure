#include<stdio.h>
#include <stdlib.h>
typedef struct circular_linlist
{
    int data;
    struct circular_linlist *next;
}node;

void print(node ** head)
{
	node *trav = *head;
	printf("List :");
	do
    {
        printf(" %d",trav->data);
		trav = trav->next;
    } while ((trav!=*head));
    
	printf("\n");
}

void *create_node(int value);
void add_first(node **head,node **tail,int value);
void add_last(node **head,node **tail,int value);
void at_position(node **head,node **tail,int value,int pos);
void delete_begin(node **head,node **tail);
// void delete_end(node **head);
// void delete_at(node **head,int pos);
// void print(node **head);

int main(){
    node *head = NULL;
	node *tail = NULL;
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
				add_first(&head,&tail,value);
				break;
			case 2:
				printf("Enter the value :");
				scanf("%d",&value);
				add_last(&head,&tail ,value);
				break;
			case 3:
				printf("Enter the value :");
				scanf("%d",&value);
				printf("Enter the position :");
				scanf("%d",&pos);
				at_position(&head,&tail,value,pos);
				break;
			
			case 4:
				delete_begin(&head,&tail);
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
    return 0;
}

void *create_node(int value)
{
	node *newnode = (node*)malloc(sizeof(node));
	newnode->data = value;
	newnode->next = NULL;
	return newnode;
}

void add_first(node **head,node **tail,int value)
{
    node *newnode = create_node(value);
    if(*head == NULL)
    {
        *head= *tail = newnode;
        (*tail)->next = *head;

    }
    else{
        newnode->next = *head;
        (*tail)->next = newnode;
        *head = newnode;

    }
}
void add_last(node **head,node **tail,int value)
{
    node *newnode = create_node(value);
    if(*head == NULL)
    {
        *head= *tail = newnode;
        (*tail)->next = *head;
        return;
    }
    else
    {
        newnode->next = *head;
        (*tail)->next = newnode;
        *tail = newnode;
       
    }
}

void at_position(node **head,node **tail,int value,int pos)
{
    if(pos<1)
    return;
    node *newnode = create_node(value);
    if(*head == NULL)
    {
        *head= *tail = newnode;
        (*tail)->next = *head;
        return;
    }
    else if(pos == 1)
    {
        add_first(head,tail,value);
        return;
    }
    else
    {
        node* trav = *head;
        for(int i=1;i<pos-1;i++)
        {
            trav = trav->next;
        }
        if(trav->next->next == NULL)
        {
            add_last(head,tail,value);
            return;
        }
        newnode->next = trav->next;
        trav->next = newnode;
        return;
    }
}
void delete_begin(node **head,node **tail)
{
    if(*head == NULL)
    return;
    else if((*head)->next == *head)
    {
        free(*head);
        *head=*tail=NULL;
    }
    else
    {
        node *trav = 
    }
}
void delete_end(node **head)
void delete_at(node **head,int pos)
void print(node **head)