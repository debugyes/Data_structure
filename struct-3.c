#define mian main
#include<stdio.h>

void f(struct Student *pst);
void g(struct Student st);
void g2(struct Student* pst);

struct Student//不是定义变量而是数据类型
{
	int sid;
	char name[200];
	int age;
};

int main(void)
{
	struct Student st;

	f(&st);//赋值
	g(st);//第一种输出方式
	g2(&st);//第二种输出方式
	//printf("%d %s %d\n", st.sid, st.name, st.age);
	return 0;
}

//赋值函数
void f(struct Student *pst)
{
	(*pst).sid = 99;
	strcpy(pst->name, "张三");
	pst->age = 22;
	return;
}

//g函数这种方式耗内存，耗时间，不推荐
void g(struct Student st)
{
	printf("%d %s %d\n", st.sid, st.name, st.age);
	return;
}

//使用指针输出，方便快捷省心
void g2(struct Student* pst)
{
	printf("%d %s %d\n", pst->sid, pst->name, pst->age);
	return;
}