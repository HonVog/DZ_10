#pragma once

/// <summary>
/// class date 
/// </summary>
/// <param name="day"></param>
/// <param name="month"></param>
/// <param name="year"></param>
class Date
{
	unsigned int day;
	unsigned int month;
	unsigned int year;
public:
	// array by month
	const int dataArr[12]{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; 

	// designer
	Date(unsigned int day, unsigned int manth, unsigned int year) {	Date::equalization( day,manth, year); }
	Date(unsigned int manth, unsigned int year) : Date(1, manth, year) {};
	Date(unsigned int year) : Date(1, 1, year) {};
	Date(const Date& dt) : Date(dt.day, dt.month, dt.year) {}
	Date() : Date(1, 1, 1) {};

	

	const Date& operator ()(int i) {												//()																	     
		Date::equalization(day + i, month, year);
		return *this;
	};									 
	const Date& operator +(int i){													// + int 
		Date::equalization(day + i, month, year);
		return *this;
	};

	const Date& operator +=(int i) {												// += int																		
		Date::equalization(day + i, month, year);
		return *this;
	};									 
																									
	const Date& operator +(const Date& dt){											// + Date
		Date::equalization(day + (Date::countinDays()+ dt.countinDays()), 1, 1); 
		return *this;
	};		

	const Date& operator +=(const Date& dt){										// += Date
		Date::equalization(day + (Date::countinDays() + dt.countinDays()), 1, 1); 
		return *this;
	};

	const Date& operator ++(){														// ++ Date
		Date::equalization(++day, month, year);
		return *this;
	};

	const Date& operator ++(int) {													// Date ++
		Date::equalization(++day, month, year);
		return *this;
	};
																											
	const Date& operator -(int i) {												    // - int
		int sum = Date::countinDays() - i;
		if (sum >= 0) {
			Date::equalization(1, 1, 1);
			return *this;
		}
		else {
			Date::equalization(sum, 1, 1);
			return *this;
		}
	};
																				
	const Date& operator -=(int i) {											   // -= int
		int sum = Date::countinDays() - i;
		if (sum >= 0) {
			Date::equalization(1, 1, 1);
			return *this;
		}
		else {
			Date::equalization(sum, 1, 1);
			return *this;
		}
	};
																					
	const Date& operator -(const Date& dt) {									  // - Date
		int sum = Date::countinDays() - dt.countinDays();
		if (sum >= 0) {
			Date::equalization(1, 1, 1);
			return *this;
		}
		else {
			Date::equalization(sum, 1, 1);
			return *this;
		}
	};
																				 // -=Date
	const Date& operator -=(const Date& dt) {
		int sum = Date::countinDays() - dt.countinDays();
		if (sum >= 0) {
			Date::equalization(1, 1, 1);
			return *this;
		}
		else {
			Date::equalization(sum, 1, 1);
			return *this;
		}
	};

	bool operator ==(const Date& dt){ return (day == dt.day && month == dt.month&& year == dt.year); } // ==
	bool operator !=(const Date& dt){ return (day != dt.day && month != dt.month&& year != dt.year); } // !=
	bool operator >(const Date& dt){ return (day > dt.day && month > dt.month&& year > dt.year); }	  // >
	bool operator >=(const Date& dt){ return (day >= dt.day && month >= dt.month&& year >= dt.year); } // >=
	bool operator <(const Date& dt){ return (day < dt.day && month < dt.month&& year < dt.year); }	  // <
	bool operator <=(const Date& dt){ return (day <= dt.day&& month <= dt.month&& year <= dt.year); }  // <=

	Date operator =(const Date& dt); // =

private:
	void equalization(unsigned int day, unsigned int manth, unsigned int year);	
	unsigned int countinDays() const;

	~Date() {};
};
