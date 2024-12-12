#include<stdio.h>
#include<string.h>

char* find_substrlast(char *str,char *substr)
{
	char* temp = NULL;
	for(int i = 0; str[i]!='\0';i++)
	{
		if(str[i] == substr[0])
		{
			int j;
			for(j = 0;substr[j]!='\0';j++)
			{
				if(str[i + j]!=substr[j])
				break;
			}
		if(substr[j] == '\0')
		temp = &str[i];
		}
		
	}
	if(temp != NULL)
	return temp;
	
	return NULL;
}
int main()
{
	char str[] = "I am in SYCSE program is CSE";
	char substr[] = "CSE";
	printf("The last accurence index start from %p\n",find_substrlast(str,substr));
}