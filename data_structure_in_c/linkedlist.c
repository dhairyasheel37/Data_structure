#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * next;
};

int insert_at_begin(struct node  **head, int data)
{
    struct node *p;
    p= (struct node*)malloc(sizeof(struct node));//allocate memory for node
    p->data=data; // data into p
    p->next=*head;//null = next
    *head=p;   //give address to of p to head
    return 1;
}

int insert_at_end(struct node ** head , int data)
{
    struct node *p,*q;
    p= (struct node*)malloc(sizeof(struct node));
     if(*head == NULL)
     {
         p->data = data;
         p->next = NULL;
        *head=p;
        return 1;
     }
     else
     {
        q=*head;
        while(q->next != NULL)
        {
            q = q->next;
        }
        p->data = data;
        p->next = NULL;
        q->next = p;
        return 1;
     }


}

void display(struct node *head)
{

     if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    while (head->next != NULL)
    {
        printf("%d ",head->data);
        head = head->next;
    }
    printf("%d",head->data);

}


int main()
{
    struct node * head = NULL;
    int ch=0,r,data,pos;
    while (ch!=-1)
    {
        printf("\nEnter the 1 for inserte at begin\n");
        printf("Enter the 2 for insert at begin\n");
        printf("Enter the 3 for inser at specifc position \n");
        printf("Enter the 4 for display\n");
        printf("Enter the choice :");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1:
            {
                printf("Enter the data :");
                scanf("%d",&data);
                r = insert_at_begin(&head,data);
                if(r)
                {
                    printf("Data inserted at begin\n");
                }
                else
                {
                    printf("Data not inserted\n");
                }
            }
            break;

            case 2:
                printf("Enter the data :");
                scanf("%d",&data);
                r = insert_at_end(&head,data);
                 if (r)
                    printf("Data inserted at end\n");
                else
                    printf("Data not inserted\n");
                break;



            case 4:
            {
                display(head);
                break;
            }

             default:
                printf("Invalid choice, try again.\n");

        }

    }

}
