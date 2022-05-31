#include "Main.h"

int date_check(User* user_check)
{
	tm user_date = user_check->date;
	
	time_t t = time(0);
	tm now;
	localtime_s(&now, &t);

	if (user_date.tm_year > (now.tm_year + 1900))
	{
		return 1;
	}
	else if (user_date.tm_year == (now.tm_year + 1900))
	{
		if (user_date.tm_mon > (now.tm_mon + 1))
		{
			return 1;
		}
		else if (user_date.tm_mon == (now.tm_mon + 1))
		{
			if (user_date.tm_mday > now.tm_mday)
			{
				return 1;
			}
			else if (user_date.tm_mday == now.tm_mday)
			{
				if (user_date.tm_hour > now.tm_hour)
				{
					return 1;
				}
				else if (user_date.tm_hour == now.tm_hour)
				{
					if (user_date.tm_min > now.tm_min)
					{
						return 1;
					}
					else if (user_date.tm_min == now.tm_min)
					{
						if (user_date.tm_sec > now.tm_sec)
						{
							return 1;
						}
					}
				}
			}
		}
	}
	return 0;
}

/*
	if (
		(user_date.tm_year >= (now.tm_year + 1900)) &&
		(user_date.tm_mon >= (now.tm_mon + 1)) &&
		(user_date.tm_mday >= now.tm_mday) &&
		(user_date.tm_hour >= now.tm_hour) &&
		(user_date.tm_min >= now.tm_min) &&
		(user_date.tm_sec > now.tm_sec)
		)
	{
		return 1;
	}
	return 0;
*/