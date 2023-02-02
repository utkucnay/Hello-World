#pragma once

struct DateTime
{
	DateTime(int day, int month, int year) : _day(day), _month(month), _year(year) {}
	DateTime() = default;

	int		_day;
	int		_month;
	int		_year;
};