/*
	���뻷��dev-c++��GCC 4.9.2 ����Ϊ��
	���ݽṹ���·��������
*/
#include<stdio.h>
#include<stdlib.h>
#include"creat.h"		//�����ڽӾ���Ĵ������� 
#define m 30
typedef enum {
	false, true
}bool;	//��1�滻Ϊtrue����0�滻Ϊfalse 
typedef int dist[m];	//�������� 
typedef int path[m];	//·������ 
void dj(mgraph g, int v0, path p, dist d)
{
	bool final[m];		//����Ƿ�������·�� 
	int i, j, k, v, min, x;
	//����Ϊջ�ṹ�ڵı���
	for (v = 0; v < g.n; v++)	//ִ�г�ʼ�� 
	{
		final[v] = false;
		d[v] = g.edges[v0][v];
		if (d[v] < 999 && d[v] != 0)
			p[v] = v0;
		else
			p[v] = -1;
	}

	final[v0] = true;
	d[v0] = 0;
	for (i = 1; i < g.n; i++)
	{
		min = 999;	//��ʱ����С���ȣ��൱�ڳ�ʼ���� 
		for (k = 0; k < g.n; ++k)
			if (!final[k] && d[k] < min)
			{
				v = k;	//v����¼��ǰ�ڵ㡣 
				min = d[k];
			}
			printf("\n%c--->%c---%d\n " ,g.vexs[v0],g.vexs[v],min);
			if (min == 999)
				return;
			final[v] = true;	//��ʾ���Ѿ�������·���� 
		for (k = 0; k < g.n; ++k)
		{
			if (!final[k] && (min + g.edges[v][k] < d[k]))
			{
				d[k] = min + g.edges[v][k];
				p[k] = v;
			}
		}
	}
}
void print(mgraph g, path p, dist d)
{
	int st[m], i, pre, top = -1;
	//����Ϊջ�ṹ�ڵı���
	for (i = 0; i < g.n; i++)
	{
		st[++top] = i;
		printf("\n����Ϊ%3d,·��Ϊ:\n", d[i]);
		pre = p[i];
		while (pre != -1)
		{
			st[++top] = pre;
			pre = p[pre];
		}
		while (top > 0)
			printf("%2d", st[top--]);
	}
}
int main()
{
	mgraph g;
	path p;
	dist d;
	int v0;
	creat(&g, "s-data.txt", 1);
	printf("������ԭ����ţ�\n");
	scanf("%d", &v0);
	dj(g, v0, p, d);
	print(g, p, d);

}
