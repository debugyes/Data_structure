#include<stdio.h>

//Ϊstruct Student�����¶�ȡһ�����֣�typedef-��������-����
typedef struct Student
{
	int sid;
	char name[100];
	char sex;
}ST;
int main(void)
{
	struct Student st; // �ȼ���ST st;
	struct Student *ps; //�ȼ���St *ps;

	ST st2;
	st2.sid = 100;
	printf("%d\n", st2.sid);

	return 0;
}