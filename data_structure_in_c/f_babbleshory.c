#include<stdio.h>

void bubble_short(int *arr,int n )
{
    for (int i = 0; i < n; i++)
    {
        int min = arr[i];
        for (int j = i; j < n - i -1; j++)
        {
            if (min<arr[i])
            {
                 int temp = arr[i];
                 arr[i]=arr[i+1];
                 arr[i + 1] = temp;
            }
            
           
        }
        
        /* code */
    }
    
}

int main(){
    int n;
    printf("Enter the no. of element :");
    scanf("%d",&n);
    int arr[n],i,j;
    printf("Enter the element \n ");
    for (i = 0; i < n; i++)
    {
        printf("Enter the %d number :",i);
        scanf("%d",&arr[i]);
    }

    bubble_short(a,n);
    for (i = 0; i < n; i++)
    {
        printf("Enter the %d number :",a[i]);
    }

    
    return 0;
}