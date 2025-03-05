#include<iostream>

using namespace std;

class Date {
private:
	int year;
	int month;
	int day;
public:
	Date() : year(2024), month(2), day(1) {
		show_date();
	}

	bool isLeapYear() {
		int y = this->year;
		return (y % 4 == 0 && y % 100 != 0)|| (y % 400 == 0);
	}

	void addDay(int day) {
		this->day += day;


		while (true) {
			int daysInMonth;
			bool leap = isLeapYear();
			if (month == 2) {
				daysInMonth = leap ? 29 : 28;
			}
			else if (month == 4 || month == 6 || month == 9 || month == 11) {
				daysInMonth = 30;
			}
			else {
				daysInMonth = 31;
			}

			if (this->day <= daysInMonth)break;

			this->day -= daysInMonth;
			month++;

			if (month > 12) {
				month = 1;
				year++;
			}
		}
		show_date();
	}

	void addMonth(int month) {
		this->month += month;
		year += this->month / 12;
		this->month %= 12;
		if (this->month == 0) {
			this->month = 12;
			year--;
		}
		show_date();
	}

	void addYear(int year) {
		this->year += year;
		show_date();
	}

	void show_date() {
		cout << "Today is " << year << " / " << month << " / " << day << endl;
	}
};

int main()
{
	Date date;

	date.addDay(60);
	date.addMonth(24);
	date.addYear(2);

	cout << endl;

	date.show_date();

	return 0;
}
