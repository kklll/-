//#include<stdio.h>
//#include<stdlib.h>
//typedef char datatype;
//typedef struct node {            //�������Ľṹ�嶨��
//	datatype data;
//	struct node *lchild;
//	struct node *rchild;
//}tree;
//typedef struct stack {			//ջ�ṹ����
//	int top;
//	tree *data[100];			//��¼����ַ
//	int count;
//}zhan;
//tree *root;
//tree *creat_tree()          //�ݹ鷽������������(ǰ�򴴽�),����Ļ���Ҫһ��ȫ�����롣
//{
//	static int a = 0;
//	datatype ch;
//	tree *t;
//	if ((ch = getchar()) == '!')
//		t = NULL;
//	else
//	{
//		t = (tree *)malloc(sizeof(tree));
//		if (a == 0)
//		{
//			root = t;
//			a++;
//		}
//		t->data = ch;
//		t->lchild = creat_tree();
//		t->rchild = creat_tree();
//	}
//	return t;
//}
//tree *creat_tree_s()
//{
//	tree *p;
//	zhan s;
//	char a[100];
//	int i=0;
//	gets(a);
//	while (a[i] != '\0')
//	{
//		i++;
//		if (a[i-1] != '!')
//		{
//			p = (tree *)malloc(sizeof(tree));
//		}
//	}
//
//	return root;
//}
///*
//while (*str != '\0')
//{
//	str++;
//	if (*(str - 1) != '@')  //�������������һֱδ����@���ţ����������������
//	{					//�����ڵ�ѹ��ջ��
//		stack[top++] = tempRoot;
//		if (*str != '@')    //�жϵ�ǰ�ڵ��ǲ���@�ڵ㣬����ǵ�������Ϊ��
//		{
//			temp = CreateNode(str);
//			tempRoot->lChild = temp;
//			tempRoot = temp;
//		}
//		else
//		{
//			tempRoot->lChild = NULL;
//		}
//
//	}
//	if (*(str - 1) == '@' && top > 0)  //��ǰһ���ڵ���@�����ջ������������
//	{
//		tempRoot = stack[--top];
//		if (*str != '@')//�жϵ�ǰ�ڵ��ǲ���@�ڵ㣬����ǵ�������Ϊ��
//		{
//			temp = CreateNode(str);
//			tempRoot->rChild = temp;
//			tempRoot = temp;
//		}
//		else
//			tempRoot->rChild = NULL;
//	}
//}
//return root;
//*/
//void push(zhan *p,tree *x)
//{
//	p->data[p->top++] = x;
//}
//tree *pop(zhan *p)
//{
//	p->top--;
//	return p->data[p->top];
//}
//void inorder_(tree *t)					//��������ǵݹ��㷨
//{
//	zhan a;
//	int c=0;
//	a.top = 0;							//��ʼ��
//	while (a.top != 0 || t)
//	{
//		if (t)								//t��Ϊ�գ�ѹջ
//		{
//			push(&a,t);
//
//			t = t->lchild;					//��tָ����������
//		}
//		else
//		{
//			t = pop(&a);					//���tΪ����ջ������������ֵ
//			c++;
//			t = t->rchild;	
//		}
//	}
//	printf("%c\n", *a.data[0]);
//}
//int main()
//{
//	creat_tree();
//	inorder_(root);
//}
////ABDG!!H!!!CE!I!!F!!              4
////abd!e!!fg!!!c!!                  3