////���뻷��vs2017������Ϊ������
//
//#include<stdio.h>
//#include<stdlib.h>
//typedef int datatype;
//typedef struct  link_node
//{
//	datatype info;
//	struct link_node *next;
//}node;							//����ṹ��
//void *init()
//{
//	return NULL;
//}
//void display(node *head)		//������ʾ����
//{
//	node *p;
//	p = head;
//	if (!p)
//		printf("������Ϊ�գ��޷�����\n");
//	else
//	{
//		printf("��������ڵ�ֵΪ:\n");
//		while (p)
//		{
//			printf("%5d", p->info);
//			p = p->next;
//		}
//		printf("\n");
//	}
//}
//node *find(node *head, int i)		//���ҽ��iλ�ô������ݵ�ַ
//{
//	int j = 1;
//	node *p = head;
//	if (i < 1)
//		return NULL;
//	while (p&&i != j)
//	{
//		p = p->next;
//		j++;
//	}
//	return p;
//}
//node *insert(node *head, datatype x, int i)			//���ݲ��룬���ڽڵ�i����壩
//{
//	node *p, *q;
//	q = find(head, i);
//	if (!q&&i != 0)
//		printf("�Ҳ�����%d�ڵ�,���ܲ���%d!\n", i, x);
//	else
//	{
//		p = (node*)malloc(sizeof(node));	//�����ڴ�
//		p->info = x;
//		if (i == 0)		//�������λ��Ϊ��һ���ڵ�֮��
//		{
//			p->next = head;
//			head = p;
//		}
//		else
//		{
//			p->next = q->next;
//			q->next = p;
//		}
//	}
//	return head;
//}
////
////node *function1(node *head,datatype y, int i)	////���ݲ��룬���ڽڵ�i��ǰ�壩
////{
////	node *p, *q, *abc;
////	q = find(head, i);
////	if (!q&&i != 0)
////		printf("�Ҳ�����%d�ڵ�,���ܲ���%d!\n", i, x);
////	else
////	{
////		abc = head;
////		while (abc->next != q)
////		{
////			abc = abc->next;
////		}
////		insert(head,x)
////}
//node *dele(node *head, datatype x)		//ɾ��һ��ֵΪx�Ľڵ�
//{
//	node *pre = NULL, *p = NULL;
//	if (!head)
//	{
//		printf("����Ϊ�գ�");
//		return head;
//	}
//	p = head;
//	while (p&&p->info != x)
//	{
//		pre = p;
//		p = p->next;
//	}
//	if (p)
//	{
//		if (!pre)		//���ɾ���ڵ�Ϊ��ʼ��head�ڵ�
//			head = head->next;
//		else            //���ɾ������Ϊ�м�ڵ�
//			pre->next = p->next;
//		free(p);
//	}
//	return head;
//}
//node *creat()
//{
//	node *h = NULL, *q = NULL, *p = NULL;
//	int a, n, i;
//	printf("��������ڵ����:\n");
//	scanf_s("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//		printf("�����%d������:\n", i);
//		scanf_s("%d", &a);
//		p = (node *)malloc(sizeof(node));
//		p->info = a; p->next = NULL;
//		if (i == 1)
//		{
//			h = p; q = p;
//		}
//		else
//		{
//			q->next = p; q = p;
//		}
//	}
//	return h;
//}
//node *reverse(node *head)
//{
//	node *p = head->next, *q = NULL;
//	node *pre;
//	p = p->next;
//	q = NULL;
//	head->next = NULL;
//	while (p)
//	{
//		pre = p->next;
//		p->next = q;
//		q = p;
//		p = pre;
//	}
//	head->next = q;
//	return head;
//}
//int *count(node *head)
//{
//	int i = 0;
//	node *p = head;
//	while (p)
//	{
//		p = p->next;
//		i++;
//	}
//	return i;
//}
//node function2(node *head)
//{
//	node *p, *q;
//	int i = 1,j=1;
//	p = head;
//	q = head;
//	if (head->next == NULL)
//	{
//		printf("������ֻ��һ���ڵ㣡");
//		exit(0);
//	}
//	else
//	{
//		p = p->next;
//	}
//	if(p->info>=q->info)
//	{
//		while (p)
//		{
//			if (p->info >= q->info)
//				i++;
//			q = p;
//			p = p->next;
//		}
//	}
//	p = head;
//	q = head;
//	if (p->info < q->info)
//	{
//		while (p)
//		{
//			if (p->info < q->info)
//				j++;
//			q = p;
//			p = p->next;
//		}
//	}
//	if (count(head)==i||count(head)==j)
//	{
//		printf("������������ģ�");
//	}
//	else
//	{
//		printf("����������");
//	}
//}
//int main()
//{
//	int i, j;
//	node *head = NULL;
//	head = creat();
//	/*display(head);
//	printf("�����������ֵ:\n");
//	scanf_s("%d", &i);
//	printf("���������λ��:\n");
//	scanf_s("%d", &j);
//	head = insert(head, i, j);
//	display(head);
//	printf("��������ҽ��:\n");
//	scanf_s("%d", &i);
//	printf("�ý��ֵΪ:\n%5d\n", *find(head, i));
//	printf("������Ҫɾ����ֵ:\n");
//	scanf_s("%d", &i);
//	head = dele(head, i);
//	display(head);*/
//	/*reverse(head);*/
//	display(head);
//	function2(head);
//}