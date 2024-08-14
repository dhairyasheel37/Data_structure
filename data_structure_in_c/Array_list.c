#include<stdio.h>
int insertbegin(int* ,int* ,int ,int);
int insertend(int* ,int* ,int ,int);
int insert_at(int* , int, int*, int, int);
int deletebegin(int* ,int* );
int main()
{
    char choice;
    printf("Enter the choice if insert at begin enter 'b', if insert at end enter 'e',\n if insert at specific position enter 's',:");
    scanf("%c",&choice);

    int max_size,r,e,sp,d;
    printf("Enter the max size :");
    scanf("%d",&max_size);

    int a[20],size,last_position,insert_element,i,n;
    printf("Enter the last position ");
    scanf("%d",&last_position);

    for(i=0;i<last_position;i++)
    {
        scanf("%d",&a[i]);
    }

    int position;


    switch (choice)
    {
    case 'b':
	printf("enter the insert element :");
    scanf("%d",&insert_element);
    r=insertbegin(a,&last_position,insert_element,max_size);
    if(r==0)
    {
        printf("error");
    }
    else
    {

        for(i=0;i<last_position;i++)
        {
            printf(" %d",a[i]);
        }
    }
    break ;



    case 'e':
	printf("enter the insert element :");
    scanf("%d",&insert_element);
    e=insertend(a,&last_position,max_size,insert_element);
    if(e == 0)
    {
        printf("error");
    }
    else
    {
        printf("data is stored \n");
        for(i=0;i<last_position;i++)
        {
            printf(" %d",a[i]);
        }
    }

    break;

            case 's':
            printf("enter the insert element :");
    		scanf("%d",&insert_element);
            printf("Enter the position :");
            scanf("%d",&position);
            sp=insert_at(a,insert_element,&last_position,max_size,position);

            if(sp == 0)
            {
                printf("error");
            }
            else
            {
                printf("data is stored \n");
                for(i=0;i<last_position;i++)
                {
                    printf("%d ",a[i]);
                }
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
		for(i=0;i<size-1;i++)
                {
                    printf("%d",a[i]);
                }
	}
	break;


    }


    //insert end
    /*int position;
    printf("Enter the position :");
    scanf("%d",&position);*/



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
