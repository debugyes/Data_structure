#include<stdio.h>
#include<malloc.h>
void f(int k)
{
	int m;
	double *q = (double*)malloc(200);
}
int main(void)
{
	int i = 10;
	int *p = (int *)malloc(100);
	return 0;
}
//静态内存在栈里分配，动态内存在堆里分配
//栈由操作系统自动分配，堆由程序员自己分配