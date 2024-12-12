
#include<stdio.h>
int main()
{
	int arr[] = { 1,1,3};
	int i,j;
	int n=3;
	for(i = 0 ; i < n; i++)
	{
		
		int flag = 0;
		for(j =0 ; j<n;j++)
		{
			if(i == j)
			continue;
			if(arr[i] == arr[j])
			{
				flag = 1;
				break;
			}
		}
		if(flag == 0)
		{
			printf("non repiting element %d.\n",arr[i]);
			return 0;
		}
	}
	printf("NOt Found .\n");
	
}

//first_non_repiting_element.c