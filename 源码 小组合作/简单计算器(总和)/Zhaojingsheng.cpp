#include"Zhaojingsheng.h"
#include"Songchujia.h"

void menu()//打印菜单函数
{
    system("cls");
    cout << "**********************************" << endl;
    cout << "**********欢迎使用计算器**********" << endl;
    cout << "******                      ******" << endl;
    cout << "******   1   基本四则运算   ******" << endl;
    cout << "******   2   超位整数相加   ******" << endl;
    cout << "******   3   十六进制加法   ******" << endl;
    cout << "******   4   复数加法运算   ******" << endl;
    cout << "******   5   日期减法运算   ******" << endl;
    cout << "******   6   矩阵加法运算   ******" << endl;
    cout << "******   7   集合加法运算   ******" << endl;
    cout << "******   8   矩阵求逆运算   ******" << endl;
    cout << "******   9   矩阵乘法运算   ******" << endl;
    cout << "******   0    退出计算器    ******" << endl;
    cout << "******                      ******" << endl;
    cout << "**********************************" << endl;
    cout << "请根据提示选择您需要的功能！" << endl;
}

//运行函数
void running()
{
    int p;
    while (true)//使用循环体便于多次运算操作
    {
        //调用菜单功能
        menu();
        cin >> p;//功能选择开关
        switch (p)
        {
        case 1:
            func1();//调用基本四则运算函数
            break;
        case 2:
            func2();//调用超数相加函数
            break;
        case 3:
            func3();//调用十六进制加法函数
            break;
        case 4:
            func4();//调用复数加法运算函数
            break;
        case 5:
            func5();//调用日期减法运算函数
            break;
        case 6:
            func6();//调用矩阵相加运算函数
            break;
        case 7:
            func7();//调用集合相加运算函数
            break;
        case 8:
            func8();//调用矩阵求逆运算函数
            break;
        case 9:
            func9();//调用矩阵乘法运算函数
            break;
        default:
        {
            system("cls");//清屏
            cout << "您已退出，欢迎下次使用计算器！" << endl;
            system("pause");
            return;//退出
        }
        break;
        }
    }
}

void func1()//基本数据类型的加减乘除
{
    system("cls");//清屏
    double a, c;
    char b;
    cout << "请输入一个完整的表达式： " << endl;
    cin >> a >> b >> c;
    switch (b)//通过输入的运算符号判断运算 用switch开关语句
    {
        case '+':
        {
            cout << a << "+" << c << "=" << a + c<<endl;
            break;
        }
        case '-':
        {
            cout << a << "-" << c << "=" << a - c<<endl;
            break;
        }
        case '*':
        {
            cout << a << "×" << c << "=" << a * c << endl;
            break;
        }
        case '/':
        {
            if (!c)cout << "除数不能为0 ！" << endl;
            else cout << a << "÷" << c << "=" << a / c << endl;
            break;
        }
    }
    system("pause");
}



void func6()//两个矩阵相加，矩阵的大小和内容通过键盘输入
{
    system("cls");//清屏
    int m, n;
    cout << "请依次输入矩阵的行数和列数：" << endl;
    cin >> m >> n;
    cout << "请对第一个矩阵进行赋值：" << endl;
    double** A = generateMatrix(m, n);//调用矩阵赋值函数
    cout << "请对第二个矩阵进行赋值：" << endl;
    double** B = generateMatrix(m, n);//调用矩阵赋值函数
    cout << "生成的矩阵A为：" << endl;
    showMatrix(A, m, n);
    cout << "生成的矩阵B为：" << endl;
    showMatrix(B, m, n);
    cout << "矩阵A和矩阵B相加的结果为：" << endl;
    double** C = sumMatrix(A, B, m, n);
    showMatrix(C, m, n);
    delete[] A, B, C;
    system("pause");
}

void func8()//矩阵求逆（矩阵为方阵）
{
    system("cls");//清屏

    //1、给定一个n阶矩阵
    int  n;
    cout << "请输入矩阵的阶数：" << endl;
    cin >> n;
    cout << "请对矩阵进行赋值：" << endl;
    double** A = generateMatrix(n,n);//调用矩阵赋值函数
    cout << "生成的矩阵A为：" << endl;
    showMatrix(A, n,n);//打印给定的矩阵A

    //2、求给定矩阵A的行列式的值|A|，用num存放,如果|A|=0则提示给定的矩阵的逆不存在并退出
    double num =numMatrix(A, n);
    if (!num)
    {
        cout << "矩阵的逆不存在！" << endl;
        system("pause");
        return;
    }
    //3、求给定矩阵的伴随矩阵A*并返回
    double** B= getMatrix(A, n);
    //4、求给定矩阵的逆矩阵
    double** C= inverseMatrix(num, n, B);
    //5、输出矩阵的逆矩阵A
    cout << "矩阵A的逆为： " << endl;
    showMatrix(C,n,n);
    //6、释放内存空间
    delete[] A,B,C;
    system("pause");
}

void func9()//矩阵乘法
{
    system("cls");//清屏
    int m, k, n; 
    cout << "请依次输入 m,k,n 的值" << endl;
    cin >> m >> k >> n; 
    if (m > 0 && k > 0 && n > 0) 
    {
        cout << "请输入矩阵A" << endl;
        double** A = generateMatrix(m, k); //生成矩阵A
        cout << "请输入矩阵B" << endl;
        double** B = generateMatrix(k, n); //生成矩阵B
        double** C = multiplicationMatrix(A, B, m, n, k); //矩阵A和B相乘生成矩阵C
        cout << "矩阵 A 为：" << endl;
        showMatrix(A, m, k);//打印矩阵A
        cout << "矩阵 B 为：" << endl; 
        showMatrix(B, k, n);//打印矩阵B
        cout << "矩阵 A 和 B 相乘得到的矩阵 C 为：" << endl; 
        showMatrix(C, m, n);//打印矩阵C
        //释放内存空间
        delete[] A,B, C;
    }
    else { cout << "输入有误，请退出重新输入" << endl; }
    system("pause");
}

// 定义生成矩阵的函数，传入矩阵的行数和列数，返回矩阵 
double** generateMatrix(int row, int col)
{
    double** max = new double* [row]();
    for (int i = 0; i < row; i++)
    {
        max[i] = new double[col]();
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)

        {
            cout << "请输入矩阵中第" << i + 1 << "行第" << j + 1 << "列的值：" << endl;
            cin >> max[i][j];
        }
    }
    system("cls");
    return max;
}

//定义矩阵加法函数，返回相加后的矩阵 
double** sumMatrix(double** A, double** B, int row, int col)
{
    double** C = new double* [row]();
    for (int i = 0; i < row; i++)
    {
        C[i] = new double[col]();
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}
//定义打印矩阵的函数
void showMatrix(double** matrix, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            //floor()对元素进行向下取整，相减后判断矩阵中的元素是否为整数（大于精度）
            if ((matrix[i][j] - floor(matrix[i][j])) > 0.000001)
            {
                //不是整数保留小数点后两位
                cout << setw(6) << setiosflags(ios::fixed) << setprecision(2) << matrix[i][j];
            }
            //是整数输出整数
            else  cout << setw(6) << setiosflags(ios::fixed) << setprecision(0) << matrix[i][j];
        }
        cout << endl;
    }
}

//返回给定矩阵的行列式的值
double numMatrix(double** A, int n)
{
    if (n == 1)
        return A[0][0];
    double num = 0;
    //用temp存放A按第一个元素展开的n-1阶行列式
    double** temp = new double* [n]();
    for (int i = 0; i < n; i++)
    {
        temp[i] = new double[n]();
    }
    //按第一行展开
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            for (k = 0; k < n - 1; k++)
            {
                //确保划去第一行第k列
                temp[j][k] = A[j + 1][(k >= i) ? k + 1 : k];
            }
        }
        double t = numMatrix(temp, n - 1);
        //行标和列标的和为偶数时该项符号为正，为奇数时为负
        if (i % 2 == 0)
        {
            num += A[0][i] * t;
        }
        else
        {
            num -= A[0][i] * t;
        }
    }
    return num;
}

//计算每一行每一列的每个元素所对应的余子式，组成A*
double** getMatrix(double** A, int n)
{
    //所求给定矩阵的伴随矩阵
    double** B = new double* [n]();
    for (int i = 0; i < n; i++)
    {
        B[i] = new double[n]();
    }
    if (n == 1)
    {
        B[0][0] = A[0][0];
        return B;
    }
    int i, j, k, t;
    double** temp = new double* [n]();
    for (int i = 0; i < n; i++)
    {
        temp[i] = new double[n]();
    }
    //确保划掉第i行第j列元素
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            for (k = 0; k < n - 1; k++)
            {
                for (t = 0; t < n - 1; t++)
                {
                    temp[k][t] = A[k >= i ? k + 1 : k][t >= j ? t + 1 : t];
                }
            }
            //将行列坐标互换，实现矩阵的转置
            B[j][i] = numMatrix(temp, n - 1);

            if ((i + j) % 2 == 1)
            {
                B[j][i] = -B[j][i];
            }
        }
    }
    return B;
}
//定义矩阵求逆的函数
double** inverseMatrix(double num, int n, double** B)
{
    double** ans = new double* [n]();
    for (int i = 0; i < n; i++)
    {
        ans[i] = new double[n]();
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans[i][j] = B[i][j] / num;
        }
    }
    return ans;
}

//定义矩阵乘法函数
double** multiplicationMatrix(double** A, double** B, int row, int col, int k)
{
    double** C =  new double* [row](); 
    for (int i = 0; i < row; i++) 
    { 
        C[i] = new double[col](); 
    }
    for (int i = 0; i < row; i++) 
    { 
        for (int j = 0; j < col; j++)
        { 
            for (int m = 0; m < k; m++) 
            { 
                C[i][j] += A[i][m] * B[m][j]; 
            }
        }
    }
    return C;
}