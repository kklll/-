/*
ʵ����  ���򷽷�ʵ����2ѧʱ��
1��ʵ��Ŀ��
ͨ����ʵ����������Ļ����㷨�͹����Լ����ҵĻ��������͹��̡�
2��ʵ������
���һ������Ͳ���ϵͳ���ܹ�ʵ�ֶԸ�����һ��ѧ���Ľ���֤��Ϣ���磺���š�������ϵ�𡢰�ŵȣ���������Ͳ��ҡ�
1)���տ���˳���������
2���ܹ�ʵ�ֲ���ĳ��ϵ�����еĽ��鿨�Ų������
3��ʵ��Ҫ��
��1���������ڽ���֤��Ϣ���Ľṹ�壻
��2���������֤��Ϣ�ļ�¼��¼�������Ϣ��
��3��д����ĳ�������㷨����ð�����򣩰��ؼ��ֶԼ�¼����������㷨������
��4���Խ���֤��Ϣ�ļ�¼��ϵ�������������ҽṹ��
��5������ĳ��Ҫ���ҵ�ϵ�������������ҷ������Ҳ������ϵ�����н���֤��Ϣ��
*/
/*
���뻷�� vs2017������
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define m 100
typedef struct node
{
	char id[15];
	char name[10];
	char department[15];
	char classid[15];
}info;
int creat(char file[30],info info[m])
{
	int n, i;
	FILE *fp = fopen(file, "r");
	if (fp)
	{
		printf("�ļ���ȡ�ɹ�\n");
	}
	else
	{
		printf("�ļ���ȡʧ��\n");
		exit(0);
	}
	fscanf(fp, "%d\n",&n);
	for (i = 0; i < n; i++)
	{
		fscanf(fp, "%s %s %s %s \n", &info[i].name, &info[i].id, &info[i].department, &info[i].classid);
	}
	printf("δ����ǰ��˳��Ϊ:\n");
	for (i = 0; i < n; i++)
	{
		printf("%s %s %s %s \n", info[i].name, info[i].id, info[i].department, info[i].classid);
	}
	return n;
}
void QuickSort(info y[m],int left,int right,int n)
{
	info x;
	int i, j, flag = 1;
	if (left < right)
	{
		i = left;
		j = right;
		x = y[i];
		while (i < j)
		{
			while (i < j&&strcmp(x.id,y[j].id)<0)
				j--;
			if (i < j)
				y[i++] = y[j];
			while (i<j&&strcmp(x.id, y[j].id)> 0)
				i++;
			if (i < j)
				y[j--] = y[i];
		}
		y[i] = x;
		QuickSort(y, left, i - 1,n);		//�ݹ�ʵ�ַ��� 
		QuickSort(y, i + 1, right,n);
	}
}
int main()
{
	info x[m];
	int n,i;
	n=creat("sort.txt", x);
	printf("\n\n�����Ľ��Ϊ:\n");
	QuickSort(x,0,7,n);
	for (i = 0; i < n; i++)
	{
		printf("%6s %s %s %s \n", x[i].name, x[i].id, x[i].department, x[i].classid);
	}
	return 0;
}