#include<stdio.h>

//为struct Student再重新多取一个名字，typedef-数据类型-名称
typedef struct Student
{
	int sid;
	char name[100];
	char sex;
} *PSTU, STU; // PST代表struct Student *， ST代表struct Student
int main(void)
{
	STU st; //struct Student st
	PSTU ps = &st; //struct Student *ps
	ps->sid = 99;

	printf("%d\n", ps->sid);

	return 0;
}