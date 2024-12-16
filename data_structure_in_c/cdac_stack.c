#include<stdio.h>
#define n 5
typedef struct stack{
	int arr[n];
	int top;
}stack_t;

void stack_init(stack_t *st);
void stack_push(stack_t *st, int value);
int stack_pop(stack_t *st);
int peek(stack_t *st);
int stack_empty(stack_t *st);
int stack_full(stack_t *st);

int main()
{
	stack_t st;
	int choice,value;
	stack_init(&st);
	
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
					stack_push(&st,value);
				}
					break;
			case 2 :
				if(stack_empty(&st))
				printf("Stack is empty .\n");
				else
				{
					printf("The poped element is %d.\n",stack_pop(&st));
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
					for(int i=0;i<n;i++)
					{
						printf(" %d = %d\n",i,st.arr[i]);	
					}	
				}
		}
		
	}while(choice != 0);
	

}

void stack_init(stack_t *st)
{
	st->top = -1;
}
void stack_push(stack_t *st, int value)
{
	st->top++;

	st->arr[st->top] = value;
}

int stack_pop(stack_t *st)
{
	int temp = st->arr[st->top];

	st->top--;
	return temp;
}
int peek(stack_t *st)
{
	return st->arr[st->top];
}
int stack_empty(stack_t *st)
{
	return st->top == -1;
}
int stack_full(stack_t *st)
{
	return st->top == n-1;
}
