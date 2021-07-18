#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int k,n,sum,mul;
	for (n = k = 10; n < 100; n++,k++)
	{
		mul = (n/10) * (n % 10); //整除取十位，求余取个位
		sum = (n/10) + (n % 10); 
		if (mul > sum)
			cout << setw(3) << n;
		if (k % 5 == 0)
			cout << setw(3) << " " << endl;//不输出的地方占位，美观效果
	}
}
