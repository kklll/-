///*
//    ���뻷��dev-c++��GCC 4.9.2 ����Ϊ��
//	���ݽṹͼ����С���������㷨����³˹�����㷨��
//*/
//#include<stdio.h>
//#include<stdlib.h>
//typedef struct mgraph{		//�˺�����������ͼ���ڽӾ��� 
//	int n,e;		//��¼����ߵĸ�����Ϣ
//	int edges[30][30];		//�ڽӾ���
//	char verx[30];		//�������Ϣ��Ҳ���Ƕ������ƣ�
//}mgraph;
//typedef struct edgedata
//{
//	int beg,end;
//	int len;
//}edge;
//void QuickSort(edge edges[],int left,int right)
//{			//�������� 
//	edge x;
//	int i,j,flag=1;
//	if(left<right)
//	{
//		i=left;
//		j=right;
//		x=edges[i];
//		while(i<j)
//		{
//			while(i<j&&x.len<edges[j].len)
//				j--;
//			if(i<j)
//				edges[i++]=edges[j];
//			while(i<j&&x.len>edges[i].len)
//				i++;
//			if(i<j)
//				edges[j--]=edges[i];
//		}
//		edges[i]=x;
//		QuickSort(edges,left,i-1);		//�ݹ�ʵ�ַ��� 
//		QuickSort(edges,i+1,right);		
//	}
//}
//void getedge(mgraph g,edge edges[])
//{		//��ȡ�ɵ����,ʹ��edges���鴢��ÿ������Ϣ 
//	int i,j,k=0;
//	for(i=0;i<g.n;i++)
//		for(j=0;j<i;j++)
//			if(g.edges[i][j]!=0&&g.edges[i][j]<999)
//			{
//				edges[k].beg=i;
//				edges[k].end=j;
//				edges[k++].len=g.edges[i][j];
//			}	
//}
//void kruskal(mgraph g)
//{
//	int i,j,k=0,lt;//lt�������ڴ����м����
//	int cnvx[30];
//	edge edges[900];
//	edge tree[30];
//	getedge(g,edges);
//	QuickSort(edges,0,g.e-1);
//	for(i=0;i<g.n;i++)
//		cnvx[i]=i;
//	for(i=0;i<g.n-1;i++)
//	{
//		while(cnvx[edges[k].beg]==cnvx[edges[k].end])
//			k++;
//		tree[i]=edges[k];
//		lt=cnvx[edges[k].end];
//		for(j=0;j<g.n;j++)
//			if(cnvx[j]==lt)
//			cnvx[j]=cnvx[edges[k].beg];
//		k++;
//	}
//	printf("��С������Ϊ:\n");
//	for(j=0;j<g.n-1;j++)
//	{
//		printf("%c------>%c\n",g.verx[tree[j].end],g.verx[tree[j].beg]);
//	}
//}
//void creat(mgraph *g,char *s,int c)		//�ڽӾ���Ĵ��� 
//{
//	int i,j,k,w;
//	FILE *rf;
//	rf= fopen(s,"r");
//	if(rf)
//	{
//		fscanf(rf,"%d %d\n",&g->n,&g->e);
//		for(i=0;i<g->n;i++)
//		{
//			fscanf(rf,"%c\n",&g->verx[i]);
//		}
//		for(i=0;i<g->n;i++)
//		{
//			for(j=0;j<g->n;j++)
//			{
//				if(j==i)
//				g->edges[i][i]=0;
//				else
//				g->edges[i][j]=999;
//			}
//		}
//		for(k=0;k<g->e;k++)
//		{
//			fscanf(rf,"%d %d %d\n",&i,&j,&w);
//			g->edges[i][j]=w;
//			if(c==0)
//			g->edges[j][i]=w;
//		}
//		fclose(rf);
//	}
//	else
//	{
//		printf("���ļ�ʧ���޷�����!");
//		exit(0);
//	}
// } 
// int main()
// {
// 	mgraph g;
// 	char filename[30]={"Data.txt"};
// 	creat(&g,filename,0);
// 	kruskal(g);
// }
