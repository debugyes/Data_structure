#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct Node
{
	int datal;
	struct Node *pNext;
}NODE, *PNODE;

void initStack(PSTACK);

typedef struct Stack
{
	PNODE pTop;//ָ�����Ӷ���
	PNODE pBottom;//ָ�����ӵײ�
}STACK, *PSTACK;

int main(void)
{
	STACK S; //STACK �ȼ���struct Stack

	initStack(&S);//��ʼ��
	pushStack();//����Ҫָ���ŵ�λ�ã�ֻ�ܷ���ջ��
	traverse();
	return 0;
}

void initStack(STACK *pS)
{

	return 0;
}