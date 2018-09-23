#include<stdio.h>
struct Student//不是定义变量而是数据类型
{
	int sid;
	char name[200];
	int age;
};
int main(void)
{
	struct Student st = { 1000, "zhangsan", 20 };
	//st.sid = 99; 第一种方式，不常用
	struct Student *pst;//只占4个字节

	//第二种方式，用一个指针变量指向那个变量
	pst = &st;
	pst->sid = 99;     //pst->sid等价于（*pst）.sid，而（*pst）.sid等价于st.sid，所以pst->sid等价于st.sid


	return 0;
}