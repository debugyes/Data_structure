#define mian main
#include<stdio.h>

void f(struct Student *pst);
void g(struct Student st);
void g2(struct Student* pst);

struct Student//���Ƕ������������������
{
	int sid;
	char name[200];
	int age;
};

int main(void)
{
	struct Student st;

	f(&st);//��ֵ
	g(st);//��һ�������ʽ
	g2(&st);//�ڶ��������ʽ
	//printf("%d %s %d\n", st.sid, st.name, st.age);
	return 0;
}

//��ֵ����
void f(struct Student *pst)
{
	(*pst).sid = 99;
	strcpy(pst->name, "����");
	pst->age = 22;
	return;
}

//g�������ַ�ʽ���ڴ棬��ʱ�䣬���Ƽ�
void g(struct Student st)
{
	printf("%d %s %d\n", st.sid, st.name, st.age);
	return;
}

//ʹ��ָ�������������ʡ��
void g2(struct Student* pst)
{
	printf("%d %s %d\n", pst->sid, pst->name, pst->age);
	return;
}