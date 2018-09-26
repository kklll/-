//���뻷��vs2017������Ϊ��ͷ������

#include<stdio.h>
#include<stdlib.h>
typedef int datatype;
typedef struct  link_node
{
	datatype info;
	struct link_node *next;
}node;							//��������ṹ��
void *init()
{
	node *head;
	head = (node *)malloc(sizeof(node));
	head->next = NULL;
	return head;
}
void display(node *head)		//������ʾ����
{
	node *p;
	p = head->next;
	if (!p)
		printf("������Ϊ��\n");
	else
	{
		printf("��������ڵ�ֵΪ:\n");
		while (p)
		{
			printf("%5d", p->info);
			p = p->next;
		}
		printf("\n");
	}
}
node *find(node *head, int i)		//���ҽ��iλ�ô������ݵ�ַ
{
	int j = 0;
	node *p = head;
	if (i < 0)
	{
		printf("��ͷ�ڵ���������ڵ�%d����㣡", i);
		return NULL;
	}
	else if (i == 0)
		return p;
	while (p&&i != j)
	{
		p = p->next;
		j++;
	}
	return p;
}
node *insert(node *head, datatype x, int i)			//���ݲ��룬���ڽڵ�i����壩
{
	node *p, *q;
	q = find(head, i);
	if (!q)
	{
		printf("�Ҳ�����%d�ڵ�,���ܲ���%d!\n", i, x);
		return head;
	}
	else
	{
		p = (node*)malloc(sizeof(node));	//�����ڴ�
		p->info = x;
		p->next = q->next;
		q->next = p;
		return head;
	}
}
node *dele(node *head, datatype x)		//ɾ��һ��ֵΪx�Ľڵ�
{
	node *pre = head, *p = NULL;
	p = head->next;
	while (p&&p->info != x)
	{
		pre = p;
		p = p->next;
	}
	if (p)
	{
		pre->next = p->next;
		free(p);
	}
	return head;
}
node *creat(node *head)
{
	node *h = NULL, *q = NULL, *p = NULL;
	int a, n, i;
	printf("��������ڵ����:\n");
	scanf_s("%d", &n);
	for (i = 1; i <= n; i++)
	{
		printf("�����%d������:\n", i);
		scanf_s("%d", &a);
		p = (node *)malloc(sizeof(node));
		p->info = a;
		p->next = NULL;
		if (i == 1)
		{
			head->next = p;
			q = p;
		}
		else
		{
			q->next = p;
			q = p;
		}
	}
	return h;
}
int main()
{
	node *head;
	head=init();
	creat(head);
	display(head);
}
