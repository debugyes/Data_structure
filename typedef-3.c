#include<stdio.h>

//Ϊstruct Student�����¶�ȡһ�����֣�typedef-��������-����
typedef struct Student
{
	int sid;
	char name[100];
	char sex;
} *PSTU, STU; // PST����struct Student *�� ST����struct Student
int main(void)
{
	STU st; //struct Student st
	PSTU ps = &st; //struct Student *ps
	ps->sid = 99;

	printf("%d\n", ps->sid);

	return 0;
}