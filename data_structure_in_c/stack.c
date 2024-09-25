#include<stdio.h>
#include<conio.h>

#define ARR 10

struct stack
{
    int a[ARR];
    int top;
};

void init_stack(struct stack *);
void push(struct stack* ,int item);
int pop(struct stack *);

void main()
{
    struct stack s;
    int i;


    init_stack(&s);

    push(&s,8);
    push(&s,20);
    push(&s,-4);
    push(&s,15);
    push(&s,18);

    i = pop(&s);
    printf("\n\n Item popped %d" , i);


    i = pop(&s);
    printf("\n\n Item popped %d" , i);

    i = pop(&s);
    printf("\n\n Item popped %d" , i);

    i = pop(&s);
    printf("\n\n Item popped %d" , i);


}

void init_stack(struct stack *s)
{
    s->top = -1;
}



void push(struct stack* s ,int item)
{
    if(s-> top == ARR-1)
    {
        printf("\n Stack is full");
    }
    s-> top++;
    s-> a[s -> top] = item;
}

int pop(struct stack *s)
{

    int data;
    if( s -> top == -1)
    {
        printf("\n stack is empty");
        return NULL;88i
    }
    data = s-> a[s->top];
    s -> top--;
    return data;
}
