#include<stdio.h>
#include<stdlib.h>
  struct node{
  int data;
  struct node*next;
   
};
int push (struct node**top,int n){
             if(top==NULL){
                    struct node*p;
                    p=(struct node*)malloc(sizeof(struct node));
                    p->data=n;
                    p->next=NULL;
                    *top=p;
                     
                    return 1;   
             }
             else{
                  struct node*p;
                  p=(struct node*)malloc(sizeof(struct node));
                  p->data=n;
                  p->next=*top;
                  *top=p;
                  return 1;
             }
}
void display(struct node*top){
   if(top==NULL)
    printf("under flow");
   else{
    while(top->next!=NULL){
    printf("%d ",top->data);
    top=top->next;
    }
    printf("%d",top->data);
}}
int pop(struct node**top){
     struct node*temp=*top;
     if(*top==NULL)
          return -1;
    else if(temp->next==NULL){
         int n;
         n=temp->data;
         *top=NULL;
         return n;
          }
     else{
           int n=temp->data;
           *top=temp->next;
           return n;
     }
}
int main(){
  struct node*top;
   top=NULL;
   int ch,n,r;
   while( 1){ 
   
    printf("\nenter the choice:\n");
    printf("1]push.\n");
    printf("2]Display.\n");
     printf("3]pop.\n");
    scanf("%d",&ch);
    
      switch(ch){
         
      case 1: printf("enter the data:");
              scanf("%d",&n);
              push(&top,n);
              break;
              
      case 2: display(top);
              break;
        
      case 3: 
              r=pop(&top);
              if (r==-1)
              printf("under flow");
              else
              printf("pop is done poped element is %d",r);
              break;
      
      default: printf("invalid choice");
      }
   }
}
