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
	int operator- (Date c);	//日期作差的运算符重载
};
int Date::monthDays[12][2] = 
{{31,31},{28,29},{31,31},{30,30},{31,31},
{30,30},{31,31},{31,31},{30,30},{31,31},{30,30},
{31,31}};
void Date::set()
{
	cout << "请输入年份：" << endl;
	cin >> year ;
	cout << "请输入月份：" << endl;
	cin >> month;
	cout << "请输入日号：" << endl;
	cin >> day;
	cout << "=========================" << endl;
}
int Date::operator-(Date c)	
{
	int number = 0;
	if (year > c.year || month > c.month || day > c.day) //确保被减日期为大的日期
	{
		swap(year, c.year);
		swap(month, c.month);
		swap(day, c.day);
	}
	while (year < c.year || month < c.month || day < c.day) {
		day++;
		//加一天后，相应的月，年可能会发生变化
		if (day == monthDays[month-1][isLeap(year)] + 1) {
			month++;//当前号超过当前月最高天数：月份加1，号变成下月的1号
			day = 1;
		}
		if (month == 13) {
			year++;//到达一年的最后一天 ：年份加1,月份变成下年的1月
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
	cout << "两日期间相差：" << c << "天" << endl;
	cout << "=========================" << endl;
}