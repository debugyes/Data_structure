//跨函数使用内存
#include<stdio.h>
#include<malloc.h>
struct Student
{
	int sid;
	int age;
};

struct Student*CreatlistStudent(void);
void ShowStudent(struct Student*);

int main(void)
{
	struct Student *ps;
	ps = CreatlistStudent();
	ShowStudent(ps);
	return 0;
}

struct Student*CreatlistStudent(void)
{
	struct Student *p = (struct Student*)malloc(sizeof(struct Student));
	p->sid = 99;
	p->age = 88;
	return p;
}

void ShowStudent(struct Student* pst)
{
	printf("%d %d\n", pst->sid, pst->age);
}