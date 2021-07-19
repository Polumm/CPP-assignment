#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>//仅用于leftTrim去空格
using namespace std;
void addStr(char a[], char b[], char c[], const int N, int & tag);//用来生成加和后的新数组
char addChar(char ch1, char ch2, int & tag);//用来实现按位加法运算
void leftTrim(char str[]);//去掉字符串前面的空格
void HecToDec(char a[]);//对每一位，由十六进制ASCII值转为十进制数值（将大小写和数字“连了起来”，求和的时候就不需要考虑与ASCII的跨越）

int main()
{
	int tag = 0;
	const int N = 20;
	char a[N + 1] = { 0 }, b[N + 1] = { 0 }, c[N + 2] = { 0 };//预留串结束符和进位
	cout << "a = ";
	cin.getline(a, N + 1, '\n');
	HecToDec(a);//转换进制与数制
	cout << "b = ";
	cin.getline(b, N + 1);
	HecToDec(b);
	addStr(a, b, c, N, tag);//生成新数组
	cout << "十六进制运算结果为：" << c << endl;
	return 0;
}

void addStr(char a[], char b[], char c[], const int N, int & tag)
{
	int i, j, k;
	memset(c, ' ', N + 2);
	i = strlen(a) - 1;//strlen() - 1锁定最后一个数位的数组下标
	j = strlen(b) - 1;
	k = N;
	while (i >= 0 && j >= 0)
		c[k--] = addChar(a[i--], b[j--], tag);//从低位到高位对齐相加
	while (i >= 0)
		c[k--] = addChar(a[i--], 0, tag);//0补齐，这里与超长整数那道题不一样，因为已经进行了数制转换，不传‘0’，传0即可
	while (j >= 0)
		c[k--] = addChar(b[j--], 0, tag);
	if (tag == 1)//最高位如果还需进位
		c[k] = '1';
	c[N + 1] = '\0';
	leftTrim(c);
}

char addChar(char ch1, char ch2, int & tag)
{
	char ch,temp;
	ch = (ch1 + ch2) + tag;//按位加和，考虑进位
	temp = ch % 16;//逢十六进一，剩余的数
	if (ch >= 16) //逢十六进一
	{	
		tag = 1;
		if (temp > 9)
			temp += ('A' - 10);//10-15用A-F表示
		else temp += '0';
	}
	else
	{
		tag = 0;
		if (temp > 9)
			temp += ('A' - 10);//10-15用A-F表示
		else temp += '0';
	}
	return temp;
}

void leftTrim(char str[])
{
	int i;
	for (i = 0; str[i] == ' '; i++)
		strcpy(str, str + i);//数组名作为地址不断左移
}

void HecToDec(char a[])//对每一位，由十六进制ASCII值转为十进制<数值>，将大小写和数字“连了起来”
{
	for (int i = 0; a[i] != '\0'; i++)
	{
		if ((a[i] >= 'A') && (a[i] <= 'F'))
		{
			a[i] = a[i] - 'A' + 10;
		}
		else if ((a[i] >= 'a') && (a[i] <= 'f'))
		{
			a[i] = a[i] - 'a' + 10;//求和的时候就不需要考虑数字、大小写ASCII码不连续的问题，全部都是数值
		}
		else if ((a[i] >= '0') && (a[i] <= '9'))
		{
			a[i] = a[i] - '0';
		}
	}
}

