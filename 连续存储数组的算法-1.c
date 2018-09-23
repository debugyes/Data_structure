#define mian main
#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

struct Arr                    //定义了一个数据类型
{
	int *pBase;             //代表的是数组第一个元素的地址
	int len;                   //数组所能容纳的最大元素的个数
	int cnt;                  //当前数组有效元素的个数
 //int increment;       //自动增长因子
};

bool init_arr(struct Arr *pArr, int length);//初始化
void input_arr(struct Arr *pArr);
bool append_arr(struct Arr *pArr, int val); //追加
bool insert_arr(struct Arr *pArr, int pos, int val);              //插入                //pose的值从1开始
bool delete_arr();                                     //删除
bool get();                                               //获取下标
bool is_empty(struct Arr *pArr);             //判断是否为空
bool is_full(struct Arr *pArr);                 //判断是否满
void sort_arr();                                        //排序
void show_arr(struct Arr *pArr);
void inversion_arr();                               //倒置

int main(void)
{
	int len;
	struct Arr arr;

	printf("请输入数组的长度:");
	scanf_s("%d", &len);

	init_arr(&arr, len);
	input_arr(&arr);
	show_arr(&arr, len);  //最好传递地址
	append_arr(&arr, 1);



	return 0;
}

bool init_arr(struct Arr *pArr, int length) 
{
	pArr->pBase = (int *)malloc(sizeof(int) * length); //这个指针指向的结构体变量中的pbase成员
	if (NULL == pArr->pBase)
	{
		printf("动态内存分配失败！\n");
		exit(-1);//终止整个程序
	}
	else
	{
		pArr->len = length;
		pArr->cnt = 0;
		printf("分配成功！\n");
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
}
void input_arr(struct Arr *pArr)
{
	for (int i = 0; i < pArr->len;++i)
	{
		printf("请输入第%d个元素：", i + 1);
		scanf_s("%d", &pArr[i]);
	}
}
void show_arr(struct Arr *pArr)
{
	if (is_empty(pArr)) //pArr本身就是地址，不需要&
	{
		printf("数组为空！\n");
	}
	else
	{
		for (int  i = 0; i < pArr->cnt ; ++i)
		{
			printf("%d ", pArr->pBase[i]);
		}
	}
}

bool append_arr(struct Arr *pArr, int val)
{
	if (is_full(pArr))
	{
		return false;
	}
	else
	{
		pArr->pBase[pArr->cnt] = val;
		(pArr->cnt)++;
		return true;
	}
}
bool insert_arr(struct Arr *pArr, int pos, int val)
{
	int i;

	if (is_full(pArr))
	{
		return false;
	}
	if (pos < 1 || pos>pArr->len)
	{

	}
	for (i = pArr->cnt - 1; i >= pos - 1; --i)
	{
		pArr->pBase[i + 1] = pArr->pBase[i];
	}
	pArr->pBase[pos - 1] = val;
	
	return true;
}