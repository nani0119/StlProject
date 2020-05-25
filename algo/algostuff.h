#ifndef ALGOSTUFF_H
#define ALGOSTUFF_H 

#include <iostream>
#include <vector>
#include <array>
#include <deque>
#include <list>
#include <forward_list>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_map>
#include <string>
#include <iterator>
#include <functional>
#include <algorithm>
#include <numeric>

// - fill values from first to last into the collection, include last
template <typename C>
inline void INSERT_ELEMENTS(C& c, int first, int last)
{
	for(int i = first; i <= last; i++)
	{
		c.insert(c.end(), i);
	}
}

template <typename C>
inline void PRINT_ELEMENTS(const C& c, const std::string optstr = "")
{
	std::cout << optstr;
	for(auto elem : c)
	{
		std::cout << elem << " ";
	}
	std::cout << std::endl;
}

template <typename MC>
inline void PRINT_MAPPED_ELEMENTS(const MC& mc, const std::string optstr = "")
{
	std::cout << optstr;
	for(auto elem: mc)
	{
		std::cout << "[" << elem.first << ", " << elem.second << "] ";
	}
	std::cout << std::endl;
}

inline void PRINT_SPLIT_LINE(const std::string optstr = "")
{
	std::cout << std::endl;
	std::cout << "==========================================="<<std::endl;
	std::cout << "               " << optstr << std::endl;
	std::cout << "==========================================="<<std::endl;
	std::cout << std::endl;
}


#endif /* ifndef ALGOSTUFF_H */
