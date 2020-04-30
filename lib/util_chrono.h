#ifndef UTIL_CHRONO_DURATION_H
#define UTIL_CHRONO_DURATION_H

#include <ratio>
#include <chrono>
#include <iostream>
#include <string>
#include <ctime>

template <typename V, typename R>
std::ostream& operator<<(std::ostream&os, const std::chrono::duration<V,R>& d)
{
   os << "[ " << d.count() << " of " << R::num << "/" <<R::den << " ]";
   return os;	
}

template <typename C>
void printClockProperty()
{
	std::cout<< "- precision: ";
	// if time unit is less or equal one millisecond
	typedef typename C::period P;
	if(std::ratio_less_equal<P, std::milli>::value)
	{
		// convert to milliseconds
		typedef typename std::ratio_multiply<P, std::kilo>::type TT;  // time base unit is second, P is precision is 1/1000000000 s, so multiply ,convert to millisecond
		std::cout << std::fixed << double(TT::num)/TT::den << " milliseconds" << std::endl;
	}
	else
	{
		std::cout << std::fixed << double(P::num)/P::den << " seconds" << std::endl; 
	}
	std::cout<< "- is_steady: " << std::boolalpha << C::is_steady << std::endl;
	
}

template <typename T>
std::string timepoint2String(const T& tp, bool use_UTC = false)
{
	// convert to system time
	std::chrono::system_clock::time_point st = std::chrono::system_clock::time_point(tp.time_since_epoch());
	std::time_t t = std::chrono::system_clock::to_time_t(st);
	std::string ts;
	if(use_UTC)
	{

		// without timezone
		ts = std::asctime(std::gmtime(&t));
	}
	else
	{
		// with timezone
		ts = std::ctime(&t);
	}
	ts.resize(ts.size() - 1);
	return ts;
}

template <typename C = std::chrono::system_clock>
std::chrono::time_point<C> makeTimePoint(int year, int mon ,int day, int hour, int min, int sec = 0)
{
	struct std::tm t;
	t.tm_sec = sec; // second of minute (0 .. 59 and 60 for leap seconds)
	t.tm_min = min; // minute of hour (0 .. 59)
	t.tm_hour = hour; // hour of day (0 .. 23)
	t.tm_mday = day; // day of month (0 .. 31)
	t.tm_mon = mon-1; // month of year (0 .. 11)
	t.tm_year = year-1900; // year since 1900
	t.tm_isdst = -1; // determine whether daylight saving time

    std::time_t tt = std::mktime(&t);
	if(tt == -1)
	{
		throw "no valid system time";
	}

	std::chrono::system_clock::time_point tp = 	std::chrono::system_clock::from_time_t(tt);
	std::chrono::time_point<C> rtp = std::chrono::time_point<C>(tp.time_since_epoch());
	return rtp;
}
#endif /* ifndef UTIL_CHRONO_DURATION_H*/
