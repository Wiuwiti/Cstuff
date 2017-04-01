#pragma once
#include <stdbool.h>
/// <summary>
/// Data structure to store the date of a material.
/// </summary>
typedef struct {
	int _day;
	int _month;
	int _year;
}Date;
/// <summary>
/// Creates a data structure of type "Date".
/// </summary>
/// <param name="day">Type: int ; Represents the day in Date structure. </param>
/// <param name="month">Type: int ; Represents the month in Date structure. </param>
/// <param name="year">Type: int ; Represents the year in Date structure. </param>
Date* createDate(int day, int month, int year);
void destroyDate(Date* d);
Date* copyDate(Date* d);
int getDay(Date* d);
int getMonth(Date* d);
int getYear(Date* d);
void toStringDate(Date* d, char str[]);
bool isExpired(Date* d1, Date* d2);

void testDate();