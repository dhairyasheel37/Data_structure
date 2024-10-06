#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * next;
};

int insert_at_begin(struct node  **head, int data);
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

int at(struct node **head ,int pos , int n)
{
    struct node *new,*temp;
    int i=1;
    temp=*head;
    if(pos==1)
    {
        new = (struct node*)malloc(sizeof(struct node)) ;
        new->data = n; 
        new->next = temp;
        *head=new;
        return pos;
    }

    
    else if(1<pos)
    {
        for (int i = 1; i < pos-1; i++)
        {
            temp = temp->next;
            if(temp==NULL)
            {
                return 0;
            }
        /* code */
        }
    //insert
        new=(struct node*)malloc(sizeof(struct node));
        new->data=n;
        new->next = temp->next;
        temp->next = new;
        return pos;      
    }
    else
    return -1;
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
int insert_after(struct node**head,int loc,int no)
{
    struct node *temp,*r;
    temp = *head;
    for (int i = 1; i < loc; i++)
    {
        temp = temp->next;
        if(temp==NULL)
        {
            return 0;
        }
        /* code */
    }
    //insert
    r=(struct node*)malloc(sizeof(struct node));
    r->data=no;
    r->next = temp->next;
    temp->next = r;
    return 1;
    
}

int insert_before(struct node**head,int pos,int no)
{
    struct node *temp,*r;
    temp = *head;
    int i;
    if(pos == 1)
    {
        r=(struct node*)malloc(sizeof(struct node));
        r->data=no;
        r->next=*head;
        *head = r;
    }
    else if(pos>1)
    {
        for (i = 1; i < pos-1; i++)
        {
            temp = temp->next;
            if(temp==NULL)
            {
                return 0;
            }
        }
    //insert
        r=(struct node*)malloc(sizeof(struct node));
        r->data=no;
        r->next = temp->next;
        temp->next = r;
        return 1;
    }
    else
    {
        return 0;
    }
}

int delete_at_begin(struct node ** head)
{
    if(*head == NULL)
    {
        return 0;
    }
    else
    {
        struct node *temp;
        temp = *head;
        *head=temp->next;
        free(temp);
        return 1;
    }
}

int delete_at_end(struct node ** head)
{
    if(*head == NULL)
    {
        return 0;
    }
    else
    {
        struct node *temp,*r;
        temp = *head;
        while(temp->next!=NULL)
        {
            r=temp;
            temp=temp->next;
        }
        r->next=NULL;
       
        free(temp);
        return 1;
    }
}
int  delete_at(struct node**head,int pos)
{
    struct node *temp,*r;
    temp = *head;
    if(pos==1)
    {
        *head = temp->next;
        return 1;
        free(temp);
    }
    else if(1<pos)
    {
        for(int i=1;i<pos;i++)
        {
            r=temp;
            temp=temp->next;
            if(temp == NULL)
            {
                return -1;
            }
        }
        r->next = temp->next;
        free(temp);
        return 1;


    }
}

int main()
{
    struct node * head = NULL;
    int ch=0,r,data,pos;
    printf("Enter the 1 for inserte at begin.\n");
    printf("Enter the 2 for insert at end.\n");
    printf("Enter the 3 for inser at specifc position.\n");        
    printf("Enter the 4 for display.\n");
    printf("Enter the 5 for insert after node.\n");
    printf("Enter the 6 for insert before node.\n");
    printf("Enter the 7 for delete at begin.\n");
    printf("Enter the 8 for delete at end.\n");
    
    while (ch!=-1)
    {
        
        printf("\nEnter the choice :");
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

            case 3:
            {
                printf("Enter the  position :");
                scanf("%d",&pos);
                printf("Enter thr data :");
                scanf("%d",&data);
                r = at(&head,pos,data);
                if(r==pos)
                {
                    printf("insert at position %d.\n",r);
                }
                else
                {
                    printf("unsucssecful\n");
                }
                // r = insert
            }
            break;

            case 4:
            {
                display(head);
                break;
            }

            case 5:
            printf("Enter the  position :");
            scanf("%d",&pos);
            printf("Enter thr data :");
            scanf("%d",&data);
            r=insert_after(&head,pos,data);
            if(r==1)
            {
                printf("insert at position %d.\n",r);
            }
            else
            {
                printf("unsucssecful\n");
            }
            break;

            case 6:
            printf("Enter the  position :");
            scanf("%d",&pos);
            printf("Enter thr data :");
            scanf("%d",&data);
            r=insert_before(&head,pos,data);
            if(r==1)
            {
                printf("insert at position.\n");
            }
            else
            {
                printf("unsucssecful\n");
            }
            break;

            case 7:
            r = delete_at_begin(&head);
            if (r==1)
            {
                printf("Element  Delete\n");
            }
            else
            {
                printf("unsucssecful\n");
            }
            break;

            case 8:
            r = delete_at_end(&head);
            if(r==1)
            {
                printf("delete possible\n");
            }
            else
            {
                printf("unsucssesful\n");
            }
            break;

            case 9:
            printf("Enter the position");
            scanf("%d",&pos);
            r=delete_at(&head,pos);
            if(r==1)
            {
                printf("delete possible\n");
            }
            else
            {
                printf("unsucssesful\n");
            }
            break;


            default:
                printf("Invalid choice, try again.\n");

        }

    }

}

