#include<stdio.h>
#include<math.h>

float standard(float arr[],int size)
{
    float var=0,sum = 0,mean,sd=0;
    int i;
    for (i = 0; i < size; i++)
    {
        sum =sum + arr[i];
    }
    mean = sum / size;
    for (int i = 0; i < size; i++)
    {
        var = var + pow((arr[i]-mean),2); 
    }
    sd = sqrt(var);
    return sd;
    
}

int main(){
    int n;
    printf("Enter the total number of element :");
    scanf("%d",&n);
    float arr[n];
    printf("enter the %d elements\n",n);
    for (int  i = 0; i < n; i++)
    {
        scanf("%f",&arr[i]);
    }
    printf("Standerd Deviation : %f",standard(arr,n));
    
    return 0;
}