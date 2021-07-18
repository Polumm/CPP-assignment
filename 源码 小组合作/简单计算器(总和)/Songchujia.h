#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include"Zhaojingsheng.h"
using namespace std;
//================================================
//2.超长整数加法的声明
void addStr(char a[], char b[], char c[], const int N, int& tag);//用来生成加和后的新数组
char addChar(char ch1, char ch2, int& tag);//用来实现加法运算
void leftTrim(char str[]);//去掉字符串前面的空格


//================================================
//3.两个十六进制数相加的声明
using namespace std;
void addStr2(char a[], char b[], char c[], const int N, int& tag);//用来生成加和后的新数组
char addChar2(char ch1, char ch2, int& tag);//用来实现加法运算
void leftTrim(char str[]);//去掉字符串前面的空格
void HecToDec(char a[]);//对每一位，由十六进制ASCII值转为十进制数值（将大小写和数字“连了起来”，求和的时候就不需要考虑与ASCII的跨越）

//================================================
//4.两复数相加的声明
class complex
{
private:
	double real, image;//实部和虚部
public:
	complex(double real = 0.0, double image = 0.0);
	void set();//与用户交互，实现初始化
	void show();
	complex operator +(complex c);//返回类型 operator运算符 (形参列表)

};

//================================================
//5.两日期做差的声明
class Date
{
private:
	int date, year, month, day;
	static int monthDays[12][2];
public:
	void set();
	int operator- (Date c);	//日期作差的运算符重载
};

//================================================
//7.两集合相加的声明
class Set
{
private:
	int n;//集合元素个数
	string* p = NULL;//操作集合的指针
public:
	Set() { ; }
	Set(int m);
	void set();		//在set()函数中与用户交互，实现初始化
	void show();
	Set operator +(Set c);	//加法的重载
};
