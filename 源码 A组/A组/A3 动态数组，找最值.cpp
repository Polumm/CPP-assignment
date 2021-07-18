#include<iostream>
using namespace std;

int main()
{
	int m,*p,min,max;
	cout << "请输入排序元素的个数：";
	cin >> m;
	p = new int[m];
	cout << "请依次输入数组元素：" << endl;
	for (int i = 0; i < m; i++)
		cin >> p[i];
	min = max = p[0];
	for (int i = 0; i < m; i++)
	{
		if (p[i] > max)	max = p[i];
		if (p[i] < min) min = p[i];
	}
	delete[]p;
	p = NULL;
	cout << "最大数为：" << max << endl;
	cout << "最小数为：" << min << endl;

}