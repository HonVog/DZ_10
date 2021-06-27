#include "Date.h"

Date Date::operator = (const Date& dt) {
	Date newDate(dt); 
	return newDate;
}


void Date::equalization(unsigned int day, unsigned int manth, unsigned int year) { // sort
	(day == 0) ? day = 1 : day;
	(manth == 0) ? manth = 1 : manth;
	(year == 0) ? year = 1 : year;
	while (day >= 365)
	{
		if (day >= 366 && year % 4 == 0) { day - 366; ++year; continue; }
		day - 365; ++year;
	}

	do
	{
		while (manth > 12) { ++year; }
		while (day > dataArr[manth]) {
			if (manth > 12) break;
			if (day == 29 && manth == 2 && (year % 4) == 0) break;
			day -= dataArr[manth];
			++manth;
		}
	} while (manth > 12);


	this->day = day;
	this->month = manth;
	this->year = year;
}

unsigned int Date::countinDays() const {
	unsigned int days{ day };
	unsigned int years { year };
	unsigned int months{ month };
	do
	{
		--months;
		(months == 0) ? months = 12 : months;
		days += dataArr[months];
	} while (months != 0);

	days = days + (366 * (years / 4)) + ((years - (years / 4)) * 365);
	return days;
}
