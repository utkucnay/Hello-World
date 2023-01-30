#pragma once

struct DateTime
{
	DateTime(__int8 day, __int8 month, __int8 year) : _day(day), _month(month), _year(year) {}
	DateTime() = default;

	__int8		_day;
	__int8		_month;
	__int8		_year;
};