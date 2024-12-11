#include<stdio.h>

int binary(int arr[],int n)
{
    int low = 0,high =5;
    int mid = (low + high)/2;
    while (low<=high)
    {
        if(n == arr[mid])
        {
            return mid;
            break;
        }
        else if(n < arr[mid])
        {
             high = mid -1;
         }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
    
    
}

int main(){
    int arr[5],n;
    for (int i = 0; i < 5; i++)
    {
        scanf("%d",&arr[i]);
    }
    
    printf("enter the serching element :");
    scanf("%d",&n);
   
    printf(" %d",binary(arr,n));
    
    

    return 0;
}   