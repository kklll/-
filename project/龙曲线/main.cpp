#include<iostream>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#include"Show.h"
using namespace std;
string result;//	����ȫ�ֱ���result����¼ͼ�ε��ַ������
string toUpper(string s);
void dragonCurve(const string seed, int n);//���������
void dragonCurve2(const string seed, int n, unsigned long long int p, unsigned long long int l);//�������
void menu();//��ʾĿ¼�ĺ���
void function1();//��ʾȫ�������ߺ���
void function2();//��ʾָ��λ�������ߵĺ���
int choose(int y);//���Ϊż������г���������ֱ��Ϊ����Ϊֹ
void show(int x);//�ж���������λ��Ϊ

int choose(int y)
{
	if (y % 2 == 1)
		return y;
	else
		return choose(y / 2);
}
void show(int x)
{
	int a = choose(x);
	if (((a + 1) / 2) % 2 == 0) {
		result += '-';
	}
	else {
		result += '+';
	}
}

int main()
{
	int num;
	menu();

	while (true)
	{
		cin >> num;
		switch (num)
		{
		case 1:
			system("cls");
			function1();
			break;
		case 2:
			system("cls");
			function2();
		case -1:
			exit(0);
			break;
		}
	}

	return 0;
}

void dragonCurve(const string seed, int n) {//�ݹ����������ߵĻ�ͼ��ʾ
	if (n == 0) {
		//cout << seed;
		result.append(seed);
		return;
	}
	for (int i = 0; i < seed.size(); i++) {
		if (seed[i] == 'X')
			dragonCurve("X+YF", n - 1);
		//��������ݹ��滻
		else if (seed[i] == 'Y')
			dragonCurve("FX-Y", n - 1);
		//��������ݹ��滻
		else {
			result += seed[i];
			//�����ܽ�����ַ�������
		}
	}
}

void dragonCurve2(const string seed, int n, unsigned long long int p, unsigned long long int l) {//�ݹ����������ߵĻ�ͼ��ʾ
	for (int i = p; i < p + l; i++)
	{
		if (i % 6 == 1 || i % 6 == 5)
		{
			result += 'F';
		}
		if (i % 6 == 2)
		{
			result += 'X';
		}
		if (i % 6 == 4) {
			result += 'Y';
		}
		if (i % 3 == 0)
		{
			int x = i / 3;
			show(x);
		}
	}
}

//static�����ĳ�ʼ����
int Show::angle = 0;
string toUpper(string s)
/*
��Сд��ĸת��Ϊ��д��ĸ��ͳһ�ַ���ʽ��
�������Է�ֹ������������ɵĳ������
*/
{
	for (int i = 0; i < s.length(); i++)
	{
		char c = s[i];
		if ((c >= 'a') && (c <= 'z'))
			s[i] = s[i] - 32;
	}
	return s;
}
void menu()
{
	cout << "�����������¹��ܣ�" << endl;
	cout << "1:������������ߵ�ͼ���Լ�ͼ�α��ʽ��" << endl;
	cout << "2:���ָ�����������ߵı��ʽ�Լ�ͼ�Ρ�" << endl;
	cout << "�˳�������-1��" << endl;
	cout << "��������ѡ���ܵ���ţ�" << endl;
}
void function1()
{
	cout << "��������˫���ߵ���ʼ����:(����:FX)" << endl;
	cout << "���и�����ĸ��ʾΪ:" << endl;
	cout << "F����ǰ���ƶ�һ�񲢻��ߡ�" << endl;
	cout << "+��������ת90�ȡ�" << endl;
	cout << "-��������ת90�ȡ�" << endl;
	cout << "X��Y�����ԡ�" << endl;
	string seed;
	cin >> seed;
	seed = toUpper(seed);
	int count;
	cout << "���������Ĳ��������ĸ���:";
	cin >> count;
	int i = 0;
	while (i < count)
	{
		int n;//�����ߴ���
		cout << "�����������ߵ�����n��0<=n<=50����" << endl;
		cin >> n;
		dragonCurve(seed, n);	//���Ӻʹ���
		cout << "�����ߵ��ַ�����ʾΪ��" << endl;
		cout << result << endl;
		cout << "�����ߵ��ַ�����Ϊ��" << endl;
		cout << result.length() << endl;
		system("pause");
		Show::draw(result, n);
		result.clear();
		Show::angle = 0;
		i++;
	}
	system("pause");
	system("cls");
	menu();
}
void function2()
{
	cout << "��������˫���ߵ���ʼ����:(����:FX)" << endl;
	cout << "���и�����ĸ��ʾΪ:" << endl;
	cout << "F����ǰ���ƶ�һ�񲢻��ߡ�" << endl;
	cout << "+��������ת90�ȡ�" << endl;
	cout << "-��������ת90�ȡ�" << endl;
	cout << "X��Y�����ԡ�" << endl;
	string seed;
	cin >> seed;
	seed = toUpper(seed);
	int count;
	cout << "���������Ĳ��������ĸ���:";
	cin >> count;
	int i = 0;
	while (i < count)
	{
		int n;//�����ߴ���
		unsigned long long int p;//��������ʼλ��
		unsigned long long int l;//Ҫ��ʾ�������߳���
		cout << "�����������ߵ�����n��0<=n<=50����p�Լ�l��1<=p<=1 000 000 000��1<=l<=50����" << endl;
		cin >> n >> p >> l;
		if (p > 3 * pow(2, n) - 1 || p > 3 * pow(2, n) - 1 + l)
		{
			cout << "����ָ��Խ�磬������ָ��!" << endl;
			exit(0);
		}
		dragonCurve2(seed, n, p, l);	//���Ӻʹ���
		cout << "�����ߵ��ַ�����ʾΪ��" << endl;
		cout << result << endl;
		cout << "�����ߵ��ַ�����Ϊ��" << endl;
		cout << result.length() << endl;
		system("pause");
		Show::draw(result, 2);
		result.clear();
		Show::angle = 0;
		i++;
	}
	system("pause");
	system("cls");
	menu();
}