#include<stdio.h>

//Ϊstruct Student�����¶�ȡһ�����֣�typedef-��������-����
typedef struct Student
{
	int sid;
	char name[100];
	char sex;
} *PST; // PST�ȼ���struct Student *
int main(void)
{
	struct Student st;
	PST ps = &st;

	ps->sid = 99;
	printf("%d\n", ps->sid);

	return 0;
}