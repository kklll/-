/*
	���뻷��dev-c++��GCC 4.9.2 ����Ϊ�� 
	���ݽṹͼ����С���������㷨��Prim�㷨�� 
*/ 
#include<stdio.h>
#include<stdlib.h>
typedef struct edgedata{
	int beg,end;	//��ʼ�ߵ��±�������ߵ��±� 
	int lenth;	//���ߵĳ��� 
}edge;
typedef struct mgraph{		//�˺�����������ͼ���ڽӾ��� 
	int n,e;		//��¼����ߵĸ�����Ϣ
	int edges[30][30];		//�ڽӾ���
	char verx[30];		//�������Ϣ��Ҳ���Ƕ������ƣ�
}mgraph;
void creat(mgraph *g,char *s,int c)		//�ڽӾ���Ĵ��� 
{
	int i,j,k,w;
	FILE *rf;
	rf= fopen(s,"r");
	if(rf)
	{
		fscanf(rf,"%d %d",&g.n,&g.e);
		for(i=0;i<g->n;i++)
		{
			fscanf(rf,"%c",&g->verx);
		}
		for(i=0;i<g->n;i++)
		{
			for(j=0;j<g->n;j++)
			{
				if(j==i)
				g->edges[i][i]=0;
				else
				g->edges[i][j]=-1;
			}
		}
		for(k=0;k<g->e;k++)
		{
			fscanf(rf,"%d %d %d",&i,&j,&w);
			g->edges[i][j]=w;
			if(c==0)
			a[j][i]=w;
		}
		fclose(rf);
	}
	else
	{
		printf("���ļ�ʧ���޷�����!");
		exit(0);
	}
 } 
void prim(mgraph g,edge tree[m-1])
{
	edge x;		//��ʼ�� 
	int d,min,j,k,s,v;
	for(v=1;v<=g.n-1,v++)	//��0��ʼ�����߽���ѭ�� 
	{
		tree[v-1].beg=0;	
		tree[v].end=v;
		tree[v-1].lenth=g.edges[0][v];
	}
	for(k=0;k<=g.n-3;k++)
	{
		
	}
}

int main()
 {
		
	return 0;
}
