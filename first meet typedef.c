#include<stdio.h>

//为struct Student再重新多取一个名字，typedef-数据类型-名称
typedef struct Student
{
	int sid;
	char name[100];
	char sex;
}ST;
int main(void)
{
	struct Student st; // 等价于ST st;
	struct Student *ps; //等价于St *ps;

	ST st2;
	st2.sid = 100;
	printf("%d\n", st2.sid);

	return 0;
}