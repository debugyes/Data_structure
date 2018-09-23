#define mian main
#include<stdio.h>
#include<malloc.h>
#include<stdbool.h>

struct Arr                    //������һ����������
{
	int *pBase;             //������������һ��Ԫ�صĵ�ַ
	int len;                   //�����������ɵ����Ԫ�صĸ���
	int cnt;                  //��ǰ������ЧԪ�صĸ���
 //int increment;       //�Զ���������
};

bool init_arr(struct Arr *pArr, int length);//��ʼ��
void input_arr(struct Arr *pArr);
bool append_arr(struct Arr *pArr, int val); //׷��
bool insert_arr(struct Arr *pArr, int pos, int val);              //����                //pose��ֵ��1��ʼ
bool delete_arr();                                     //ɾ��
bool get();                                               //��ȡ�±�
bool is_empty(struct Arr *pArr);             //�ж��Ƿ�Ϊ��
bool is_full(struct Arr *pArr);                 //�ж��Ƿ���
void sort_arr();                                        //����
void show_arr(struct Arr *pArr);
void inversion_arr();                               //����

int main(void)
{
	int len;
	struct Arr arr;

	printf("����������ĳ���:");
	scanf_s("%d", &len);

	init_arr(&arr, len);
	input_arr(&arr);
	show_arr(&arr, len);  //��ô��ݵ�ַ
	append_arr(&arr, 1);



	return 0;
}

bool init_arr(struct Arr *pArr, int length) 
{
	pArr->pBase = (int *)malloc(sizeof(int) * length); //���ָ��ָ��Ľṹ������е�pbase��Ա
	if (NULL == pArr->pBase)
	{
		printf("��̬�ڴ����ʧ�ܣ�\n");
		exit(-1);//��ֹ��������
	}
	else
	{
		pArr->len = length;
		pArr->cnt = 0;
		printf("����ɹ���\n");
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
		printf("�������%d��Ԫ�أ�", i + 1);
		scanf_s("%d", &pArr[i]);
	}
}
void show_arr(struct Arr *pArr)
{
	if (is_empty(pArr)) //pArr������ǵ�ַ������Ҫ&
	{
		printf("����Ϊ�գ�\n");
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