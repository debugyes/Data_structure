#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node
{
	int data;       //������
	struct Node *pNext;//ָ����
}NODE, *PNODE;   //NODE = struct Node 
                             //*PNODE = struct Node *

//��������
PNODE creat_list();
void traverse_list(pHead);//����
bool is_empty(PNODE pHead);
int length_list(PNODE);
bool insert_list(PNODE, int, int);
bool delet_list(PNODE, int, int *);
void sort_list(PNODE);

int main(void)
{
	int list_len;

	PNODE pHead = NULL;//����һ��ͷ�ڵ�

	pHead = creat_list(); //����һ����ѭ�������������������ͷ�ڵ�ĵ�ַ����pHead

	traverse_list(pHead);//����

	if (is_empty(pHead))
		printf("����Ϊ�գ�\n");

	list_len = length_list(pHead);
	printf("����ĳ���Ϊ��%d", list_len);
	return 0;
}

PNODE creat_list()
{
	int len;//���������Ч�ڵ�ĸ���
	int i;//ѭ����
	int val;//������ʱ����û�����Ľڵ��ֵ
	PNODE pHead = (PNODE)malloc(sizeof(NODE));//������һ���������Ч���ݵ�ͷ�ڵ�

	PNODE pTail = pHead;//����һ�����ڹҽڵ�ı���
	pTail->pNext = NULL;

	if (NULL == pHead)
	{
		printf("\a����ʧ�ܣ�������ֹ��\n");
		exit(-1);
	}

	printf("����������Ҫ���ɵ�����ڵ�ĸ�����len = ");
	scanf_s("%d", &len);

	for ( i = 0; i < len; ++i)
	{
		printf("�������%d���ڵ��ֵ��", i + 1);
		scanf_s("%d", &val);
		
		PNODE pNew = (PNODE)malloc(sizeof(NODE));//����һ���ڵ�
		if (NULL == pNew)
		{
			printf("\a����ʧ�ܣ�������ֹ��\n");
			exit(-1);
		}

		pNew->data = val;

		pTail->pNext = pNew;//���½ڵ����pTail����
		pNew->pNext = NULL;//���½ڵ�ָ�������
		pTail = pNew;//ʱ��ָ�����һ���ڵ�
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

void sort_list(PNODE phead)
{

	return 0;
}