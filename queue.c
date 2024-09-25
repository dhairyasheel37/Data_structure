#include<stdio.h>
#define size 5
struct queue
{
	int arr[size];
	int fr;
	int rr;
};
void init_queue(struct queue *);

int enqueue(struct queue *, int );

int dequeue(struct queue *);

int retrive(struct queue );


int main()
{
	struct queue q;
	int choice = 1,data,option = 0,f,position;
	init_queue(&q);

	while(option != -1)
	{
		printf("enqueue 1\n");
		printf("dequeue 2\n");
		printf("retrive 3\n");
                printf("Enter the option : ");
		scanf("%d",&option);
		switch(option)
		{
			case 1:
				printf("Enter the element :");
				scanf("%d",&data);
				f = enqueue(&q,data);
				if(f == -1)
				{
					printf("queue is full\n");
					printf("\n");
				}
				else
				{
					printf("enqueue is succesful \n");
					printf("\n");
				}
				break;

			case 2:

				f= dequeue(&q);
				if(f == -1)
				{
					printf("queue is empty\n");
					printf("\n");
				}
				else
				{
					printf("dequeue is %d \n",f);
					printf("\n");
				}
				break;
			case 3:
				f=retrive(q);
				if(f == -1)
				{
					printf("queue is empty\n");
					printf("\n");
				}
				else
				{
					printf("element at ff is %d ",f);
				}
				break;
			default :
				printf("wrong option \n");

		}

		printf("\n");
	}
}







void init_queue(struct queue *q)
{
	q->fr = -1;
	q->rr = -1;
}


int enqueue(struct queue *q, int data)
{
	if( q-> rr == size-1)
	{
		return -1;
	}
	else if( q-> fr == -1 && q-> rr == -1)
	{
		q-> fr =0;
		q -> rr = 0;
	}
	else
	{
		(q->rr)++;
	}
	q -> arr[q-> rr] =data;
	return data;

}

int dequeue(struct queue *q)
{
        int data;

	if( q-> rr == -1)
	return -1;

	data = q->arr[q-> fr];
    if( q-> fr ==  q-> rr )
	{
		(q -> fr)= -1;
		(q -> rr)= -1;
	}
	else
	{
		(q->fr)++;

	}
	return data;
}

int retrive(struct queue q)
{
	if(q.fr == -1)
	{
		return -1;
	}
	else
	{
		return q.arr[q.fr];
	}
}
