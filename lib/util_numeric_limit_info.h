#ifndef UTIL_NUMERIC_LIMIT_INFO
#define UTIL_NUMERIC_LIMIT_INFO
#include <iostream>
#include <limits>

template <typename T>
class NumericLimitInfo
{
	public:
		static void getNumericInfo()
		{
			std::cout << std::boolalpha;
			std::string name = typeid(T).name();
			std::cout << "###########################################################" << std::endl;
			std::cout << "type:              "<< name << std::endl;

			/// 标准库是否为其实现了特化
			/// @code
			std::cout << "is_specialized():  " << std::numeric_limits<T>::is_specialized << std::endl;
			/// @endcode
			
			/// 最大值
			/// @code
			std::cout << "max():             " << std::numeric_limits<T>::max() << std::endl;
			/// @endcode

			/// 最小值
			/// @code
			std::cout << "min():             " << std::numeric_limits<T>::min() << std::endl;
			/// @endcode
		
			/// 最大负值
			/// @code
			std::cout << "lowest():          " << std::numeric_limits<T>::lowest() << std::endl;
			/// @endcode

			/// 是否是有符号的，即可以表示正负值
			/// @code
			std::cout << "is_signed():       " << std::numeric_limits<T>::is_signed << std::endl;
			/// @endcode
			
			/// 是否是整形的
			/// @code
			std::cout << "is_integer():      " << std::numeric_limits<T>::is_integer << std::endl;
			/// @endcode
			
			/// 是否是精确表示的
			/// @code
			std::cout << "is_exact():        " << std::numeric_limits<T>::is_exact << std::endl;
			/// @endcode
			
			/// 是否存在大小界限
			/// @code
			std::cout << "is_bounded():      " << std::numeric_limits<T>::is_bounded << std::endl;
			/// @endcode
			
			/// 两个比较大的数相加而不会溢出，生成一个较小的值
			/// @code
			std::cout << "is_modulo():       " << std::numeric_limits<T>::is_modulo << std::endl;
			/// @endcode
			
			/// 是否符合某某标准
			/// @code
			std::cout << "is_iec559():       " << std::numeric_limits<T>::is_iec559 << std::endl;
			/// @endcode
			
			/// 不加+-号可以表示的位数
			/// @code
			std::cout << "digits():          " << std::numeric_limits<T>::digits << std::endl;
			/// @endcode
			
			/// 十进制数的个数
			/// @code
			std::cout << "digits10():        " << std::numeric_limits<T>::digits10 << std::endl;
			/// @endcode
			
			/// 基数，一般基数为2
			/// @code
			std::cout << "radix():           " << std::numeric_limits<T>::radix << std::endl;
			/// @endcode
			
			/// 以2为基数的最小指数
			/// @code
			std::cout << "min_exponent():    " << std::numeric_limits<T>::min_exponent << std::endl;
			/// @endcode
			
			/// 以2为基数的最大指数
			/// @code
			std::cout << "max_exponent():    " << std::numeric_limits<T>::max_exponent << std::endl;
			/// @endcode
			
			/// 以10为基数的最小指数
			/// @code
			std::cout << "min_exponent10():  " << std::numeric_limits<T>::min_exponent10 << std::endl;
			/// @endcode
			
			/// 以10为基数的最大指数
			/// @code
			std::cout << "max_exponent10():  " << std::numeric_limits<T>::max_exponent10 << std::endl;
			/// @endcode
			
			/// 1值和最接近1值的差距
			/// @code
			std::cout << "epsilon():         " << std::numeric_limits<T>::epsilon() << std::endl;
			/// @endcode
			
			/// 舍入方式
			/// @code
			std::cout << "round_style():     " << std::numeric_limits<T>::round_style << std::endl;
			/// @endcode
		}	
};

#endif /* ifndef UTIL_NUMERIC_LIMIT_INFO */
