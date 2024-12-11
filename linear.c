#include<stdio.h>

int linear(int arr[],int n , int key)
{
	for(int i = 0 ; i<n ; i++)
	{
		if(arr[i] == key)
		return i;
	}
	return 0;
}

int main()
{
	int arr[] = {4,3,8,1,2},key;
	printf("Enter the key element :");
	scanf("%d",&key);
	int r = linear(arr,5,key);
	if(r)
	printf("The element is :%d",r + 1);
	else
	printf("It is not found.\n");
}