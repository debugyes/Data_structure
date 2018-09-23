#include<stdio.h>
#include<stdbool.h>
#include<malloc.h>
//������һ���������ͣ����ֽ�struct arr�����������ͺ���������Ա
struct Arr
{
	int *pBase; //�洢���������һ��Ԫ�صĵ�ַ
	int len;      //�����������ɵ����Ԫ�صĸ���
	int cnt;      //��ǰ������ЧԪ�صĸ���
	//int increment��
};

void init_arr(struct Arr *pArr, int len);
void input_arr(struct Arr *pArr);
bool append_arr(struct Arr *pArr, int val); //׷��
bool insert_arr(struct Arr *pArr, int pos, int val); //pos��λ�ã���1��ʼ
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

	printf("�����������Խ��еĲ�����\n\n");
	printf("--------------------\n");


	printf("1. ��������\n");
	printf("--------------------\n\n");
	printf("��������ѡ���ǣ�");
	scanf_s("%d", &operation);

	if (operation == 1)
	{
		printf("��ѡ���ˡ��������ݡ�\n\n");
		printf("����������Ҫ�洢Ԫ�صĸ�����");
		scanf_s("%d", &len);
		init_arr(&arr, len);
		input_arr(&arr);
		operation = 0;
	}
	else
	{
		printf("\n\a������Ч�����˳�����\n");
		exit(-1);
	}

	printf("�����������Լ������еĲ�����\n\n");
	printf("--------------------\n");
	printf("1.չʾ����\n2.׷������\n3.��������\n4.ɾ������\n5.ɾ������\n6.��������\n7.ð������\n8.�˳���������������ݽ����ᱻ���棡��\n");
	printf("--------------------\n\n");
	printf("��������ѡ���ǣ�");
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
		printf("����������׷��Ԫ�صĸ�����");
		scanf_s("%d", &number_append);

		for (int i = 0; i < number_append; i++)
		{
			printf("��������׷�ӵĵ�%d��ֵ��", i + 1);
			scanf_s("%d", val);
			append_arr(&arr, val);
		}
		operation_1 = 0;
	}

	else if (3 == operation_1)
	{
		printf("����������������ݵ�λ�ã�");
		scanf_s("%d", &pos);
		printf("�����������ڸ�λ�ò�������ݣ�");
		scanf_s("%d", val);
		insert_arr(&arr, pos, val);
		operation_1 = 0;
	}

	else if (4 == operation_1)
	{
		printf("����������ɾ�������ݵ�λ�ã�");
		scanf_s("%d", &pos);
	}

	else if (5 == operation_1)
	{

	}
	else
	{
		printf("\a�����ѽ�������л����ʹ�ã�\n");
		exit(-1);
	}
		
	return 0;
}

void init_arr(struct Arr *pArr, int len)
{
	pArr->pBase = (int*)malloc(sizeof(struct Arr));
	if (NULL == pArr)
	{
		printf("\a����ʧ�ܣ�\n");
		exit(-1);
	}
	else
	{
		printf("\n\a����ɹ���\n\n");
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
		printf("�������%d��Ԫ�ص�ֵ��", i+1);
		scanf_s("%d", &pArr->pBase[i]);
		pArr->cnt++;
	}
	printf("\a�����Ѿ��ɹ����棡\n\n");
}
void show_arr(struct Arr * pArr)
{
	if (is_empty(pArr))
	{
		printf("\a���ʧ�ܣ�����Ϊ�գ�\n");
	}
	else
	{
		for (int i = 0; i < pArr->cnt; i++)
		{
			printf("\a��%d��Ԫ�ص�ֵΪ��%d\n", i, pArr->pBase[i]);
		}
	}
	return;
}

bool append_arr(struct Arr *pArr, int val)
{
	if (is_full(pArr))
	{
		printf("\a׷��ʧ�ܣ���������!\n");
		return false;
	}
	else
	{
		printf("\a׷�ӳɹ���\n");
		pArr->pBase[pArr->cnt] = val;
		++pArr->cnt;
	}
	return;
}

bool insert_arr(struct Arr *pArr, int pos, int val)
{
	if (is_full(pArr))
	{
		printf("\a���ʧ�ܣ�\n");
		return false;
	}
	if (pos<1 || pos>pArr->cnt+1)
	{
		printf("\a���ʧ�ܣ�\n");
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