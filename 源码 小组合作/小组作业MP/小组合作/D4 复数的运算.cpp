#include <iostream>
using namespace std;

class complex
{
private:
	double real, image;//实部和虚部
public:
	complex(double real = 0.0, double image = 0.0);//默认构造
	void set();//与用户交互，实现初始化
	void show();
	complex operator +(complex c);//返回类型 operator运算符 (形参列表)

};

complex::complex(double i , double j)
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
	cout << "输入复数：" << real << 'i' <<" + " << image << 'j' << " 成功！" << endl;
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
int main()
{
	complex c1, c2, c3;
	c1.set();
	c2.set();
	c3 = c1 + c2;
	c3.show();
}
