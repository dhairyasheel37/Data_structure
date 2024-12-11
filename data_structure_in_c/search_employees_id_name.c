#include<stdio.h>
#include<string.h>
//search_employees_id_name.c
struct employee
{
	char emp_name[20];
	int emp_id;
};

void search_name(struct employee *ep,int n,char name[])
{
	int r ,flag;
	for(int i=0; i < n;i++)
	{
		r = strcmp((ep[i].emp_name),name);
		if(r == 0)
		{
			printf("The index with + 1 is %d \n",i+1);
			flag = 1;
		}
	}
	if(flag == 0)
	printf("not found\n");
}

int search_id(struct employee *ep,int n,int id)
{
	for(int i = 0; i < n;i++)
	{
		if(ep[i].emp_id == id)
		{
			
			printf("The index is :%d \n",i + 1);
			printf("The emp_name :%s \n",ep->emp_name);
			return 1;
		}
	}
	return -1;
}

int main()
{
	int n;
	printf("Enter the size of structure :");
	scanf("%d",&n);
	struct employee ep[n];
	
	for(int i = 0;i < n; i++)
	{
		printf("Enter the name :");
		scanf("%s",ep[i].emp_name);
		printf("Enter the employee id : ");
		scanf("%d",&ep[i].emp_id);
	}
	
	char name[20];
	int id,r;

	printf("Enter the search name :");
	scanf("%s",name);

	printf("Enter the id : ");
	scanf("%d",&id);
	
	search_name(ep,n,name);
	
	r=search_id(ep,n,id);
	if(r<0)
	{
		printf("Id is not found\n");
	}
}