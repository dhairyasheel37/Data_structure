#include<stdio.h>
 
struct student
{
		char name[20];
		int roll_no;
		int mark ;
};
 
void set_information(struct student *s1)
{
		printf("Enter the student name :");
		scanf("%s",s1->name);
		printf("Enter the student roll no :");
		scanf("%d",&s1->roll_no);
		printf("Enter the mark :");
		scanf("%d",&s1->mark);
}
 
void printf_information(struct student s1)
{
		printf("%s \n",s1.name);
		printf("%d \n",s1.roll_no);
		printf("%d \n",s1.mark);
}
 
int main()
{
		struct student s1;
 
		set_information(&s1);
 
		printf_information(s1);
}
