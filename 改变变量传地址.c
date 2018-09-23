#include<stdio.h>

void f(int **q);
int main(void)
{
	int i = 9;
	int *p = &i;

	printf("%p\n", p);
	f(&p);
	printf("%p\n", p);
	return 0;
}
void f(int **q)
{
	*q = (int *)0xffffffff;
}
//没有实际含义，平时不要这么写，不安全