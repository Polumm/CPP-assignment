#include <iostream>
using namespace std;
class hexInt
{
private:
	int a;
public:
	hexInt() { ; }
	void set();
	hexInt operator+ (hexInt c);//�Ӻŵ�����
	void showOct() { cout << "�˽��Ʊ�ʾΪ��" << oct << a << endl; }
	void showDec() { cout << "ʮ���Ʊ�ʾΪ��" << dec << a << endl; }
	void showHex() { cout << "ʮ�����Ʊ�ʾΪ��" << hex << a << endl; }
};
void hexInt::set()
{ 
	cout << "������һ��ʮ����������" << endl;
	cin >> hex >> a;
};
hexInt hexInt::operator+ (hexInt c)
{
	hexInt temp;
	temp.a = a + c.a;
	cout << "===========================" << endl;
	cout << "�ӷ�����ɹ�,���Ϊ��" << hex << temp.a << endl;
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
