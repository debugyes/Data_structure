#include<stdio.h>
struct Student//���Ƕ������������������
{
	int sid;
	char name[200];
	int age;
};
int main(void)
{
	struct Student st = { 1000, "zhangsan", 20 };
	//st.sid = 99; ��һ�ַ�ʽ��������
	struct Student *pst;//ֻռ4���ֽ�

	//�ڶ��ַ�ʽ����һ��ָ�����ָ���Ǹ�����
	pst = &st;
	pst->sid = 99;     //pst->sid�ȼ��ڣ�*pst��.sid������*pst��.sid�ȼ���st.sid������pst->sid�ȼ���st.sid


	return 0;
}