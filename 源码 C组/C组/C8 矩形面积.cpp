#include<iostream>
using namespace std;
class rectangle
{
private:
	double width;
	double length;
	double size;

public://类内声明，类外定义
	rectangle(double w, double l);
	double show();
	double AddArea(rectangle a);
};

rectangle::rectangle(double w, double l)//构造函数
{
	width = w;
	length = l;
	size = width * length;
}
double rectangle::show() { return size; }//获取面积
double rectangle::AddArea(rectangle a) {return (size + a.show());}//面积加和

int main()
{
	double m, n, p, q;
	cout << "请输入矩形a的长宽：" << endl;
	cin >> m >> n;
	cout << "请输入矩形b的长宽：" << endl;
	cin >> p >> q;
	cout << "======================" << endl;
	rectangle a(m,n);
	cout << "矩形a的面积为：" << a.show() << endl;
	rectangle b(p,q);
	cout << "矩形b的面积为：" << b.show() << endl;
	cout << "a、b总面积为：" << a.AddArea(b) << endl;
	return 0;
}
