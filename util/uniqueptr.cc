#include <iostream>
#include <memory>
#include <string>
#include <functional>
using namespace std;

void deleterFunc(int* p)
{
	cout << __func__ << ":" << "func deleter" << endl;
	delete [] p;
}

/**
 * @brief unique_ptr demo
 * 
 */
class UniquePtrDemo
{
	private:

		void uniquePtrSink(unique_ptr<string> up)
		{
			cout << *up << endl;
		}

		unique_ptr<string> uniquePtrSource()
		{
			unique_ptr<string> up(new string("unique ptr source"));
			return up;
		}
	public:
		void uniquePtrUsing()
		{
			cout << "#########################"<<__func__<<"###########################"<< endl;
			/// create and init
			/// @code
			unique_ptr<string> up(new string("hello world"));
			cout << (*up)[0] << endl;
			cout << up->c_str() << endl;
			cout << *(up.get()) << endl;
			/// @endcode
			
			/// release
			/// @code
			// up = nullptr;
			// up.reset();
			string* pstr = up.release();  // lose ownship			
			/// @endcode
			cout << *pstr << endl;


			/// array
			/// @code
			unique_ptr<int[]> upIntArray(new int[10]);
			for(int i = 0; i < 10; i++)
			{
				upIntArray[i] = i;  // shared_ptr can use []
			}

			if(upIntArray)  // or upIntArray != nullptr or upIntArray.get() != nullptr
			{
				for(int i = 0; i < 10; i++)
				{
					cout<<	upIntArray[i] << ",　"; 
				}
				cout << endl;
			}
			/// @endcode
		}

		void uniquePtrTransferOwnship()
		{
			cout << "#########################"<<__func__<<"###########################"<< endl;
			/// tansfer ownship
			/// @code
			unique_ptr<string> up (new string("aaaaaaaaaaaa"));
			//unique_ptr<string> up1(up);   //ERROR
			unique_ptr<string> up1(std::move(up));
			unique_ptr<string> up2;
			up2 = std::move(up1);

			string* str = up2.release();
			/// @endcode
			cout << *str << endl;

			/// sink and source
			/// @code
			unique_ptr<string> up3 = uniquePtrSource();
			uniquePtrSink(std::move(up3));
			/// @endcode

		}

		class ClassDeleter
		{
			public:
				void operator()(int* p)
				{
					cout << __func__ << ":" << "class deleter" << endl;
					delete [] p;
				}
		};

		/**
		 * @brief   unique_ptr 使用非默认deleter函数
		 *
		 * @detail   unique_ptr 用在类的构造函数中能够保证即使构造函数出现异常退出，资源也会被释放
		 */
		void uniquePtrDeleter()
		{
			cout << "#########################"<<__func__<<"###########################"<< endl;
			/// class deleter
			/// @code
			unique_ptr<int[], ClassDeleter> pClassDeleter(new int[10]);  // deleter not need
			/// @endcode
			
			/// func deleter
			/// @code
			unique_ptr<int[], std::function<void(int*)> > pFuncDeleter(new int[10], deleterFunc);
			/// @endcode
			
			/// lambda deleter
			/// @code
			auto l = [](int* p) {cout << __func__ << ":" << "lambda deleter" << endl; delete [] p;};
			unique_ptr<int[], decltype(l)> pLambdaDeleter(new int[10], l);
			/// @endcode
		}
};


int main(int argc, char *argv[])
{
	UniquePtrDemo demo;
	demo.uniquePtrUsing();
	demo.uniquePtrTransferOwnship();
	demo.uniquePtrDeleter();
	
	return 0;
}
