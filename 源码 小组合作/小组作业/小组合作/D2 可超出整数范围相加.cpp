#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>//仅用于leftTrim去空格
using namespace std;
void addStr(char a[], char b[], char c[], const int N, int& tag);//用来生成加和后的新数组
char addChar(char ch1, char ch2, int& tag);//用来实现加法运算
void leftTrim(char str[]);//去掉字符串前面的空格

int main()
{
	int tag = 0;
	const int N = 20;
	char a[N + 1] = { 0 }, b[N + 1] = { 0 }, c[N + 2] = { 0 };//预留串结束符和进位
	cout << "a = ";
	cin.sync();
	cin.getline(a, N + 1);
	cout << "b = ";
	cin.getline(b, N + 1);
	addStr(a, b, c, N, tag);
	cout << "运算结果为：" << c << endl;
	return 0;
}

void addStr(char a[], char b[], char c[], const int N, int& tag)
{
	int i, j, k;
	memset(c, ' ', N + 2);
	i = strlen(a) - 1;//strlen() - 1锁定最后一个数位的数组下标
	j = strlen(b) - 1;
	k = N;
	while (i >= 0 && j >= 0)
		c[k--] = addChar(a[i--], b[j--], tag);//从低位到高位对齐相加
	while (i >= 0)
		c[k--] = addChar(a[i--], '0', tag);//ASCII码运算，'0'补齐
	while (j >= 0)
		c[k--] = addChar(b[j--], '0', tag);
	if (tag == 1)//最高位如果还需进位
		c[k] = '1';
	c[N + 1] = '\0';
	leftTrim(c);
}

char addChar(char ch1, char ch2, int& tag)
{
	char ch;
	ch = (ch1 - '0' + ch2 - '0') + tag;//对ASCII字符处理
	if (ch >= 10)
	{
		tag = 1;
		return (ch - 10 + '0');//return时转成对应ASCII码
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
		strcpy(str, str + i);//数组名作为地址不断左移
}

