#include<stdio.h>
#include<stdlib.h>
struct node
{
 
	int data;
	struct node * next;
};
 
 
int enqueue(struct node ** fr,struct node ** rr,  int n)
{
	struct node * p,*temp;
	p = (struct node*)malloc(sizeof(struct node));
	if(*fr == NULL && *rr == NULL)
	{
		p->data = n;
		*fr=*rr=p;
		p->next = NULL;
		return 1;
	}
	else
	{
		temp = *rr;
		p->data = n;
		p->next = NULL;
		*rr = p;
 
		temp->next = p;
	return 1;
	}
 
 
}
int dequeue(struct node **fr ,struct  node **rr)
{
	struct node *temp;
 
	if(*fr == NULL && *rr == NULL)
	{
		return -1;
	}
	else
	{
		temp=*fr;
		*fr=temp->next;
		free(temp);
		return 1;
	}
 
}
 
 
void display(struct node *fr) {
     struct node *p = fr;
    if (p == NULL) {
        printf("empty\n");
        return;
    }
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
 
int main()
{
	struct node * fr;
	struct node * rr;
	fr = NULL;
	rr = NULL;
	int ch,data,r;
	while(1)
	{
		if(ch==-1)
		break;
		printf("Enter the chioce :");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				printf("Enter the data :");
				scanf("%d",&data);
				r = enqueue(&fr,&rr,data);
				if(r==1)
				{
					printf("enqueue\n");
				}
				else
				{
					printf("error\n");
				}
				break;
			case 2:
				display(fr);
				break;
			case 3:
				r = dequeue(&fr,&rr);
				if(r==1)
				{
					printf("enqueue\n");
				}
				else
				{
					printf("error\n");
				}
				break;
 
				default :
				printf("wrong choice\n");
		}		
 
	}
}
