#include <iostream>
using namespace std;
int main()
{
	int a, b, c;
	cout << "两十六进制数的加法" << endl;
	cout << "=======================" << endl;
	cout << "请输入两个十六进制数：" << endl;
	cin >> hex >> a >> hex >> b;
	c = a + b;
	cout << "八进制结果：" << oct << c << endl;
	cout << "十进制结果：" << dec << c << endl;
	cout << "十六进制结果：" << hex << c << endl;
}
