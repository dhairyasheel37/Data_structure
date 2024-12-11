  //binary_desending.c
#include<stdio.h>

int binary(int arr[],int key,int l,int h)
{
	while(l<=h)
	{
		int mid = (l+h)/2;
		if(arr[mid]==key)
		{
			return mid;
		}
		else if (key < arr[mid])
		{
			l = mid + 1;
		}
		else 
		{
			h = mid - 1;
		}
	}
	return -1;
}

int main()
{
	int arr[] = {90,80,70,60,50,40,30,20,10},key;
	printf("Enter the key element :");
	scanf("%d",&key);
	
	int r = binary(arr,key,0,8);
	if(r != -1)
	printf("\n It is present at position %d \n",r + 1);
	else
	printf("not found\n");
}