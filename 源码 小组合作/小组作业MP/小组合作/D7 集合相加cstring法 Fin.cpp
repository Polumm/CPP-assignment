#include <iostream>
#include <cstring>
using namespace std;
bool compare(string a[], int n, string x)//����Ԫ�ؽ��бȽϣ���ȷ���0
{
	for (int i = 0; i < n; i++)
		if (a[i] == x) return 0;
	return 1;
}
class Set
{
private:
	int n;//����Ԫ�ظ���
	string *p = NULL;//�������ϵ�ָ��
public:
	Set() { ; } //Ĭ�Ϲ��죬��֤���̵�������
	Set(int m);  
	void set();	//��ֵ����	
	void show();
	Set operator +(Set c);	//�Ӻŵ�����
};

void Set::set()//���û������ķ�ʽʵ�ֳ�ʼ��
{
	cout << "�����뼯��A��Ԫ�ظ�����";
	cin >> n;
	cout << "�����뼯��Ԫ�أ�" << endl;
	p = new string[n];//��̬���뼯��
	for (int i = 0; i < n; i++)//�û�����Ԫ��
	{
		cin >> p[i];
	}
	cout << "���ϴ����ɹ���" << endl;
}

Set::Set(int m)//��֪Ԫ�ظ�������������
{
	n = m;
	p = new string[m];
}

void Set::show()
{
	cout << "�ü���Ϊ��" << endl;
	for (int i = 0; i < n; i++)
		cout << p[i] << '\t';
}

Set Set::operator + (Set c)
{
	int m = n + c.n;
	int same = 0;

	for (int i = 0; i < n; i++)//��ȷ���������ظ�Ԫ�صĸ���
	{
		for (int j = 0; j < c.n; j++)
		{
			if (c.p[j] == p[i])
				same++;//�ظ�Ԫ�ظ���
		}
		
	}
	Set temp(m-same);//���ظ�Ԫ�صĸ�����Ϊ�¼���Ԫ�صĸ���
	int i = 0;
	int j = 0;
	for (; i < (m-same); i++,j++)
	{
		if (i < n)
		{
			temp.p[i] = p[i];//���е�Ԫ��ֱ�ӷ���
		}
		else
		{
			if (compare(p, n, c.p[j - n]))//�ظ���Ԫ�����¼�����ֻ��һ��
				temp.p[i] = c.p[j - n];
			else i--;
		}
	}
	cout << "�����ϼӺͳɹ���" << endl;
	return temp;
}

int main()
{
	Set a, b, c;
	a.set();
	cout << "=========================" << endl;
	b.set();
	cout << "=========================" << endl;
	c = a + b;
	c.show();
	cout << endl;
}