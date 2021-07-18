#include"Songchujia.h"
#include"Zhaojingsheng.h"
//======================================================================
//功能函数区
//======================================================================
//2.可能超出整数表示范围的两个整数相加的功能函数
void func2()
{
	system("cls");//清屏
	int tag = 0;
	const int N = 20;
	char a[N+1] = { 0 }, b[N + 1] = { 0 }, c[N + 2] = { 0 };//预留串结束符和进位
	cout << "a = ";
	cin.sync();
	cin.getline(a,N + 1);
	cin.getline(a, N+1);
	cout << "b = ";
	cin.getline(b, N + 1);
	addStr(a, b, c, N, tag);
	cout << "运算结果为：" << c << endl;
	system("pause");
}

//3.两个十六进制数相加的功能函数
void func3()
{
	system("cls");//清屏
	int tag = 0;
	const int N = 20;
	char a[N + 1] = { 0 }, b[N + 1] = { 0 }, c[N + 2] = { 0 };//预留串结束符和进位
	cout << "a = ";
	cin.sync();
	cin.getline(a, N + 1);
	cin.getline(a, N + 1);
	HecToDec(a);//转换进制与数制，详见子函数区
	cout << "b = ";
	cin.getline(b, N + 1);
	HecToDec(b);
	addStr2(a, b, c, N, tag);
	cout << "十六进制运算结果为：" << c << endl;
	system("pause");
}

//4.两个复数相加的功能函数
void func4()
{
	system("cls");//清屏
	complex c1, c2, c3;
	c1.set();
	c2.set();
	c3 = c1 + c2;
	c3.show();
	system("pause");
}

//5.两个日期数据相减的功能函数
void func5()
{
	system("cls");//清屏
	cout << "=========================" << endl;
	Date date1, date2;
	date1.set(); date2.set();
	int c = date1 - date2;
	cout << "两日期间相差：" << c << "天" << endl;
	cout << "=========================" << endl;
	system("pause");
}

//7.两个集合相加（其中没有重复数据）的功能函数
void func7()
{
	system("cls");//清屏
	Set a, b, c;
	a.set();
	cout << "=========================" << endl;
	b.set();
	cout << "=========================" << endl;
	c = a + b;
	c.show();
	cout << endl;
	system("pause");
}





//================================================================
// 子函数区
//================================================================
//2.超长整数加法的子函数
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
//================================================================
//3.十六进制数加法的子函数
void addStr2(char a[], char b[], char c[], const int N, int& tag)
{
	int i, j, k;
	memset(c, ' ', N + 2);
	i = strlen(a) - 1;//strlen() - 1锁定最后一个数位的数组下标
	j = strlen(b) - 1;
	k = N;
	while (i >= 0 && j >= 0)
		c[k--] = addChar2(a[i--], b[j--], tag);//从低位到高位对齐相加
	while (i >= 0)
		c[k--] = addChar2(a[i--], 0, tag);//0补齐，这里与超长整数那道题不一样，因为已经进行了数制转换，不传‘0’，传0即可
	while (j >= 0)
		c[k--] = addChar2(b[j--], 0, tag);
	if (tag == 1)//最高位如果还需进位
		c[k] = '1';
	c[N + 1] = '\0';
	leftTrim(c);
}

char addChar2(char ch1, char ch2, int& tag)
{
	char ch, temp;
	ch = (ch1 + ch2) + tag;
	temp = ch % 16;
	if (ch >= 16)
	{
		tag = 1;
		if (temp > 9)
			temp += ('A' - 10);
		else temp += '0';
	}
	else
	{
		tag = 0;
		if (temp > 9)
			temp += ('A' - 10);
		else temp += '0';
	}
	return temp;
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
			a[i] = a[i] - 'a' + 10;//求和的时候就不需要考虑大小写ASCII的跨越问题，全部都是数值
		}
		else if ((a[i] >= '0') && (a[i] <= '9'))
		{
			a[i] = a[i] - '0';
		}
	}
}

//================================================================
//4.两复数相加的子函数
complex::complex(double i, double j)
{
	real = i;
	image = j;
}

void complex::set()
{
	cout << "请输入实部：" << endl;
	cin >> real;
	cout << "请输入虚部：" << endl;
	cin >> image;
	cout << "输入复数：" << real << 'i' << " + " << image << 'j' << " 成功！" << endl;
}

void complex::show()
{
	cout << "该复数为：" << real << 'i' << " + " << image << 'j' << endl;
}

complex complex::operator + (complex c)
{
	complex temp;
	temp.real = real + c.real;
	temp.image = image + c.image;
	cout << "两复数加和成功！" << endl;
	return temp;
}

//====================================================================
//5.两日期做差的子函数
bool isLeap(int year)
{
	return (year % 4 == 0) || (year % 100 == 0 && year % 400 == 0);
}
int Date::monthDays[12][2] =
{ {31,31},{28,29},{31,31},{30,30},{31,31},
{30,30},{31,31},{31,31},{30,30},{31,31},{30,30},
{31,31} };
void Date::set()
{
	cout << "请输入年份：" << endl;
	cin >> year;
	cout << "请输入月份：" << endl;
	cin >> month;
	cout << "请输入日号：" << endl;
	cin >> day;
	cout << "=========================" << endl;

}
int Date::operator-(Date c)
{
	int number = 0;
	if (year > c.year || month > c.month || day > c.day) //确保被减日期为大的日期
	{
		swap(year, c.year);
		swap(month, c.month);
		swap(day, c.day);
	}
	while (year < c.year || month < c.month || day < c.day) {
		day++;
		//加一天后，相应的月，年可能会发生变化
		if (day == monthDays[month - 1][isLeap(year)] + 1) {
			month++;//当前号超过当前月最高天数：月份加1，号变成下月的1号
			day = 1;
		}
		if (month == 13) {
			year++;//到达一年的最后一天 ：年份加1,月份变成下年的1月
			month = 1;
		}
		number++;
	}
	return number;
}

//======================================================================
//7.两集合相加的子函数
bool compare(string a[], int n, string x)
{
	for (int i = 0; i < n; i++)
		if (a[i] == x) return 0;
	return 1;
}
void Set::set()
{
	cout << "请输入集合的元素个数：";
	cin >> n;
	cout << "请输入集合元素：" << endl;
	p = new string[n];//
	for (int i = 0; i < n; i++)//
	{
		cin >> p[i];
	}
	cout << "集合创建成功！" << endl;
}

Set::Set(int m)
{
	n = m;
	p = new string[m];
}

void Set::show()
{
	cout << "该集合为：" << endl;
	for (int i = 0; i < n; i++)
		cout << p[i] << '\t';
}

Set Set::operator + (Set c)
{
	int m = n + c.n;
	int same = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < c.n; j++)
		{
			if (c.p[j] == p[i])
				same++;//重复元素个数
		}

	}
	Set temp(m - same);
	int i = 0;
	int j = 0;
	for (; i < (m - same); i++, j++)
	{
		if (i < n)
		{
			temp.p[i] = p[i];
		}
		else
		{
			if (compare(p, n, c.p[j - n]))//重复元素不放入新集合
				temp.p[i] = c.p[j - n];
			else i--;
		}
	}
	cout << "两集合加和成功！" << endl;
	return temp;
}
