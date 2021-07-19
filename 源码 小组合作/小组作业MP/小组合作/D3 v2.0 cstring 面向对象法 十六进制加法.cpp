#include <iostream>
using namespace std;
class hexInt
{
private:
	int a;
public:
	hexInt() { ; }
	void set();
	hexInt operator+ (hexInt c);//加号的重载
	void showOct() { cout << "八进制表示为：" << oct << a << endl; }
	void showDec() { cout << "十进制表示为：" << dec << a << endl; }
	void showHex() { cout << "十六进制表示为：" << hex << a << endl; }
};
void hexInt::set()
{ 
	cout << "请输入一个十六进制数：" << endl;
	cin >> hex >> a;
};
hexInt hexInt::operator+ (hexInt c)
{
	hexInt temp;
	temp.a = a + c.a;
	cout << "===========================" << endl;
	cout << "加法运算成功,结果为：" << hex << temp.a << endl;
	return temp;
}
int main()
{
	hexInt a, b, c;
	a.set(); b.set();
	c = a + b;
	c.showOct();
	c.showDec();
	c.showHex();
}
