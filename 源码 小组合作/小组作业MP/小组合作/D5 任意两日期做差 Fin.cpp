#include <iostream>
using namespace std;
bool isLeap(int year) 
{
	return (year % 4 == 0) || (year % 100 == 0 && year % 400 == 0);
}
class Date
{
private:
	int date, year, month, day;
	static int monthDays[12][2];
public:
	void set();
	int operator- (Date c);	//������������������
};
int Date::monthDays[12][2] = 
{{31,31},{28,29},{31,31},{30,30},{31,31},
{30,30},{31,31},{31,31},{30,30},{31,31},{30,30},
{31,31}};
void Date::set()
{
	cout << "��������ݣ�" << endl;
	cin >> year ;
	cout << "�������·ݣ�" << endl;
	cin >> month;
	cout << "�������պţ�" << endl;
	cin >> day;
	cout << "=========================" << endl;
}
int Date::operator-(Date c)	
{
	int number = 0;
	if (year > c.year || month > c.month || day > c.day) //ȷ����������Ϊ�������
	{
		swap(year, c.year);
		swap(month, c.month);
		swap(day, c.day);
	}
	while (year < c.year || month < c.month || day < c.day) {
		day++;
		//��һ�����Ӧ���£�����ܻᷢ���仯
		if (day == monthDays[month-1][isLeap(year)] + 1) {
			month++;//��ǰ�ų�����ǰ������������·ݼ�1���ű�����µ�1��
			day = 1;
		}
		if (month == 13) {
			year++;//����һ������һ�� ����ݼ�1,�·ݱ�������1��
			month = 1;
		}
		number++;
	}
	return number;
}
int main()
{
	cout << "=========================" << endl;
	Date date1, date2;
	date1.set();date2.set();
	int c = date1 - date2;
	cout << "�����ڼ���" << c << "��" << endl;
	cout << "=========================" << endl;
}