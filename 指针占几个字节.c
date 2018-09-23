#include<stdio.h>
int main(void)
{
	double *p;
	double x = 66.6;

	p = &x;             //x占8个字节，一个字节是八位

	double arr[3] = { 1.1, 2.2, 3.3 };
	double *q;

	q = &arr[0];
	printf("%p\n", q); // %p实际就是十六进制输出
	q = &arr[1];
	printf("%p\n", q);
	return 0;
}