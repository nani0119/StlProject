#include <string>
#include <utility>
#include <functional>
#include "util_tupleprint.h"

using namespace std;

/**
 * @brief tuple operation
 */

class TupleDemo
{
	public:
		/**
		 * @brief   创建tuple方法
		 */
		void tupleCreate()
		{
			cout << "################" << __func__ << "################"<<endl;
			/// create tuple with default value 
			/// @code
			tuple<int, float, string> t;
			/// @endcode
			cout << t << endl;
			
			/// create tuple and init it
			/// @code
			tuple<int, float, string> t1 (1, 2.0, "hello");
			/// @endcode
			cout << t1 << endl;

			/// init tuple with pair
			/// @code
			tuple<int, float> t3 (make_pair<int, float>(1, 3.0));
			/// @endcode
			cout << t3 << endl;
			
			/// make_tuple
			/// @code
			auto t4 = make_tuple(1, 3.0, "world");
			/// @endcode
			cout << t4 << endl;

			/// assign
			/// @code
			auto t5 = t;
			/// @endcode
			cout << t5 << endl;

			/// assign a pair
			/// @code
			tuple<int, float> t6 = pair<int, float>(1, 1.0);
			/// @endcode
			cout << t6 << endl;
		}

		/**
		 * @brief   获取tuple内变量
		 */
		void tupleExtra()
		{
			cout << "################" << __func__ << "################"<<endl;
			
			/// 逐个元素访问
			/// @code
			tuple<int, float, string> t1 (1, 2.0 ,"hello");
			cout << std::get<0>(t1) << endl << std::get<1>(t1) << endl << std::get<2>(t1) << endl;
			/// @endcode
			
			/// tie
			/// @code
			int i;
			float f;
			string s;
			std::tie(i,f,s) = t1;
			cout << i << endl;
			cout << f << endl;
			cout << s << endl;
			/// @endcode
		
			/// the same as tie
			/// @code
			int ii;
			float ff;
			string ss;
			make_tuple(std::ref(ii), std::ref(ff), std::ref(ss)) = t1;
			// make_tuple => tuple tmp
			// tmp = t1
			// ref_ii = t-->i
			// ii = i
			cout << ii << endl;
			cout << ff << endl;
			cout << ss << endl;
			/// @endcode	
			
			i = 10;
			cout << t1 << endl;

			/// change element value
			/// @code
			std::get<0>(t1) = 10;
			/// @endcode
			cout << t1 << endl;
		}

		/**
		 * @brief  交换 
		 *
		 */
		void tupleSwap()
		{

			cout << "################" << __func__ << "################"<<endl;
			/// swap
			/// @code
			tuple<int, float, string> t1 (1, 2.0 ,"hello");
			tuple<int, float, string> t2 (2, 4.0 ,"world");
			cout << "t1:" << t1 << endl;
		    cout << "t2:" << t2 << endl;	
			t1.swap(t2);
			cout << "t1:" << t1 << endl;
		    cout << "t2:" << t2 << endl;	
			/// @endcode
		}

		/**
		 * @brief tuple 其他功能 
		 *
		 */

		void tupleAdditionFeature()
		{

			cout << "################" << __func__ << "################"<<endl;
			
			typedef tuple<int, float, string>  IntFloatStrTuple;
			IntFloatStrTuple t1 (1, 2.0 ,"hello");
			tuple<double, string> t2 (4.0 ,"world");
            cout << t1 << endl;
		    cout << t2 << endl;	
			
			/// size
			/// @code
			int sz;
			sz = std::tuple_size<IntFloatStrTuple>::value;
			cout << sz << endl;
			/// @endcode
			
			/// element type
			/// @code
			std::tuple_element<0, IntFloatStrTuple>::type i = 45;  // i --> int
			cout << i << endl;
			/// @endcode
			

			/// cat two tuple
			/// @code
			auto t3 = std::tuple_cat(t1, t2);
			cout << t3 << endl;
			/// @endcode
		}
};


int main(int argc, char *argv[])
{
	class TupleDemo demo;
	demo.tupleCreate();
	demo.tupleExtra();
	demo.tupleSwap();
	demo.tupleAdditionFeature();
	return 0;
}
