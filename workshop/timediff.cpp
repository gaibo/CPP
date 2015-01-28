#include <iostream>
#include <cstring>

struct time {
	char months[10];		// typed out
	int month;
	int day;		// 1 to 30
	int year;
	int hour;		// 0 to 23, 24-hour style
	int minute;		// 0 to 59
	int second;		// 0 <= second < 60
};
struct time time1, time2;

void difference(void);

int main()
{
	std::cout << "Input more recent time first" << '\n' << "Format: month day year hour minute second" << '\n';
	std::cin >> time1.months >> time1.day >> time1.year >> time1.hour >> time1.minute >> time1.second;
	
	if (strcmp(time1.months, "January") == 0)
		time1.month = 1;
	else if (strcmp(time1.months, "February") == 0)
		time1.month = 2;
	else if (strcmp(time1.months, "March") == 0)
		time1.month = 3;
	else if (strcmp(time1.months, "April") == 0)
		time1.month = 4;
	else if (strcmp(time1.months, "May") == 0)
		time1.month = 5;
	else if (strcmp(time1.months, "June") == 0)
		time1.month = 6;
	else if (strcmp(time1.months, "July") == 0)
		time1.month = 7;
	else if (strcmp(time1.months, "August") == 0)
		time1.month = 8;
	else if (strcmp(time1.months, "September") == 0)
		time1.month = 9;
	else if (strcmp(time1.months, "October") == 0)
		time1.month = 10;
	else if (strcmp(time1.months, "November") == 0)
		time1.month = 11;
	else if (strcmp(time1.months, "December") == 0)
		time1.month = 12;
	else {
		std::cerr << "Not a month\n";
		return (1);
	}
	
	if (time1.day > 30 || time1.day <= 0) {
		std::cerr << "Model assumes thirty days in every month for now\n" << "Give a real date\n";
		return (1);
	}
	
	if (time1.year <= 0) {
		std::cerr << "Give a real year\n";
		return (1);
	}
	
	if (time1.hour > 23 || time1.hour < 0) {
		std::cerr << "Give a real hour\n";
		return (1);
	}
	
	if (time1.minute > 59 || time1.minute < 0) {
		std::cerr << "Give a real minute\n";
		return (1);
	}
	
	if (time1.second > 59 || time1.second < 0) {
		std::cerr << "Give a real hour\n";
		return (1);
	}

	std::cout << "Input second time to find difference" << '\n';
	std::cin >> time2.months >> time2.day >> time2.year >> time2.hour >> time2.minute >> time2.second;

	if (strcmp(time2.months, "January") == 0)
		time2.month = 1;
	else if (strcmp(time2.months, "February") == 0)
		time2.month = 2;
	else if (strcmp(time2.months, "March") == 0)
		time2.month = 3;
	else if (strcmp(time2.months, "April") == 0)
		time2.month = 4;
	else if (strcmp(time2.months, "May") == 0)
		time2.month = 5;
	else if (strcmp(time2.months, "June") == 0)
		time2.month = 6;
	else if (strcmp(time2.months, "July") == 0)
		time2.month = 7;
	else if (strcmp(time2.months, "August") == 0)
		time2.month = 8;
	else if (strcmp(time2.months, "September") == 0)
		time2.month = 9;
	else if (strcmp(time2.months, "October") == 0)
		time2.month = 10;
	else if (strcmp(time2.months, "November") == 0)
		time2.month = 11;
	else if (strcmp(time2.months, "December") == 0)
		time2.month = 12;
	else {
		std::cerr << "Not a month\n";
		return (1);
	}
	
	if (time2.day > 30 || time2.day <= 0) {
		std::cerr << "Model assumes thirty days in every month for now\n" << "Give a real date\n";
		return (1);
	}
	
	if (time2.year <= 0) {
		std::cerr << "Give a real year\n";
		return (1);
	}
	
	if (time2.hour > 23 || time2.hour < 0) {
		std::cerr << "Give a real hour\n";
		return (1);
	}
	
	if (time2.minute > 59 || time2.minute < 0) {
		std::cerr << "Give a real minute\n";
		return (1);
	}
	
	if (time2.second > 59 || time2.second < 0) {
		std::cerr << "Give a real hour\n";
		return (1);
	}

	difference();
	return (0);
}

void difference(void)
{
	int diffyear, diffmonth, diffday, diffhour, diffminute, diffsecond;
	
	// year difference
	diffyear = time1.year - time2.year;
	
	// month difference
	if (time1.month < time2.month) {
		diffyear -= 1;
		diffmonth = (time1.month - time2.month) + 12;
	} else
		diffmonth = time1.month - time2.month;
	
	// day difference
	if (time1.day < time2.day) {
		diffmonth -= 1;
		diffday = (time1.day - time2.day) + 30;
	} else
		diffday = time1.day - time2.day;
		
	// hour difference
	if (time1.hour < time2.hour) {
		diffday -= 1;
		diffhour = (time1.hour - time2.hour) + 24;
	} else
		diffhour = time1.hour - time2.hour;
		
	// minute difference
	if (time1.minute < time2.minute) {
		diffhour -= 1;
		diffminute = (time1.minute - time2.minute) + 60;
	} else
		diffminute = time1.minute - time2.minute;
		
	// second difference
	if (time1.second < time2.second) {
		diffminute -= 1;
		diffsecond = (time1.second - time2.second) + 60;
	} else
		diffsecond = time1.second - time2.second;
		
	// remove negatives if found
	if (diffsecond < 0) {
		diffminute -= 1;
		diffsecond += 60;
	} if (diffminute < 0) {
		diffhour -= 1;
		diffminute += 60;
	} if (diffhour < 0) {
		diffday -= 1;
		diffhour += 12;
	} if (diffday < 0) {
		diffmonth -= 1;
		diffday += 30;
	} if (diffmonth < 0) {
		diffyear -= 1;
		diffmonth += 12;
	} if (diffyear < 0)
		std::cerr << "Did not follow instructions\n";
	
	std::cout << "Difference is " << diffyear << " years " << diffmonth << " months " << diffday << " days " << diffhour << " hours " << diffminute << " minutes " << diffsecond << " seconds" << '\n';
}
