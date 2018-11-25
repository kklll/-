/*
		���뻷��vs2017
		����Ϊͼ�Ĵ��������
*/
//vs2017 ����fopen��fscanf������fopen_s,fscanf_s  Ԥ��������� _CRT_SECURE_NO_WARNINGS��ֹ���档
//����fopen��fopen_s fscanf��fscanf_s�÷��ıȽ� https://blog.csdn.net/razy_monkey/article/details/50215271
#include<stdio.h>
#include<stdlib.h>
//���ȴ����ڽӱ�EdgeNode
typedef struct 	node
{
	int adjvex;
	struct node *next;
}EdgeNode;			//�ڽӱ��еı߱�ڵ㣨����ṹ�壩
typedef struct VertexNode
{
	char vertex;
	EdgeNode *FirstEdge;
}VertexNode;		//�ڽӱ��б��㣨ͷ�������嶨�壩
typedef struct LinkedGraph
{
	VertexNode adjlist[100];
	int n, e;
}LinkedGraph;		//�ڽӱ�Ľṹ���壬adjlist�����ͷ�ڵ㣬n�涥�������e����������

LinkedGraph * Creat(char *filename, int c)		//�����ڽӱ�ĺ������ļ���ȡ��c���������ͼ��������ͼ��1����0���ޣ�
{
	LinkedGraph *g;
	g = (LinkedGraph *)malloc(sizeof(LinkedGraph));
	int i, j, k;
	static EdgeNode *s;
	FILE *fp = NULL;			//�����ļ�ָ��fp
	fp = fopen(filename, "r");		//����ֻ��ģʽ
	if (fp)
	{
		fscanf(fp, "%d %d\n", &g->n, &g->e);
		for (i = 0; i < g->n; i++)
		{
			fscanf(fp, "%c ", &g->adjlist[i].vertex);
			//�α��ϸô�Ϊ"%ls"�����÷��μ���https://blog.csdn.net/ymzhou117/article/details/6932069
			g->adjlist[i].FirstEdge = NULL;
		}
		for (i = 0; i < g->e; i++)
		{
			fscanf(fp, "%d %d", &j, &k);
			s = (EdgeNode *)malloc(sizeof(EdgeNode));
			s->adjvex = k;
			s->next = g->adjlist[j].FirstEdge;		//
			g->adjlist[j].FirstEdge = s;
			if (c == 0)			//�ޱ߱�Ļ���������һ��
			{
				s = (EdgeNode*)malloc(sizeof(EdgeNode));
				s->adjvex = j;
				s->next = g->adjlist[k].FirstEdge;
				g->adjlist[k].FirstEdge = s;
			}
		}
		fclose(fp);
		printf("ͼ������ɣ�");
	}
	else
	{
		printf("�ļ���ʧ�ܣ��޷����в���!");
	}
	return g;
}
/*
�����곡����������
*/
int visited[100];             //�������
LinkedGraph * dfs(LinkedGraph *g, int i)
{
	EdgeNode *p;
	printf("\n");
	printf("���ʵ�:");
	printf("%c", g->adjlist[i].vertex);
	visited[i] = 1;
	p = g->adjlist[i].FirstEdge;
	while (p)
	{
		if (!visited[p->adjvex])
			dfs(g, p->adjvex);
		p = p->next;
	}
}
void dfstraverse(LinkedGraph *g)
{/* ������ȱ���ͼg*/
	int i;
	for (i = 0; i < g->n; i++)
		visited[i] = 0;
	for (i = 0; i < g->n; i++)
		if (!visited[i])  /* viδ���ʹ�*/
			dfs(g, i);
	printf("\n\n");
}
int visited_2[100];
void bfs(LinkedGraph *g,int i)				//������ȱ���
{
	int j;
	EdgeNode *p;
	int queue[100], front, rear;		//���нṹ�ı�������
	front = rear = 0;				//��ʼ������
	printf("���ʵ�:");
	printf("%c\n", g->adjlist->vertex);
	visited_2[i] = 1;
	queue[rear++] = i;
	while (rear>front)
	{
		j = queue[front++];
		p = g->adjlist[j].FirstEdge;
		while (p)
		{
			if (visited_2[p->adjvex] == 0)
			{
				printf("���ʵ�:");
				printf("%c\n", g->adjlist[p->adjvex].vertex);
				queue[rear++] = p->adjvex;
				visited_2[p->adjvex] = 1;
			}
			p = p->next;
		}
	}
}
int bfstraverse(LinkedGraph *g)
{

	int i, count = 0;
	for (i = 0; i < g->n; i++)
	{
		visited_2[i] = 0;
	}
	for (i = 0; i < g->n; i++)
	{
		if (!visited_2[i])
		{
			/*printf("\n");*/
			count++;
			bfs(g, i);
		}
	}
}
int main()
{
	LinkedGraph *g;
	g = Creat("C:\\Users\\10129\\source\\repos\\Project2\\Project2\\Data.txt", 0);
	printf("������ȱ���˳��Ϊ:\n");
	dfstraverse(g);				//��ȱ���
	printf("������ȱ���˳��Ϊ:\n");
	bfstraverse(g);				//��ȱ���
	return 0;
}
