#include<stdio.h>
#include<malloc.h>
int main(void)
{
	int a[5] = {4, 10, 2, 8, 6};	//��̬����
	int len;

	printf("����������Ҫ�����ڴ�ĳ��ȣ�");
	scanf_s("%d", &len);

	int *pArr = (int *)malloc(sizeof(int)*len); //��̬���䣬malloc���ص�һ���ֽڵ�ַ�����͸�pArr������pArr���е�һ���ֽڵ�ַҲ����������

	*pArr = 4;// ������a[0] = 4��
	pArr[1] = 10;//������a[1] = 10��
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