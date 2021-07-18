#include <iostream>
#include <cstring>
using namespace std;
bool compare(string a[], int n, string x)//两个元素进行比较，相等返回0
{
	for (int i = 0; i < n; i++)
		if (a[i] == x) return 0;
	return 1;
}
class Set
{
private:
	int n;//集合元素个数
	string *p = NULL;//操作集合的指针
public:
	Set() { ; } //默认构造，保证流程的完整性
	Set(int m);  
	void set();	//赋值函数	
	void show();
	Set operator +(Set c);	//加号的重载
};

void Set::set()//与用户交互的方式实现初始化
{
	cout << "请输入集合A的元素个数：";
	cin >> n;
	cout << "请输入集合元素：" << endl;
	p = new string[n];//动态申请集合
	for (int i = 0; i < n; i++)//用户输入元素
	{
		cin >> p[i];
	}
	cout << "集合创建成功！" << endl;
}

Set::Set(int m)//已知元素个数，创建集合
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

	for (int i = 0; i < n; i++)//先确定两集合重复元素的个数
	{
		for (int j = 0; j < c.n; j++)
		{
			if (c.p[j] == p[i])
				same++;//重复元素个数
		}
		
	}
	Set temp(m-same);//非重复元素的个数即为新集合元素的个数
	int i = 0;
	int j = 0;
	for (; i < (m-same); i++,j++)
	{
		if (i < n)
		{
			temp.p[i] = p[i];//独有的元素直接放入
		}
		else
		{
			if (compare(p, n, c.p[j - n]))//重复的元素在新集合中只放一次
				temp.p[i] = c.p[j - n];
			else i--;
		}
	}
	cout << "两集合加和成功！" << endl;
	return temp;
}

int main()
{
	Set a, b, c;
	a.set();
	cout << "=========================" << endl;
	b.set();
	cout << "=========================" << endl;
	c = a + b;
	c.show();
	cout << endl;
}