	#include<iostream>
using namespace std;
class Student
{
public: int id, english, computer, total;
	  void getscore()
	  {
		  cout << "输入学号："; cin >> id;
		  cout << "输入英语成绩： "; cin >> english;
		  cout << "输入计算机成绩："; cin >> computer;
		  cout << "=========================================" << endl;
		  total = english + computer;
	  }
	  void show()
	  {
		  cout << "学号" << id << " 英语=" << english << " 计算机=" << computer << " 总分=" << total << endl << endl;
	  }
};
int main()
{
	int n, i, j;
	Student** p;//输入学生人数待定，指针数组需要动态申请
	Student* temp;//Student类要动态申请
	cout << "请输入需要排序的学生人数：";
	cin >> n;
	cout << "=========================================" << endl;
	p = new Student * [n];//动态创建指针数组，数组元素为类的指针

	for (j = 0; j < n; j++)
	{
		p[j] = new Student;

		cout << "学生 " << j + 1 << endl;
		p[j]->getscore();//用指针调用成员函数进行初始化
	}

	for (j = 0; j < n - 1; j++)//冒泡排序
		for (i = j + 1; i < n; i++)
			if (p[i]->total > p[j]->total)//用指针取数据成员
			{
				temp = p[j]; p[j] = p[i]; p[i] = temp;//交换指针实现排序，后续需要用指针进行输出
			}
	cout << "排序结果如下：" << endl;
	for (i = 0; i < n; i++)
		p[i]->show();
}