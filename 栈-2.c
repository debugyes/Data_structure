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
	PNODE pTop;//指向箱子顶端
	PNODE pBottom;//指向箱子底部
}STACK, *PSTACK;

int main(void)
{
	STACK S; //STACK 等价于struct Stack

	initStack(&S);//初始化
	pushStack();//不需要指定放的位置，只能放在栈底
	traverse();
	return 0;
}

void initStack(STACK *pS)
{

	return 0;
}