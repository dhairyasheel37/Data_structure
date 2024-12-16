#include<stdio.h>

void printf_arrey(int arr[],int N)
{
	for(int i=0;i<N;i++)
	{
		printf("%-4d",arr[i]);
	}
}
void insertion_sort(int arr[],int N)
{
	for(int i = 1;i<N;i++)
	{
		int j;
		int temp = arr[i];
		for(j = i-1;j>=0;j--)
		{
			if(arr[j] > temp)
			arr[j+1]=arr[j];
			else
			break;
			
		}
		arr[j+1] = temp;
	}
}


int main()
{
	int arr[] = {55,44,22,66,11,33};

	printf("The arrey sort : ");
	printf_arrey(arr,6);
	printf("\n");
	insertion_sort(arr,6);
	printf_arrey(arr,6);
	printf("\n");
	return 0;
}