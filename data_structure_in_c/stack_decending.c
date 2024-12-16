#include<stdio.h>

#define size 4

typedef struct stack
{
	int arr[size];
	int top;
}stack_d;

void init(stack_d *st);
void push(stack_d *st, int value);
int pop(stack_d *st);
int peek(stack_d *st);
int stack_empty(stack_d *st);
int stack_full(stack_d *st);


int main()
{
	stack_d st;
	int choice,value;
	init(&st);
	
	do{
		printf("\n0. Exit\n");
		printf("1. push\n");
		printf("2. pop\n");
		printf("3. peek\n");
		printf("4. print \n");
		printf("Enter the choice :");
		scanf(" %d",&choice);

		switch(choice)
		{
			case 1 :
				if(stack_full(&st))
				printf("The stack is full. \n");
				else
				{
					printf("Enter the push value :");
					scanf("%d",&value);
					push(&st,value);
				}
					break;
			case 2 :
				if(stack_empty(&st))
				printf("Stack is empty .\n");
				else
				{
					printf("The poped element is %d.\n",pop(&st));
				}
				

				break;
			case 3 :
				if(stack_empty(&st))
				printf("Stack is empty .\n");
				else
				{
					printf("The poped element is %d.\n",peek(&st));
				}
				break;
			case 4 :
				if(stack_empty(&st))
				printf("Stack is empty .\n");
				else
				{
					for(int i=size-1;i<st.top;i--)
					{
						printf(" %d = %d\n",i,st.arr[i]);	
					}	
				}
				break;
		}
		
	}while(choice != 0);
	
}

void init(stack_d *st)
{
	st->top = size;
}
void push(stack_d *st, int value)
{
	st->top--;
	st->arr[st->top]=value;
}
int pop(stack_d *st)
{
	int temp = st->arr[st->top];

	st->top++;

	return temp;
}
int peek(stack_d *st)
{
	return st->top;
}
int stack_empty(stack_d *st)
{
	return st->top == size;
}
int stack_full(stack_d *st)
{
	return st->top == 0;
}