#include<stdio.h>

void show_Array(int *p, int len)
{
	int i;
	p[0] = -1;  //p[0] == *p          p[2] == *(p+2) == *(a+2) == a[2]
	for ( i = 0; i < len; ++i)
	{
		printf("%d ", p[i]);
	}
	return;
}
int main(void)
{
	int a[5] = { 1, 2, 3, 4, 5 };
	show_Array(a, 5);
	return 0;
}