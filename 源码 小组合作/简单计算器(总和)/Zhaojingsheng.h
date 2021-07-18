#include<iostream>
#include<ctime>
#include<iomanip>
#include<cmath>
using namespace std;

//函数声明
//1 功能函数模块
	//1.0.1 打印菜单函数（赵经生）
	void menu();
	//1.0.2 运行函数 (赵经生）
	void running();
	//1.1 功能函数1：基本数据类型的加减乘除  （赵经生）
	void func1();
	//1.2 功能函数2：可能超出整数表示范围的两个整数相加  （宋楚嘉）
	void func2();
	//1.3 功能函数3：两个十六进制数相加  （宋楚嘉）
	void func3();
	//1.4 功能函数4：两个复数相加 （宋楚嘉）
	void func4();
	//1.5 功能函数5：两个日期数据相减 （宋楚嘉）
	void func5();
	//1.6 功能函数6：两个矩阵相加  （赵经生）
	void func6();
	//1.7 功能函数7：两个集合相加（其中没有重复数据） （宋楚嘉）
	void func7();
	//1.8 功能函数8：矩阵求逆 （赵经生）
	void func8();
	//1.9 功能函数9：矩阵乘法 （赵经生）
	void func9();

//2 子函数模块
	//2.1 生成矩阵的函数 （赵经生）
	double** generateMatrix(int row, int col);
	//2.2 矩阵相加运算的函数 （赵经生）
	double** sumMatrix(double** A, double** B, int row, int col);
	//2.3 打印矩阵的函数 （赵经生）
	void showMatrix(double** A, int row, int col);
	//2.4 求逆矩阵函数 （赵经生）
	double** inverseMatrix(double num, int n,double** B);
	//2.5 求矩阵的行列式的值的函数 （赵经生）
	double numMatrix(double** A, int n);
	//2.6 求矩阵每一行每一列的每个元素所对应的余子式，组成伴随矩阵A*  （赵经生）
	double**  getMatrix(double** A, int n);
	//2.7 求两个矩阵的乘积矩阵 （赵经生）
	double** multiplicationMatrix(double** A, double** B, int row, int col, int k);