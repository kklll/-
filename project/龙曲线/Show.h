#pragma once
#include <string>
#include<iostream>
using namespace std;
/*
���й�����Ķ��壺
	����draw����Ϊ����ͼ�λ���������ĺ���
	angle��Ϊ���ϵĽǶȱ任
	frowardΪͼ����ǰ����
	left��ԭ��Ƕ�����ת90��
	right��ԭ��Ƕ�����ת��80��
*/
class Show
{
public:
	Show();
	static void draw(string s, int n);
	static int angle;
	static void forward(int dis);
	static void left();
	static void right();
};