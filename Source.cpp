#include<iostream>
#include<stdexcept>
using namespace std;
class error {
private:
	int month, day;
public:
	error(int M , int D){
		this->month = M;
		this->day = D;
	}
	void get_month() {
		switch (month)
		{
		case(1):cout << "January ";
			break;
		case(2):cout << "February ";
			break;
		case(3):cout << "March ";
			break;
		case(4):cout << "April ";
			break;
		case(5):cout << "May ";
			break;
		case(6):cout << "june ";
			break;
		case(7):cout << "July ";
			break;
		case(8):cout << "August ";
			break;
		case(9):cout << "September ";
			break;
		case(10):cout << "October ";
			break;
		case(11):cout << "November ";
			break;
		case(12):cout << "December ";
			break;
		default:
			throw MonthError();
			break;
		}
	}
	void get_day() {
		
			if(month==2&&day>29){
				throw DayError();
			}
			else if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31) {
				throw DayError();
			}
			else if ((month == 4 || month == 6 || month == 9 || month == 11 ) && day >30) {
				throw DayError();
			}
			else {
				cout << day;
			}
		
	}
	class DayError {};
	class MonthError {};
};
int main() {
	int m, d;
	try {
		cout << "please,Enter the date: " << endl;
		cin >> m >> d;
		error a(m, d);
		a.get_month();
		a.get_day();
	}
	catch (error::MonthError) {
		cout << "A wrong Month";
	}
	catch (error::DayError) {
		cout << "A wrong Day";
	}

	return 0;
}