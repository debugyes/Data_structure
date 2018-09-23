/*
目的：跨函数使用内存
*/
#include<stdio.h>
struct Student//不是定义变量而是数据类型
{
	int sid;
	char name[200];
	int age;
}; //分号不能省
int main(void)
{
	struct Student st = { 1000, "zhangsan", 20 }; 
	printf("%d %s %d\n", st.sid, st.name, st.age);
	return 0;
}