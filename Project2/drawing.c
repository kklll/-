//#include<stdio.h>
//#include<stdlib.h>
////���ȴ����ڽӱ�EdgeNode
//typedef struct 	node
//{
//	int adjvex;
//	struct node *next;
//}EdgeNode;			//�ڽӱ��еı߱�ڵ㣨����ṹ�壩
//typedef struct VertexNode
//{
//	char vertex;
//	EdgeNode *FirstEdge;
//}VertexNode;		//�ڽӱ��б��㣨ͷ�������嶨�壩
//typedef struct LinkedGraph
//{
//	VertexNode adjlist[100];
//	int n, e;
//}LinkedGraph;		//�ڽӱ�Ľṹ���壬adjlist�����ͷ�ڵ㣬n�涥�������e����������
//
//LinkedGraph * Creat(LinkedGraph *g, char *filename, int c)		//�����ڽӱ�ĺ������ļ���ȡ��c���������ͼ��������ͼ��1����0���ޣ�
//{
//	int i, j, k;
//	static EdgeNode *s;
//	FILE *fp = NULL;			//�����ļ�ָ��fp
//	fp = fopen(filename, "r");		//����ֻ��ģʽ
//	if (fp)
//	{
//		fscanf(fp, "%d%d\n", &g->n, &g->e);
//		for (i = 0; i < g->n; i++)
//		{
//			fscanf(fp, "%c", &g->adjlist[i].vertex);
//			//�α��ϸô�Ϊ"%ls"�����÷��μ���https://blog.csdn.net/ymzhou117/article/details/6932069
//			g->adjlist[i].FirstEdge = NULL;
//		}
//		for (i = 0; i < g->e; i++)
//		{
//			fscanf(fp, "%d%d", &j, &k);
//			s = (EdgeNode *)malloc(sizeof(EdgeNode));
//			s->adjvex = k;
//			s->next = g->adjlist[j].FirstEdge;		//
//			g->adjlist[j].FirstEdge = s;
//			if (c == 0)			//�ޱ߱�Ļ���������һ��
//			{
//				s = (EdgeNode*)malloc(sizeof(EdgeNode));
//				s->adjvex = j;
//				s->next = g->adjlist[k].FirstEdge;
//				g->adjlist[k].FirstEdge = s;
//			}
//		}
//		fclose(fp);
//		printf("ͼ������ɣ�");
//	}
//	else
//	{
//		printf("�ļ���ʧ�ܣ��޷����в���!");
//	}
//}
///*
//�����곡����������
//*/
//int visited[100];             //�������
//LinkedGraph * dfs(LinkedGraph *g, int i)
//{
//	EdgeNode *p;
//	printf("���ʵ�:%c\n", g->adjlist[i].vertex);
//	visited[i] = 1;
//	p = g->adjlist[i].FirstEdge;
//	while (p)
//	{
//		if (!visited[p->adjvex])
//			dfs(g, p->adjvex);
//		p = p->next;
//	}
//}
//
//void dfstraverse(LinkedGraph *g)
//{/* ������ȱ���ͼg*/
//	int i;
//	for (i = 0; i < g->n; i++)
//		visited[i] = 0;
//	for (i = 0; i < g->n; i++)
//		if (!visited[i])  /* viδ���ʹ�*/
//			dfs(g, i);
//}
//int main()
//{
//	LinkedGraph g;
//	Creat(&g, "E:\\Data.txt", 0);
//	dfstraverse(&g);
//	return 0;
//}
