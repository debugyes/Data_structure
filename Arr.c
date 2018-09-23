#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>
//定义了一个数据类型，名字叫struct arr，该数据类型含有三个成员
struct Arr
{
	int *pBase; //存储的是数组第一个元素的地址
	int len;      //数组所能容纳的最大元素的个数
	int cnt;      //当前数组有效元素的个数
	//int increment；
};

void init_arr(struct Arr *pArr, int len);
void input_arr(struct Arr *pArr);
bool append_arr(struct Arr *pArr, int val); //追加
bool insert_arr(struct Arr *pArr, int pos, int val); //pos（位置）从1开始
bool delet_arr(struct Arr *pArr, int pos, int *pVal);
bool is_full(struct Arr *pArr);
bool is_empty(struct Arr *pArr);
void sort_arr(struct Arr * pArr);
void show_arr(struct Arr *pArr);
void inversion_arr(struct Arr *pArr);

int main(void)
{
	struct Arr arr;
	int len;
	int operation;
	int operation_1;
	int number_append;
	int val = 0;
	int pos;

	printf("下面是您可以进行的操作：\n\n");
	printf("--------------------\n");


	printf("1. 存入数据\n");
	printf("--------------------\n\n");
	printf("您想做的选择是：");
	scanf_s("%d", &operation);

	if (operation == 1)
	{
		printf("您选择了“存入数据“\n\n");
		printf("请输入您想要存储元素的个数：");
		scanf_s("%d", &len);
		init_arr(&arr, len);
		input_arr(&arr);
		operation = 0;
	}
	else
	{
		printf("\n\a操作无效！已退出程序\n");
		exit(-1);
	}

	printf("下面是您可以继续进行的操作：\n\n");
	printf("--------------------\n");
	printf("1.展示数据\n2.追加数据\n3.插入数据\n4.删除数据\n5.删除数据\n6.倒置数据\n7.冒泡排序\n8.退出程序（所储存的数据将不会被保存！）\n");
	printf("--------------------\n\n");
	printf("您想做的选择是：");
	scanf_s("%d", &operation_1);

	if (1 == operation_1)
	{
		printf("\n\n");
		printf("--------------------\n");
		show_arr(&arr);
		printf("--------------------");
		printf("\n\n");
		operation_1 = 0;
	}

	else if (2 == operation_1)
	{
		printf("请输入您想追加元素的个数：");
		scanf_s("%d", &number_append);

		for (int i = 0; i < number_append; i++)
		{
			printf("请输入您追加的第%d个值：", i + 1);
			scanf_s("%d", val);
			append_arr(&arr, val);
		}
		operation_1 = 0;
	}

	else if (3 == operation_1)
	{
		printf("请输入您想插入数据的位置：");
		scanf_s("%d", &pos);
		printf("请输入您想在该位置插入的数据：");
		scanf_s("%d", val);
		insert_arr(&arr, pos, val);
		operation_1 = 0;
	}

	else if (4 == operation_1)
	{
		printf("请输入您想删除的数据的位置：");
		scanf_s("%d", &pos);
	}

	else if (5 == operation_1)
	{

	}
	else
	{
		printf("\a程序已结束，感谢您的使用！\n");
		exit(-1);
	}
		
	return 0;
}

void init_arr(struct Arr *pArr, int len)
{
	pArr->pBase = (int*)malloc(sizeof(struct Arr));
	if (NULL == pArr)
	{
		printf("\a分配失败！\n");
		exit(-1);
	}
	else
	{
		printf("\n\a分配成功！\n\n");
		pArr->len = len;
		pArr->cnt = 0;
	}
	return;
}
bool is_empty(struct Arr *pArr)
{
	if (0 == pArr->cnt)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool is_full(struct Arr *pArr)
{
	if (pArr->cnt == pArr->len)
	{
		return true;
	}
	else
	{
		return false;
	}
	return;
}

void input_arr(struct Arr *pArr)
{
	for (int i = 0; i < pArr->len; i++)
	{
		printf("请输入第%d个元素的值：", i+1);
		scanf_s("%d", &pArr->pBase[i]);
		pArr->cnt++;
	}
	printf("\a数据已经成功保存！\n\n");
}
void show_arr(struct Arr * pArr)
{
	if (is_empty(pArr))
	{
		printf("\a输出失败，数组为空！\n");
	}
	else
	{
		for (int i = 0; i < pArr->cnt; i++)
		{
			printf("\a第%d个元素的值为：%d\n", i, pArr->pBase[i]);
		}
	}
	return;
}

bool append_arr(struct Arr *pArr, int val)
{
	if (is_full(pArr))
	{
		printf("\a追加失败，数组已满!\n");
		return false;
	}
	else
	{
		printf("\a追加成功！\n");
		pArr->pBase[pArr->cnt] = val;
		++pArr->cnt;
	}
	return;
}

bool insert_arr(struct Arr *pArr, int pos, int val)
{
	if (is_full(pArr))
	{
		printf("\a添加失败！\n");
		return false;
	}
	if (pos<1 || pos>pArr->cnt+1)
	{
		printf("\a添加失败！\n");
		return false;
	}

	for (int i = pArr->cnt-1; i >= pos-1; --i)
	{
		pArr->pBase[i + 1] = pArr->pBase[i];
	}
	pArr->pBase[pos - 1] = val;
	return true;
	return;
}

bool delet_arr(struct Arr *pArr, int pos, int *pVal)
{
	if (is_empty(pArr))
	{
		return false;
	}
	if (pos < 1 || pos>pArr->cnt)
	{
		return true;
	}

	*pVal = pArr->pBase[pos - 1];
	for (int i = pos; i < pArr->cnt; ++i)
	{
		pArr->pBase[i - 1] = pArr->pBase[i];
	}
	pArr->cnt--;
	return;
}

void inversion_arr(struct Arr *pArr)
{
	int i = 0;
	int j = pArr->cnt - 1;
	int t;

	while (i < j)
	{
		t = pArr->pBase[i];
		pArr->pBase[i] = pArr->pBase[j];
		pArr->pBase[j] = t;
		++i;
		--j;
	}
	return;
}

void sort_arr(struct Arr * pArr)
{
	int i, j, t;

	for (i = 0; i < pArr->cnt; ++j)
	{
		for (j = i + 1; j < pArr->cnt; ++i)
		{
			if (pArr->pBase[i] > pArr->pBase[j])
			{
				t = pArr->pBase[i];
				pArr->pBase[i] = pArr->pBase[j];
				pArr->pBase[j] = t;
			}
		}
	}
	return;
}