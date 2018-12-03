#include<stdio.h>
#include<stdlib.h>
typedef struct mgraph {		//�˺�����������ͼ���ڽӾ��� 
	int n, e;		//��¼����ߵĸ�����Ϣ
	int edges[30][30];		//�ڽӾ���
	char vexs[30];		//�������Ϣ��Ҳ���Ƕ������ƣ�
}mgraph;
void creat(mgraph *g, char *s, int c)		//�ڽӾ���Ĵ��� 
{
	int i, j, k, w;
	FILE *rf;
	rf = fopen(s, "r");
	if (rf)
	{
		fscanf(rf, "%d %d\n", &g->n, &g->e);
		for (i = 0; i < g->n; i++)
		{
			fscanf(rf, "%c\n", &g->vexs[i]);
		}
		for (i = 0; i < g->n; i++)
		{
			for (j = 0; j < g->n; j++)
			{
				if (j == i)
					g->edges[i][i] = 0;
				else
					g->edges[i][j] = 999;
			}
		}
		for (k = 0; k < g->e; k++)
		{
			fscanf(rf, "%d %d %d\n", &i, &j, &w);
			g->edges[i][j] = w;
			if (c == 0)
				g->edges[j][i] = w;
		}
		fclose(rf);
	}
	else
	{
		printf("���ļ�ʧ���޷�����!");
		exit(0);
	}
}

