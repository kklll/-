#include "Show.h"
#include<graphics.h>
#include<conio.h>
#include<math.h>
#define RED RGB(227,23,13)	//�궨���ߵ���ɫ
void Show::draw(string s, int n)
{
	initgraph(1000, 700);				//��ʼ��ͼ�λ������С
	setbkcolor(WHITE);					//���ñ��������ɫ	
	cleardevice();						//�������	
	setcolor(RED);					//����ֱ����ɫ
	setorigin(1000 / 2, 300);		//����ԭ��
	if (n > 9)
		setaspectratio(pow(0.80, n - 5), pow(0.80, n - 5));
	for (int i = 0; i < s.length(); i++)
		//�Խ���ַ������б���
	{
		char j = s.at(i);
		if (j == 'F') {
			//���ΪF����ǰ����10����
			Show::forward(10);
		}
		if (j == '+') {
			//���Ϊ+����ת90��
			Show::left();
		}
		if (j == '-') {
			;
			//���Ϊ-����ת90��
			Show::right();
		}
		if (j == 'X' || j == 'Y')
		{
			//���ΪX����Y���򲻽��в���
			continue;
		}
	}
	int x = _getch();					// ���������롣
	closegraph();						// �رջ�ͼ����
}

void Show::forward(int dis)
{
	switch (angle)
	{
		//��������µ�����ת������
	case 0:
		linerel(dis, 0);
		//��������Ϊ�����������Ϊ��׼�Ļ���
		//EasyX������Ϊ���Ͻ�Ϊ����ԭ�㣬
		//����x����Ϊ����������
		//����y����Ϊ���������������
		break;
	case 90:
		linerel(0, -dis);
		break;
	case 180:
		linerel(-dis, 0);
		break;
	case 270:
		linerel(0, dis);
		break;
	default:
		break;
	}
}

void Show::left()
{
	//��ת��������ԭ��ĽǶȼ���90������360����ȡ������õ���ת��ĽǶ�
	angle = (angle + 90) % 360;
}

void Show::right()
{
	//��ת��������ԭ��ĽǶȼ�ȥ90������360����ȡ������õ���ת��ĽǶ�
	//��Ҫ���������������0����ת��Ƕ�Ϊ270�㣬��Ҫ����С��0ʱת����ϵ
	if (angle - 90 < 0)
	{
		angle = 360 - 90;
	}
	else
	{
		angle = (angle - 90) % 360;
	}
}
