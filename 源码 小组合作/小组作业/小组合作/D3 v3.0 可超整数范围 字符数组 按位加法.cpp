#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>//������leftTrimȥ�ո�
using namespace std;
void addStr(char a[], char b[], char c[], const int N, int & tag);//�������ɼӺͺ��������
char addChar(char ch1, char ch2, int & tag);//����ʵ�ְ�λ�ӷ�����
void leftTrim(char str[]);//ȥ���ַ���ǰ��Ŀո�
void HecToDec(char a[]);//��ÿһλ����ʮ������ASCIIֵתΪʮ������ֵ������Сд�����֡���������������͵�ʱ��Ͳ���Ҫ������ASCII�Ŀ�Խ��

int main()
{
	int tag = 0;
	const int N = 20;
	char a[N + 1] = { 0 }, b[N + 1] = { 0 }, c[N + 2] = { 0 };//Ԥ�����������ͽ�λ
	cout << "a = ";
	cin.getline(a, N + 1, '\n');
	HecToDec(a);//ת������������
	cout << "b = ";
	cin.getline(b, N + 1);
	HecToDec(b);
	addStr(a, b, c, N, tag);//����������
	cout << "ʮ������������Ϊ��" << c << endl;
	return 0;
}

void addStr(char a[], char b[], char c[], const int N, int & tag)
{
	int i, j, k;
	memset(c, ' ', N + 2);
	i = strlen(a) - 1;//strlen() - 1�������һ����λ�������±�
	j = strlen(b) - 1;
	k = N;
	while (i >= 0 && j >= 0)
		c[k--] = addChar(a[i--], b[j--], tag);//�ӵ�λ����λ�������
	while (i >= 0)
		c[k--] = addChar(a[i--], 0, tag);//0���룬�����볬�������ǵ��ⲻһ������Ϊ�Ѿ�����������ת����������0������0����
	while (j >= 0)
		c[k--] = addChar(b[j--], 0, tag);
	if (tag == 1)//���λ��������λ
		c[k] = '1';
	c[N + 1] = '\0';
	leftTrim(c);
}

char addChar(char ch1, char ch2, int & tag)
{
	char ch,temp;
	ch = (ch1 + ch2) + tag;//��λ�Ӻͣ����ǽ�λ
	temp = ch % 16;//��ʮ����һ��ʣ�����
	if (ch >= 16) //��ʮ����һ
	{	
		tag = 1;
		if (temp > 9)
			temp += ('A' - 10);//10-15��A-F��ʾ
		else temp += '0';
	}
	else
	{
		tag = 0;
		if (temp > 9)
			temp += ('A' - 10);//10-15��A-F��ʾ
		else temp += '0';
	}
	return temp;
}

void leftTrim(char str[])
{
	int i;
	for (i = 0; str[i] == ' '; i++)
		strcpy(str, str + i);//��������Ϊ��ַ��������
}

void HecToDec(char a[])//��ÿһλ����ʮ������ASCIIֵתΪʮ����<��ֵ>������Сд�����֡�����������
{
	for (int i = 0; a[i] != '\0'; i++)
	{
		if ((a[i] >= 'A') && (a[i] <= 'F'))
		{
			a[i] = a[i] - 'A' + 10;
		}
		else if ((a[i] >= 'a') && (a[i] <= 'f'))
		{
			a[i] = a[i] - 'a' + 10;//��͵�ʱ��Ͳ���Ҫ�������֡���СдASCII�벻���������⣬ȫ��������ֵ
		}
		else if ((a[i] >= '0') && (a[i] <= '9'))
		{
			a[i] = a[i] - '0';
		}
	}
}

