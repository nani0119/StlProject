#ifndef UTIL_PRINT_ELEMENTS
#define UTIL_PRINT_ELEMENTS
#include <iostream>
#include <string>

template <typename T>
inline void  PRINT_ELEMENTS(const T& coll, const std::string& optstr="")
{
	std::cout << optstr;
	for(const auto& elem: coll)
	{
		std::cout<< elem << ' ';
	}
	std::cout << std::endl;
}

#endif /* ifndef UTIL_PRINT_ELEMENTS*/
