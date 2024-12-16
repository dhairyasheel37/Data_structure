#include<stdio.h>
#define size 5
typedef struct queue
{
	int arr[size];
	int fr,rr;
}que;

void init(que *q);
void enqueue(que *q,int value);
int dequeue(que *q);
int peek(que *q);
int empty(que *q);
int full(que *q);

int main()
{
	que q;
	init(&q);
	int ch,value;
	do{
		printf("\n0. Exit\n");
		printf("1. enqueue\n");
		printf("2. dequeue\n");
		printf("3. peek\n");
		printf("4. print \n");
		printf("Enter the choice :");
		scanf(" %d",&ch);

		switch(ch)
		{
			case 1 :
				if(full(&q))
				printf("The stack is full. \n");
				else
				{
					printf("Enter the enqueue value :");
					scanf("%d",&value);
					enqueue(&q,value);
				}
				break;
			case 2 :
				if(empty(&q))
				printf("Stack is empty .\n");
				else
				{
					printf("The dequeue element is %d.\n",dequeue(&q));
				}
				break;
			case 3 :
				if(empty(&q))
				printf("Stack is empty .\n");
				else
				{
					printf("The peek element is %d.\n",peek(&q));
				}
				break;
			case 4 :
				if(empty(&q))
				printf("Stack is empty .\n");
				else
				{
					for(int i=q.fr+1;i<=q.rr;i++)
					{
						printf(" %d = %d\n",i,q.arr[i]);	
					}	
				}
		}
		
	}while(ch != 0);

}

void init(que *q)
{
	q->fr = q->rr = -1;
}
void enqueue(que *q,int value)
{
	q->rr++;
	q->arr[q->rr]=value;
}
int dequeue(que *q)
{	int temp = q->arr[q->fr+1];
	q->fr++;
	if(q->fr == q->rr)
	q->fr = q->rr = -1;
	return temp;
}
int peek(que *q)
{
	return q->arr[q->fr+1];
}
int empty(que *q)
{
	return q->rr == q->fr;
}
int full(que *q)
{
	return q->rr == size-1;
}
	

	
		
	
	
	
	
		
	
		
	
	
	
	
	
	
			