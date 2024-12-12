#include<stdio.h>
#include<string.h>
void reverse_string(char *str)
{
	int i = 0, j = strlen(str) - 1;
	while(i<j)
	{
		int temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
	
}
int main()
{
	char str[20];
	printf("Enter the string :");
	scanf("%s",str);
	
	reverse_string(str);
	printf("\nReversed string is :%s",str);
}