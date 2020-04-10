#ifndef UTIL_TUPLEPRINT_H
#define UTIL_TUPLEPRINT_H
#include <iostream>
#include <tuple>

template <int IDX, int MAX, typename... Args>
class PrintTuple
{
public:
	static void print(std::ostream& strm, const std::tuple<Args...>& t)
	{
		strm << std::get<IDX>(t) << (IDX+1 == MAX? "":",");
		PrintTuple<IDX+1, MAX, Args...>::print(strm, t);
	}
};


template <int MAX, typename... Args>
class PrintTuple <MAX, MAX, Args...>
{
public:
	static void print(std::ostream& strm, const std::tuple<Args...>)
	{}
};

/**
 * @brief   打印tuple中的元素
 *
 * @param   strm 输出流
 * @param   t    需要打印的tuple
 * @return 返回说明
 * 		@retval 无
 */

template <typename... Args>
std::ostream& operator <<(std::ostream& strm, const std::tuple<Args ...>& t)
{
	strm << "[";
	PrintTuple<0, sizeof...(Args), Args...>::print(strm, t);
	strm << "]";
	return strm;
}
#endif /* ifndef UTIL_TUPLEPRINT_H */
