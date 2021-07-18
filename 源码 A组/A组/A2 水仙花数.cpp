#include<iostream>
using namespace std;
int main()
{
	int a, b, c;
	cout << "三位水仙花数有：";
	for (int i = 100; i < 1000; i++)
	{
		a = i / 100;	//求百位
		b = i / 10 % 10;	//求十位
		c = i % 10;	//求个位
		if (a * a * a + b * b * b + c * c * c == i)         
			cout << i << '\t';
	}
	return 0;
}