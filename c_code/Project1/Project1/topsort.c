///*
//	���뻷��vs2017��2017���㣩
//	����Ϊ:��������
//*/
//#include<stdio.h>
//#include<stdlib.h>
//#define m 30
//typedef char vertextype;
//typedef struct node
//{
//	int adjvex;
//	struct node *next;
//}edgenode;
//typedef struct de{
//	edgenode * firstedge;
//	vertextype vertex;
//	int id;
//}vertexnode;
//typedef struct {
//	vertexnode adjlist[m];
//	int n, e;
//}aovgraph;
//int topsort(aovgraph g)
//{
//	int k = 0, i, j, v, flag[m];
//	int queue[m];
//	int front, rear;
//	edgenode *p;
//	front = rear = 0;	//���еĳ�ʼ������
//	for (i = 0; i < g.n; i++)
//		flag[i] = 0;
//	printf("\nAOV������������Ϊ��");
//	for (i = 0; i < g.n; i++)
//	{
//		if (g.adjlist[i].id == 0 && flag[i] == 0)
//		{
//			queue[rear++] = i;
//			flag[i] = 1;
//		}
//		while (rear > front)
//		{
//			v = queue[front++];
//			printf("%c ", g.adjlist[v].vertex);
//			k++;	//�������������ж���û�л���
//			p = g.adjlist[v].firstedge;
//			while (p)
//			{
//				j = p->adjvex;	//j���涥����±�ֵ
//				if (--g.adjlist[j].id==0&&flag[j]==0)
//				{
//					queue[rear++] = j;
//					flag[j] = 1;
//				}
//				p = p->next;
//			}
//		}
//	}
//	return k;
//}
//aovgraph * Creat(char *filename, int c)		//�����ڽӱ�ĺ������ļ���ȡ��c���������ͼ��������ͼ��1����0���ޣ�
//{
//	aovgraph *g;
//	g = (aovgraph *)malloc(sizeof(aovgraph));
//	int i, j, k;
//	static edgenode *s;
//	FILE *fp = NULL;			//�����ļ�ָ��fp
//	fp = fopen(filename, "r");		//����ֻ��ģʽ
//	if (fp)
//	{
//		fscanf(fp, "%d %d\n", &g->n, &g->e);
//		for (i = 0; i < g->n; i++)
//		{
//			fscanf(fp, "%c%d ", &g->adjlist[i].vertex,&g->adjlist[i].id);
//			g->adjlist[i].firstedge = NULL;
//		}
//		for (i = 0; i < g->e; i++)
//		{
//			fscanf(fp, "%d %d\n", &j, &k);
//			s = (edgenode *)malloc(sizeof(edgenode));
//			s->adjvex = k;
//			s->next = g->adjlist[j].firstedge;		//
//			g->adjlist[j].firstedge = s;
//			if (c == 0)			//�ޱ߱�Ļ���������һ��
//			{
//				s = (edgenode*)malloc(sizeof(edgenode));
//				s->adjvex = j;
//				s->next = g->adjlist[k].firstedge;
//				g->adjlist[k].firstedge = s;
//			}
//		}
//		fclose(fp);
//		printf("ͼ������ɣ�");
//	}
//	else
//	{
//		printf("�ļ���ʧ�ܣ��޷����в���!");
//	}
//	return g;
//}
//int main()
//{
//	aovgraph *g;
//	g = Creat("sortdata.txt", 1);
//	topsort(*g);
//}