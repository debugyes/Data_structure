#include<stdio.h>
#include<malloc.h>
int main(void)
{
	int a[5] = {4, 10, 2, 8, 6};	//静态分配
	int len;

	printf("请输入你需要分配内存的长度：");
	scanf_s("%d", &len);

	int *pArr = (int *)malloc(sizeof(int)*len); //动态分配，malloc返回第一个字节地址，发送给pArr，所以pArr里有第一个字节地址也就是数组名

	*pArr = 4;// 类似于a[0] = 4；
	pArr[1] = 10;//类似于a[1] = 10；
	printf("%d %d", *pArr, pArr[1]);

	for ( int i = 0;  i < len;  ++i)
	{
		scanf_s("%d", &pArr[i]);
	}
	for (int j = 0; j < len; ++j)
	{
		printf("%d", pArr[j]);
	}

	return 0;
}