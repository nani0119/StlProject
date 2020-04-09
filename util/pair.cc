/**
 * @file		pair.cc
 * @brief 		pair类使用介绍
 * @details		
 * @author		zhaorj
 * @date		20/04/09 
 * @version		1.0
 */

#include <utility>
#include <iostream>
#include <tuple>
#include <functional>


using namespace std;

/**
 * @brief pair使用方法 
 */
class PairDemo
{	
	class Foo
	{
		public:
			Foo(tuple<int, float> t)
			{
				cout << "Foo::Foo(tuple)"<<endl;
			}

			template<typename... Args>
			Foo(Args...)
			{
				cout <<"Foo::Foo(args)"<<endl;
			}
	};

public:
	PairDemo(){}
	/**
	 * @brief   pair 创建方法
	 * @details pair变量创建方式说明
	 */

	void pairCreate()
	{
		cout << "=====================" << __func__ << "==========================="<<endl;
		/// 1.直接声明
		/// @code
		pair<int, float> p(1,3.14);
		/// @endcode
		cout << "p: [" << p.first << "," << p.second << "]" << endl;

		/// 2.make_pair
		/// @code
		pair<int, float> p1 = make_pair(2, 3.15);
		/// @endcode
		
		/// 3.将tuple每个元素分别传入构造函数，而不是将tuple作为一个整体
		/// @code
		tuple<int, float> t (1,1.1);
		pair<int, Foo> p3 (std::piecewise_construct, make_tuple(42), t);
		/// @endcode
		pair<int, Foo> p4 (42, t);

		return;
	}

	/**
	 * @brief   访问pair中的成员 
	 */
	void pairAccessMember()
	{
		cout << "=====================" << __func__ << "==========================="<<endl;
		pair<int, float> p(1,3.14);
		/// 1. first、second
		/// @code
		cout << p.first << " ," << p.second << endl;
		/// @endcode
		

		/// 2. get方法
		/// @code
		cout << get<0>(p) << " ," << get<1>(p) << endl;
		/// @endcode
		
		/// 3. tie方法
		int c;
		/// @code
		std::tie(c, std::ignore) = p;
		/// @endcode
		cout << c << endl;
	}

	/**
	 * @brief   修改pair中值
	 */
	void pairChangeValue()
	{
		cout << "=====================" << __func__ << "==========================="<<endl;
		int i = 0;
		int j = 0;

		/// 1.引用
		/// @code
		pair<int&, int&> p (std::ref(i), std::ref(j));
		i++;
		cout << p.first << " ," << p.second << endl;  // 1,0
		cout << i << endl;                            // 1
		p.second++;
		cout << p.first << " ," << p.second << endl;  // 1,1
		cout << j << endl; // 1
		/// @endcode
		
		/// 2.直接
		/// @code
		pair<int , int > p1(0,0);
		p1.first++;
		cout << p1.first << " ," << p1.second << endl;  // 1,0
		get<1>(p1) = 1;
		cout << p1.first << " ," << p1.second << endl;  // 1,1
		/// @endcode
	}	

	/**
	 * @brief  获取pair中元素的类型
	 */
	void pairElementType()
	{
		cout << "=====================" << __func__ << "==========================="<<endl;
		/// 获取pair中元素的类型
		/// @code
		typedef std::pair<int, float>  IntFloatPair;
		pair<int, float> p(1,3.4);
	    std::tuple_element<0,IntFloatPair>::type i = 5;
		std::tuple_element<1, pair<int, float>>::type f = 3.33;
		cout << i << endl;
	    cout << f << endl;	
		/// @endcode
	}

	/**
	 * @brief   pair　提供比较功能
	 */
	void pairComapre()
	{
		cout << "=====================" << __func__ << "==========================="<<endl;
		/// 比较
		/// @code
		pair<int, float> p1(1,1.11);
		pair<int, float> p2(1,1.11);
		cout << std::boolalpha <<"p1 == p2:"<< (p1 == p2) << endl;
		cout << std::boolalpha <<"p1 < p2:"<< (p1 < p2) << endl;
		cout << std::boolalpha <<"p1 >= p2:"<< (p1 >= p2) << endl;
		/// @endcode
	}
};



/**
 * @brief   main
 */
int main(int argc, char *argv[])
{
	PairDemo demo;
	demo.pairCreate();
	demo.pairAccessMember();
	demo.pairChangeValue();
	demo.pairElementType();
	demo.pairComapre();
	return 0;
}
