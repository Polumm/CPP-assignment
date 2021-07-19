#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>//������leftTrimȥ�ո�
using namespace std;
void addStr(char a[], char b[], char c[], const int N, int& tag);//�������ɼӺͺ��������
char addChar(char ch1, char ch2, int& tag);//����ʵ�ּӷ�����
void leftTrim(char str[]);//ȥ���ַ���ǰ��Ŀո�

int main()
{
	int tag = 0;
	const int N = 20;
	char a[N + 1] = { 0 }, b[N + 1] = { 0 }, c[N + 2] = { 0 };//Ԥ�����������ͽ�λ
	cout << "a = ";
	cin.sync();
	cin.getline(a, N + 1);
	cout << "b = ";
	cin.getline(b, N + 1);
	addStr(a, b, c, N, tag);
	cout << "������Ϊ��" << c << endl;
	return 0;
}

void addStr(char a[], char b[], char c[], const int N, int& tag)
{
	int i, j, k;
	memset(c, ' ', N + 2);
	i = strlen(a) - 1;//strlen() - 1�������һ����λ�������±�
	j = strlen(b) - 1;
	k = N;
	while (i >= 0 && j >= 0)
		c[k--] = addChar(a[i--], b[j--], tag);//�ӵ�λ����λ�������
	while (i >= 0)
		c[k--] = addChar(a[i--], '0', tag);//ASCII�����㣬'0'����
	while (j >= 0)
		c[k--] = addChar(b[j--], '0', tag);
	if (tag == 1)//���λ��������λ
		c[k] = '1';
	c[N + 1] = '\0';
	leftTrim(c);
}

char addChar(char ch1, char ch2, int& tag)
{
	char ch;
	ch = (ch1 - '0' + ch2 - '0') + tag;//��ASCII�ַ�����
	if (ch >= 10)
	{
		tag = 1;
		return (ch - 10 + '0');//returnʱת�ɶ�ӦASCII��
	}
	else
	{
		tag = 0;
		return(ch + '0');
	}
}

void leftTrim(char str[])
{
	int i;
	for (i = 0; str[i] == ' '; i++)
		strcpy(str, str + i);//��������Ϊ��ַ��������
}

