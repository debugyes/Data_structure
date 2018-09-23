#include<stdio.h>

//为struct Student再重新多取一个名字，typedef-数据类型-名称
typedef struct Student
{
	int sid;
	char name[100];
	char sex;
} *PST; // PST等价于struct Student *
int main(void)
{
	struct Student st;
	PST ps = &st;

	ps->sid = 99;
	printf("%d\n", ps->sid);

	return 0;
}