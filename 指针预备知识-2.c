#include<stdio.h>
int main(void)
{
	int *p;
	int i = 10;
//	int j;

    p = &i;
	*p = i;
//	j = *p;                                                         
	printf("i = %d,*p = %d\n", i, *p);

	return 0;
}