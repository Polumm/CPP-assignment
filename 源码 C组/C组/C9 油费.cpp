#include<iostream>
using namespace std;
class Oil
{
private:
	double lead;//有铅油量
	double price;//单价
	double unlead;//无铅油量
	double unprice;//单价
	double total;

public:
	Oil()	//构造函数
	{
		cout << "今日无铅汽油的单价：";
		cin >> unprice;
		cout << "今日有铅汽油的单价：";
		cin >> price;
		cout << "请输入无铅汽油的总量：";
		cin >> unlead;
		cout << "请输入有铅汽油的总量：";
		cin >> lead;
		total = unlead * unprice + lead * price;
	}
	void show()	{cout << "总价为:" << total << "元" << endl;}
};
int main()
{
	Oil O1;
	O1.show();
	return 0;
}

