///*
//	���뻷��dev-c++��GCC 4.9.2 ����Ϊ��
//	���ݽṹͼ����С���������㷨��Prim�㷨��
//*/
//#include<stdio.h>
//#include<stdlib.h>
//typedef struct edgedata {
//	int beg, end;	//��ʼ�ߵ��±�������ߵ��±� 
//	int length;	//���ߵĳ��� 
//}edge;
//typedef struct mgraph {		//�˺�����������ͼ���ڽӾ��� 
//	int n, e;		//��¼����ߵĸ�����Ϣ
//	int edges[30][30];		//�ڽӾ���
//	char vexs[30];		//�������Ϣ��Ҳ���Ƕ������ƣ�
//}mgraph;
//void creat(mgraph *g, char *s, int c)		//�ڽӾ���Ĵ��� 
//{
//	int i, j, k, w;
//	FILE *rf;
//	rf = fopen(s, "r");
//	if (rf)
//	{
//		fscanf(rf, "%d %d\n", &g->n, &g->e);
//		for (i = 0; i < g->n; i++)
//		{
//			fscanf(rf, "%c\n", &g->vexs[i]);
//		}
//		for (i = 0; i < g->n; i++)
//		{
//			for (j = 0; j < g->n; j++)
//			{
//				if (j == i)
//					g->edges[i][i] = 0;
//				else
//					g->edges[i][j] = 999;
//			}
//		}
//		for (k = 0; k < g->e; k++)
//		{
//			fscanf(rf, "%d %d %d\n", &i, &j, &w);
//			g->edges[i][j] = w;
//			if (c == 0)
//				g->edges[j][i] = w;
//		}
//		fclose(rf);
//	}
//	else
//	{
//		printf("���ļ�ʧ���޷�����!");
//		exit(0);
//	}
//}
//void prim(mgraph g, edge tree[29])
//{
//	edge x;
//	int d, min, s, v,k,j;
//	for (v = 1; v <= g.n - 1; v++) 
//	{
//		tree[v - 1].beg = 0; 
//		tree[v - 1].end = v;
//		tree[v - 1].length = g.edges[0][v]; 
//	}
//	for (k = 0; k <= g.n - 3; k++) 
//	{
//		min = tree[k].length;  
//		s = k; 
//		for (j = k + 1; j <= g.n - 2; j++)
//		{
//			if (tree[j].length < min)
//			{
//				min = tree[j].length;
//				s = j; 
//			}
//		}
//		v = tree[s].end;
//		x = tree[s];
//		tree[s] = tree[k];
//		tree[k] = x;
//		for (j = k + 1; j <= g.n - 2; j++)
//		{
//			d = g.edges[v][tree[j].end];  
//			if (d < tree[j].length)  
//			{
//				tree[j].length = d; 
//				tree[j].beg = v; 
//			}
//		}
//	}
//	printf("��С������Ϊ��\n");
//	for (j = 0; j <= g.n - 2; j++)
//	{
//		printf("\n%c--->%c-----%d\n", g.vexs[tree[j].beg], g.vexs[tree[j].end], tree[j].length);
//	}
//	printf("���ڵ�Ϊ��%c\n", g.vexs[0]);
//}
//int main()
//{
//	mgraph g;
//	edge tree[30];
//	char filename[100] = { "Data.txt" };
//	creat(&g, filename, 0);
//	prim(g, tree);
//	return 0;
//}
