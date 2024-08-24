#include<stdio.h>
int insertbegin(int* ,int* ,int ,int);
int insertend(int* ,int* ,int ,int);
int insert_at(int* , int, int*, int, int);
int deletebegin(int* ,int* );
int deleteend(int* ,int *);
int delete_at(int* ,int *,int );
int linear(int *a,int *,int);

int main()
{
    char choice;
    printf("Enter the choice if insert at begin enter 'b', if insert at end enter 'e',\n if insert at specific position enter 's',if delete at begin enter 'd',if delete at end enter 'E',if delete at spcific position 'A',if search enter the 's':");
    scanf("%c",&choice);

    int max_size,key,d;
    printf("Enter the max size :");
    scanf("%d",&max_size);

    int a[20],size,last_position,insert_element,i,n;
    printf("Enter the last position ");
    scanf("%d",&last_position);
    if(last_position>0)
    {
         for(i=0;i<last_position;i++)
        {
            scanf("%d",&a[i]);
        }
    }


    int position;


    switch (choice)
    {
    case 'b':
	printf("enter the insert element :");
    scanf("%d",&insert_element);
    d=insertbegin(a,&last_position,insert_element,max_size);
    if(d==0)
    {
        printf("error");
    }
    else
    {
        printf("success");
    }
    break ;



    case 'e':
	printf("enter the insert element :");
    scanf("%d",&insert_element);
    d=insertend(a,&last_position,max_size,insert_element);
    if(d == 0)
    {
        printf("error");
    }
    else
    {
        printf("data is stored \n");

    }

    break;

            case 's':
            printf("enter the insert element :");
    		scanf("%d",&insert_element);
            printf("Enter the position :");
            scanf("%d",&position);
            d=insert_at(a,insert_element,&last_position,max_size,position);

            if(d == 0)
            {
                printf("error");
            }
            else
            {
                printf("data is stored \n");

            }
	    break;
	    //

    case'd':
	d=deletebegin(a,&last_position);
	if(d == 0)
	{
		printf("error");
	}
	else
	{
		printf("data is stored");
	}
	break;



    case 'E':
        d=deleteend(a,&last_position);
        if(d==0)
        {
            printf("error");
        }
        else
        {
            printf("success");
        }
        break;



    case 'A':
        printf("Enter the position :");
        scanf("%d",&position);
        d = delete_at(a,&last_position,position);
        if(d==0)
        {
            printf("error");
        }
        else
        {
            printf("success");
        }
        break;



    case 'S':
        printf("Enter the position :");
        scanf("%d",&key);
        d= linear(a,&last_position,key);
        if(d<=0)
        {
            printf("error");
        }
        else
        {
            printf("The search element %d",d + 1);
            printf("\n");
        }
    }

    if(d>0)
    {
        for(i=0;i<last_position;i++)
        {
            printf("%d ",a[i]);
        }
    }



}

int linear(int *a,int *n,int key){
    int I;



    for(I=0;I<n;I++){
        if(a[I]==key){
            return I;
        }
    }

     return -1;
}



int delete_at(int *a ,int *last_position,int position)
{
    if(*last_position == -1)
    {
        return 0;
    }
    else
    {
        int i;
        if(position >=0 && position <= *last_position)
        {
            for(i=position;i<*last_position;i++)
            {
                a[i]=a[i+1];
            }
            *last_position -= 1;
            return 1;
        }
        else
        {
            return 0;
        }
    }
}



int deleteend(int *a,int *last_position)
{
    if(*last_position == -1)
    {
        return 0;
    }
    else
    {
        *last_position -=1;
        return 1;
    }
}



int insertbegin(int *a,int *last_position,int insert_element,int max_size)
{


    if(*last_position == -1)
    {
        a[0]=insert_element;
        *last_position +=1 ;//insert element
        return 1;
    }
    else
    {
        if(*last_position >= max_size)//full list
        {
            return 0;
        }
        else
        {
            int i;
            for(i=*last_position;i>=0;i--)//Set current pos as >= the last position
            {
                a[i+1]=a[i];
            }
            a[0] = insert_element;//insert element
		*last_position = *last_position+1;
            return 1;
        }
    }

}

int insertend(int *a,int *last_position, int max_size,int insert_element)
{
    if(*last_position >= max_size)
    {
        return 0;
    }
    else
    {
        a[*last_position]=insert_element;
	 *last_position +=1;
        return 1;
    }
}


int insert_at(int *a, int insert_element, int *last_position, int max_size, int position)
{
    if(*last_position >= max_size)
    {

        return 0;
    }
    else
    {
        if(position >=0 && position<=*last_position+1)
        {
            int i;
            for(i=*last_position;i >= position-1;i--)
            {
                a[i+1] = a[i];
            }
            a[position-1] = insert_element;
            *last_position +=1;
            return 1;
        }
    }
}

int deletebegin(int *a, int *last_position)
{
	if(*last_position == -1)
	{
		return 0;
	}
	else
	{
		int i;
		for(i=0;i<*last_position;i++)
		{
			a[i]=a[i+1];

		}
	        *last_position--;
		return 1;
	}
}
