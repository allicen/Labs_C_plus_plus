#ifndef DATETIME_H
#define DATETIME_H


struct date {
	public:
		date(int d, int m, int y) {
			day = d;
			month = m;
			year = y;
		}
		
		bool set(int d, int m, int y) {
			bool correctData = true;
		
			if (m < 1 || m > 12) {
				return !correctData;
			}
			
			if (d < 1 || (m == 2 && d > 28) || ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) || d > 31) {
				return !correctData;
			}
			
			day = d;
			month = m;
			year = y;
			
			return correctData;
		}
		
		void print() {
			std::string dayCorrect = "", monthCorrect = "";
			
			if (day < 10) {
				dayCorrect = "0";
			}
			
			if (month < 10) {
				monthCorrect = "0";
			}
			
			std::cout << "Date: " << dayCorrect << day << "." << monthCorrect << month << "." << year << std::endl;
		}
		
		date read() {
			date d(day, month, year);
			return d;
		}
		
		bool equal(date one, date two) {
			return one.day == two.day && one.month == two.month && one.year == two.year;
		}
		
		bool less(date one, date two) {
			return one.year < two.year || one.year == two.year && one.month < two.month ||
				   one.year == two.year && one.month == two.month && one.day < two.day;
		}
		
		bool grater(date one, date two) {
			return one.year > two.year || one.year == two.year && one.month > two.month ||
				   one.year == two.year && one.month == two.month && one.day > two.day;
		}
		
	private:
		int day;
		int month;
		int year;
};

struct time {
	public:
		time(int h, int m, int s) {
			hour = h;
			minute = m;
			second = s;
		}
		
		bool set(int h, int m, int s) {
			bool correctTime = true;
			
			if (h < 0 || h > 23) {
				return !correctTime;
			}
			
			if (m < 0 || m > 59) {
				return !correctTime;
			}
			
			if (s < 0 || s > 59) {
				return !correctTime;
			}
			
			hour = h;
			minute = m;
			second = s;
			
			return correctTime;
		}
		
		void print() {
			std::string hourCorrect = "", minuteCorrect = "", secondCorrect = "";
			
			if (hour < 10) {
				hourCorrect = "0";
			}
			
			if (minute < 10) {
				minuteCorrect = "0";
			}
			
			if (second < 10) {
				secondCorrect = "0";
			}
			
			std::cout << hourCorrect << hour << ":" << minuteCorrect << minute << ":" << secondCorrect << second << std::endl;
		}
		
		time read() {
			time t(hour, minute, second);
			return t;
		}
		
		bool equal(time one, time two) {
			return one.hour == two.hour && one.minute == two.minute && one.second == two.second;
		}
		
		bool less(time one, time two) {
			return one.hour < two.hour || one.hour == two.hour && one.minute < two.minute ||
				   one.hour == two.hour && one.minute == two.minute && one.second < two.second;
		}
		
		bool grater(time one, time two) {
			return one.hour > two.hour || one.hour == two.hour && one.minute > two.minute ||
				   one.hour == two.hour && one.minute == two.minute && one.second > two.second;
		}
		
	private:
		int hour;
		int minute;
		int second;
};



#endif