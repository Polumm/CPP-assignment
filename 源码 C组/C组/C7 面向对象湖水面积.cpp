#include<iostream>
#include <time.h>  
#include<iomanip>
using namespace std;
class Lake 
{
private:
	int length, width, ** lake;//长度、宽度、二级指针用于湖水矩阵的生成和访问
	double	size = 0, depth = 0, per; //总面积、总深度、单位面积
public:
	Lake();//构造函数，设置湖水基本参数
	void show();//计算面积、深度并格式化打印
};

Lake::Lake()
{
	srand((unsigned)time(NULL));//生成随机数种子
	int i, j;//循环变量
	cout << "请输入湖水长度：";
	cin >> length;
	cout << "请输入湖水宽度：";
	cin >> width;
	cout << "请输入单位面积：";
	cin >> per;

	lake = new int* [length];//生成动态指针数组
	for (i = 0; i <length; i++)	lake[i] = new int[width];//用指针数组生成动态二维数组

	for (i = 0; i < length; i++)
		for (j = 0; j < width; j++)
			lake[i][j] = 0;//水深先全部归零

	for (int i = 1; i < length - 1; i++)
		for (int j = 1; j < width - 1; j++)
			lake[i][j] = (rand() % 9);//生成水深，可能出现0

	for (int i = 1; i < length - 1; i++)
		for (int j = 1; j < width - 1; j++)
			if (lake[i][j] == 0 && lake[i - 1][j] != 0 && lake[i + 1][j] != 0 && lake[i][j - 1] != 0 && lake[i][j + 1] != 0)
				lake[i][j] = (rand() % 9) + 1;//消除中间突兀地出现一个深度为0的方格的情况

}
void Lake::show()
{
	int sum = 0;//sum为方格数
	cout << "湖水深度矩阵为：" << endl;
	for (int i = 0; i < length; i++)//格式化输出
	{
		for (int j = 0; j < width; j++)
		{
			if (lake[i][j] == 0)
				cout << "■";//打印岸边
			else
			{
				cout << setw(2) << lake[i][j];//计算湖面积得排除湖岸的陆地部分				
				sum += 1;//累加水面方格数
				depth += lake[i][j];
			}
		}
		cout << endl;
	}
	size = sum * per;	//湖水总面级等于方格数乘以单位面积
	depth /= sum;	//平均深度等于总深度按方格数的平均
	cout << "湖面积为：" << size << "平方米" << endl;
	cout << "平均水深：" << depth << "米" << endl;
}

int main()
{
	Lake lake1;
	lake1.show();
}

