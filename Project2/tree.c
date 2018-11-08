/*

1��ʵ��Ŀ��
ͨ����ʵ�����ն���Ľ����͵ݹ�������ǵݹ�����㷨���˽��������ʵ���е�Ӧ�ò��������ö��������ʵ�����⡣
2��ʵ������
����ǰ�������˳����һ�ö������������ݱ������������������
��ӡ�����
3��ʵ��Ҫ��
��1������ǰ�������˳�򴴽�һ�ö�������
��2���Զ���������ǰ�����򡢺��������

*/
//���뻷��vs2017
#include<stdio.h>
#include<stdlib.h>
typedef char datatype;
typedef struct node{            //�������Ľṹ�嶨��
	datatype data;
	struct node *lchild;
	struct node *rchild;
}tree;
typedef struct stack {			//ջ�ṹ����
	int top;
	tree *data[100];			//��¼����ַ
	datatype tag[100];			//��¼���ҷ�֧�Ƿ��Ѿ��������(���ڷǵݹ�ĺ������)
}zhan;
tree *root;
tree *creat_tree()          //�ݹ鷽������������(ǰ�򴴽�),����Ļ���Ҫһ��ȫ�����롣
{
	static int a = 0;
	datatype ch;
	tree *t;
	if ((ch = getchar()) == '!')
		t = NULL;
	else
	{
		t = (tree *)malloc(sizeof(tree));
		if (a == 0)
		{
			root = t;
			a++;
		}
		t->data = ch;
		t->lchild = creat_tree();
		t->rchild = creat_tree();
	}
	return t;
}
void preorder(tree *t)			//ǰ������ݹ��㷨
{
	if (t)
	{
		printf("%c", t->data);
		preorder(t->lchild);
		preorder(t->rchild);
	}
}
void inorder(tree *t)					//��������ݹ��㷨
{
	if (t)
	{
		inorder(t->lchild);
		printf("%c", t->data);
		inorder(t->rchild);
	}
}
void postorder(tree *t)					//��������ݹ��㷨
{
	if (t)
	{
		postorder(t->lchild);
		postorder(t->rchild);
		printf("%c", t->data);
	}
}
void push(zhan *p,tree *x)
{
	p->data[p->top++] = x;
}
tree *pop(zhan *p)
{
	p->top--;
	return p->data[p->top];
}
void preorder_(tree *t)					//ǰ������ǵݹ��㷨
{
	zhan a;
	a.top = 0;							//ջ�ĳ�ʼ��
	while (a.top != 0 || t)
	{
		if (t)
		{
			printf("%c", t->data);
			push(&a, t);
			t = t->lchild;
		}
		else
		{
			t = pop(&a);
			t = t->rchild;
		}
	}
}
void inorder_(tree *t)					//��������ǵݹ��㷨
{
	zhan a;
	a.top = 0;							//��ʼ��
	while (a.top != 0 || t)
	{
		if (t)								//t��Ϊ�գ�ѹջ
		{
			push(&a,t);
			t = t->lchild;					//��tָ����������
		}
		else
		{
			t = pop(&a);					//���tΪ����ջ������������ֵ
			printf("%c", t->data);
			t = t->rchild;	
		}
	}
}
void postorder_(tree *t)					//��������ǵݹ��㷨
{
	zhan a;
	a.top = 0;
	while (t || a.top != 0)
	{
		if (t)								
		{
			a.data[a.top] = t;				//���t��㲻Ϊ�յĻ���ѹջ����д������
			a.tag[a.top] = 0;		
			a.top++;
			t = t->lchild;					//ת������
		}
		else if (a.tag[a.top-1]==1)			//���������������������������ˣ��͵�ջ������ջ����һ���
		{
			a.top--;
			t = a.data[a.top];
			printf("%c", t->data);
			t = NULL;						//��t����Ϊnull��Ȼ�����while���жϣ����ջ��Ԫ��Ҳ�������ˣ��ͽ���
		}
		else
		{
			t = a.data[a.top - 1];			//���ֻ�������������������
			a.tag[a.top - 1] = 1;
			t = t->rchild;
		}
	}
}
int main()
{
	printf("�����봴���Ķ�����ǰ�����˳��\n");
	creat_tree();
	printf("������������ɣ�\n\n");
	printf("ǰ��������Ϊ:\n");
	preorder(root);
	printf("\n\n");
	printf("����������Ϊ:\n");
	inorder(root);
	printf("\n\n");
	printf("����������Ϊ:\n");
	postorder(root);
	printf("\n\n");
	printf("ǰ��������Ϊ(�ǵݹ�):\n");
	preorder_(root);
	printf("\n\n");
	printf("����������Ϊ(�ǵݹ�):\n");
	inorder_(root);
	printf("\n\n");
	printf("����������Ϊ(�ǵݹ�):\n");
	postorder_(root);
	printf("\n\n");
	return 0;
}