#include <iostream>
using namespace std;

class complex
{
private:
	double real, image;//ʵ�����鲿
public:
	complex(double real = 0.0, double image = 0.0);//Ĭ�Ϲ���
	void set();//���û�������ʵ�ֳ�ʼ��
	void show();
	complex operator +(complex c);//�������� operator����� (�β��б�)

};

complex::complex(double i , double j)
{
	real = i;
	image = j;
}

void complex::set()
{
	cout << "������ʵ����" << endl;
	cin >> real;
	cout << "�������鲿��" << endl;
	cin >> image;
	cout << "���븴����" << real << 'i' <<" + " << image << 'j' << " �ɹ���" << endl;
}

void complex::show()
{
	cout << "�ø���Ϊ��" << real << 'i' << " + " << image << 'j' << endl;
}

complex complex::operator + (complex c)
{
	complex temp;
	temp.real = real + c.real;
	temp.image = image + c.image;
	cout << "�������Ӻͳɹ���" << endl;
	return temp;
}
int main()
{
	complex c1, c2, c3;
	c1.set();
	c2.set();
	c3 = c1 + c2;
	c3.show();
}
