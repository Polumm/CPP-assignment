#include <iostream>
using namespace std;
int main()
{
	int a, b, c;
	cout << "��ʮ���������ļӷ�" << endl;
	cout << "=======================" << endl;
	cout << "����������ʮ����������" << endl;
	cin >> hex >> a >> hex >> b;
	c = a + b;
	cout << "�˽��ƽ����" << oct << c << endl;
	cout << "ʮ���ƽ����" << dec << c << endl;
	cout << "ʮ�����ƽ����" << hex << c << endl;
}
