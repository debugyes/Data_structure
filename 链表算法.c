#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node
{
	int data;       //数据域
	struct Node *pNext;//指针域
}NODE, *PNODE;   //NODE = struct Node 
                             //*PNODE = struct Node *

//声明函数
PNODE creat_list();
void traverse_list(pHead);//遍历
bool is_empty(PNODE pHead);
int length_list(PNODE);
bool insert_list(PNODE pHead, int pos, int val);
bool delet_list(PNODE pHead, int pos, int *pVal);
void sort_list(PNODE, int len);

int main(void)
{
	int list_len;
	PNODE pHead = NULL;//建立一个头节点

	pHead = creat_list(); //创建一个非循环单链表，并将该链表的头节点的地址赋给pHead
	traverse_list(pHead);//遍历

	if (is_empty(pHead))
		printf("链表为空！\n");

	list_len = length_list(pHead);
	printf("链表的长度为：%d", list_len);

	void sort_list(pHead, list_len);
	return 0;
}

PNODE creat_list()
{
	int len;//用来存放有效节点的个数
	int i;//循环用
	int val;//用来临时存放用户输入的节点的值
	PNODE pHead = (PNODE)malloc(sizeof(NODE));//分配了一个不存放有效数据的头节点

	PNODE pTail = pHead;//建立一个用于挂节点的变量
	pTail->pNext = NULL;

	if (NULL == pHead)
	{
		printf("\a分配失败，程序终止！\n");
		exit(-1);
	}

	printf("请输入您需要生成的链表节点的个数：len = ");
	scanf_s("%d", &len);

	for ( i = 0; i < len; ++i)
	{
		printf("请输入第%d个节点的值：", i + 1);
		scanf_s("%d", &val);
		
		PNODE pNew = (PNODE)malloc(sizeof(NODE));//建立一个节点
		if (NULL == pNew)
		{
			printf("\a分配失败，程序终止！\n");
			exit(-1);
		}

		pNew->data = val;

		pTail->pNext = pNew;//把新节点挂在pTail后面
		pNew->pNext = NULL;//把新节点指针域清空
		pTail = pNew;//时刻指向最后一个节点
	}

	return pHead;
}

void traverse_list(PNODE pHead)
{
	PNODE p = pHead->pNext;
	while (NULL != p)
	{
		printf("%d\n", p->data);
		p = p->pNext;
	}
	printf("\n");

	return;
}

bool is_empty(PNODE pHead)
{
	if (NULL == pHead->pNext)
		return true;
	else
		return false;
	return ;
}

int length_list(PNODE pHead)
{
	PNODE p = pHead->pNext;
	int len = 0;

	while (NULL != p)
	{
		++len;
		p = p->pNext;
	}

	return len;
}

void sort_list(PNODE phead, int len)
{
	int i, j, t;
	PNODE p, q;

	for ( i = 0, p = phead->pNext; i<len-1; i++,p = p->pNext)
	{
		for (j = i + 1, p=p->pNext; j < len; j++, q->pNext)
		{
			if (p->data > q->data)//类似于数组中的a[i] > a[j]
			{
				t = p->data;
				p->data = q->data;
				q->data = t;
			}
		}
	}
	return 0;
}

bool insert_list(PNODE pHead, int pos, int val)
{
	int i = 0;
	PNODE p = pHead;

	while (NULL != p && i < pos - 1)//防止意外情况
	{
		p = p->pNext;
		++i;
	}

	if (i > pos - 1 || NULL == p)//防止意外情况*2
		return false;

	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (NULL == pNew)
	{
		printf("动态内存分配失败！\n");
		exit(-1);
	}
	else
	{
		printf("分配成功！\n");
	}
	//此时pos已经是前一个节点了
	pNew->data = val;
	PNODE q = p->pNext;
	p->pNext =pNew;
	pNew->pNext = q;
	return true;
}

bool delet_list(PNODE pHead, int pos, int *pVal)
{
	int i = 0;
	PNODE p = pHead;

	while (NULL != p->pNext && i < pos - 1)//防止意外情况
	{
		p = p->pNext;
		++i;
	}

	if (i > pos - 1 || NULL == p->pNext)//防止意外情况*2
		return false;

	PNODE q = p->pNext;
	*pVal = q->data;
	p->pNext = p->pNext->pNext;
	free(q);
	q = NULL;
	return true;//表示删除成功
}