:////���뻷��vs2017
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//typedef char datatype;
//typedef struct  link_node
//{
//	char name[20];
//	char xuehao[20];
//	char phone[20];
//	struct link_node *next;
//}node;							//����ṹ��
//node *init()
//{
//	return NULL;
//}
//void display(node *head)		//������ʾ����
//{
//	node *p;
//	p = head;
//	if (!p)
//		printf("������Ϊ�գ�\n");
//	else
//	{
//		printf("%5s\t%5s\t%5s\n", "����", "ѧ��", "��ϵ��ʽ");
//		while (p)
//		{
//			printf("%5s\t", p->name);
//			printf("%5s\t", p->xuehao);
//			printf("%5s\t", p->phone);
//			p = p->next;
//			printf("\n");
//		}
//		printf("\n");
//		printf("��ɣ�\n");
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
//node *insert(node *head)			//���ݲ��룬���ڽڵ�i����壩
//{
//	node *p, *q;
//	int i;
//	printf("������Ҫ����Ľ��λ��:");
//	scanf_s("%d", &i);
//	q = find(head, i);
//	if (!q&&i != 0)
//		printf("�Ҳ�����%d�ڵ�,���ܲ���.\n", i);
//	else
//	{
//		p = (node*)malloc(sizeof(node));	//�����ڴ�
//		printf("������ѧ��:");
//		getchar();
//		gets(p->xuehao);
//		printf("����������:");
//		gets(p->name);
//		printf("��������ϵ��ʽ(�ֻ�����):");
//		gets(p->phone);
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
//	printf("��ɣ�\n");
//	return head;
//}
//node *dele(node *head)		//ɾ��ѧ��Ϊx�Ľڵ�
//{
//	node *pre = NULL, *p = NULL;
//	char name[20];
//	if (!head)
//	{
//		printf("����Ϊ�գ�");
//		return head;
//	}
//	p = head;
//	printf("������Ҫɾ����ѧ����������");
//	getchar();
//	gets(name);
//	while (p&&strcmp(p->name,name)!=0)
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
//	}
//	free(p);
//	printf("��ɣ�\n");
//	return head;
//}
//node *creat()
//{
//	node *h=NULL, *q=NULL, *p=NULL;
//	int n, i;
//	printf("����Ҫ¼��ѧ������:\n");
//	scanf_s("%d", &n);
//	for (i = 1; i <= n; i++)
//	{
//
//		printf("�����%d������:\n", i);
//		p = (node *)malloc(sizeof(node));
//		if(i==1)
//		getchar();
//		printf("������ѧ��:");
//		gets(p->xuehao);
//		printf("����������:");
//		gets(p->name);
//		printf("��������ϵ��ʽ(�ֻ�����):");
//		gets(p->phone);
//		p->next = NULL;
//		if (i == 1)
//		{
//			h = p; q = p;
//		}
//		else
//		{
//			q->next = p; q = p;
//		}
//	}
//	printf("��ɣ�\n");
//	return h;
//}
//void display_name(node *head)
//{
//	node *p=head;
//	char name[20];
//	printf("������Ҫ��ͬѧ������:");
//
//	getchar();
//	gets(name);
//	while (strcmp(p->name,name)!=0 && p!=NULL)
//		p = p->next;
//	if (!p)
//	{
//		printf("�Ҳ�����ͬѧ");
//	}
//	else
//	{	
//		printf("\n");
//		printf("��ͬѧѧ��Ϊ:%s\n", p->xuehao);
//		printf("��ͬѧ����Ϊ:%s\n", p->name);
//		printf("��ͬѧ��ϵ��ʽΪ:%s\n", p->phone);
//		printf("\n");
//		printf("��ɣ�\n");
//	}
//}
//int main()
//{
//	node *head=NULL;
//	int func;
//	printf("�����������¹���:\n");
//	printf("1:����ѧ����ϵ��ʽ\n");
//	printf("2:����ѧ����ϵ��ʽ:\n");
//	printf("3:ɾ��ĳλѧ����ϵ��ʽ\n");
//	printf("4:������Ϊ��������ѧ����ϵ��ʽ\n");
//	printf("5:���ȫ��ѧ����Ϣ\n");
//	printf("6:�˳�ϵͳ\n");
//	printf("��ѡ�������:");
//	scanf_s("%d", &func);
//	while (func != 6)
//	{
//		switch (func)
//		{
//		case 1:
//			head = init();
//			head = creat();
//			break;
//		case 2:
//			head = insert(head);
//			break;
//		case 3:
//			head = dele(head);
//			break;
//		case 4:
//			display_name(head);
//			break;
//		case 5:
//			display(head);
//			break;
//		}
//		printf("\n");
//		system("pause");
//		system("cls");
//		printf("�����������¹���:\n");
//		printf("1:����ѧ����ϵ��ʽ\n");
//		printf("2:����ѧ����ϵ��ʽ:\n");
//		printf("3:ɾ��ĳλѧ����ϵ��ʽ\n");
//		printf("4:������Ϊ��������ѧ����ϵ��ʽ\n");
//		printf("5:���ȫ��ѧ����Ϣ\n");
//		printf("6:�˳�ϵͳ\n");
//		printf("��ѡ�������:");
//		scanf_s("%d", &func);
//		printf("\n");
//	}
//	return 0;
//}
