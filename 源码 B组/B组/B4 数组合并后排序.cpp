#include <iostream>
using namespace std;
int main()
{
	int A[] = { 123,88,86,86,33,15,7,0,-1,-3};
	int B[] = { 86,69,51,50,27,19,15,12,5,2};

	int lenA, lenB;//A、B的数组长度
	int i = 0, j = 0, k = 0;//循环需要的变量
	int	*C;//这里拓展了一下，动态申请数组，AB数组个数不限
	lenA = sizeof(A) / sizeof(A[0]);
	lenB = sizeof(B) / sizeof(B[0]);//总长除以单位长可得个数
	C = new int[lenA+lenB];

	while (i <= lenA && j <= lenB)//最多循环至A、B数组的共有长度，避免了数组越界的问题
	{
		if (A[i] >= B[j])//先比较再放入新数组
		{
			C[k] = A[i];
			i++;
		}
		else 
		{ 
			C[k] = B[j];
			j++;
		}
		k++;
	}
	while(i <= lenA)//剩下没有比较的部分可以直接放入
	{
		C[k] = A[i];
		i++;
	}
	while (j <= lenB)
	{
		C[k] = B[j];
		j++;
	}
	for (i = 0; i < lenA+lenB; i++)
		cout << C[i] << endl;
	return 0;
}
