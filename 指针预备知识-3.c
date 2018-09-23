#include<stdio.h>
void f(int *p)
{
	*p = 100;
	return;
}
int main(void)
{
	int i = 99;

	f(&i);
	printf("i = %d\n", i);
	return 0;
}