/*
	Rachel A Schifano
	IT 279
	Assignment 7
*/
#ifndef _DATE_
#define _DATE_

class Date {

	public:
		friend class HashTable;

		// Constructor
		Date(int _day, int _month, int _year) {
			this->day = _day;
			this->month = _month;
			this->year = _year;
		}

		// Destructor
		~Date() {}

	private:
		int day;
		int month;
		int year;
};

#endif
