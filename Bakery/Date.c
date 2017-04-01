#include "Date.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
Date* createDate(int day, int month, int year) {
	Date* _date = (Date*)malloc(sizeof(Date));
	_date->_day = day;
	_date->_month = month;
	_date->_year = year;
	return _date;
}

void destroyDate(Date* d) {
	free(d);
}

Date* copyDate(Date* d) {
	if (d == NULL) {
		return NULL;
	}
	Date* newDate = createDate(getDay(d), getMonth(d), getYear(d));
	return newDate;

}
int getDay(Date* d) {
	return d->_day;
}
int getMonth(Date* d) {
	return d->_month;
}
int getYear(Date* d) {
	return d->_year;
}

void toStringDate(Date* date, char str[]) {
	sprintf(str, "%d/%d/%d ", (*date)._day, (*date)._month, (*date)._year);
}

bool isExpired(Date* d1, Date* d2) {
	if (d1->_year > d2->_year) {
		return true;
	}
	else {
		if (d1->_month > d2->_month && d1->_year == d2->_year) {
			return true;
		}
		else {
			if (d1->_day > d2->_day && d1->_month == d2->_month && d1->_year == d2->_year) {
				return true;
			}
		}
	}
	return false;
}

void testDate() {
	Date* _date = createDate(20,4,1994);
	Date* _date2 = createDate(21, 4, 1994);
	bool _check = isExpired(_date2, _date);
	Date* _date3 = createDate(21, 25, 5415);
	printf("%d\n", _check);
	_check = isExpired(_date, _date2);
	printf("%d\n", _check);
	char str[250];
	toStringDate(_date, str);
	printf("%s\n", str);
	toStringDate(_date2, str);
	printf("%s\n", str);
	system("pause");
}