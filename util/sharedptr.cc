#include <iostream>
#include <string>
#include <memory>
#include <vector>
/**
 * @file		sharedptr.cc
 * @brief 		介绍shared_ptr
 * @author		作者
 * @date		20/04/10 
 * @version		1.0
 */
using namespace std;

void functionDeleter(string *p)
{
	cout << "delete: " << *p << endl;
	delete p;
}

class SharedPtrStringObjectDeleter
{
	private:
		string str;
	public:
		SharedPtrStringObjectDeleter(const string& s):str(s)
		{
		
		}
		void operator()(string* p)
		{
			cout << str << " " << *p << endl;
			delete p;
		}
};

/**
 * @brief shared_ptr使用示例
 */
class SharedPtrDemo
{
private:
public:
	/**
	 * @brief  shared_ptr简单使用 
	 *
	 */

	void createSharedPtr()
	{
		cout << "#######################"<<__func__<<"######################"<<endl;
        /// create shared_ptr
		/// @code
		shared_ptr<string> nico = shared_ptr<string>(new string("nico"));
		/// @endcode
		
		/// make_shared
		/// @code
		shared_ptr<string> jutta = make_shared<string>("jutta");
		/// @endcode
		
		/// assign
		/// @code
		string* bobstr = new string("bob");
		shared_ptr<string> bob{bobstr};
		/// @endcode
		
		/// reset
		/// @code
		
		shared_ptr<string> tom;
		tom.reset(new string("tom"));
		/// @endcode
		

		vector<shared_ptr<string>> personByTurn;
		personByTurn.push_back(nico);
		personByTurn.push_back(bob);
		personByTurn.push_back(jutta);

		cout <<"nico use count:" <<nico.use_count()<< endl;
		nico = nullptr;
		bob = nullptr;
		jutta = nullptr;

		for(auto ptr : personByTurn)
		{
			cout << *ptr << endl;
		}
		cout <<"nico use count:" <<personByTurn[0].use_count()<< endl;
	}

	/**
	 * @brief   使用shared_ptr
	 *
	 */

	void usingSharedPtr()
	{
		cout << "#######################"<<__func__<<"######################"<<endl;
		
		shared_ptr<string> spStr {new string("abcedfg")};
		
		/// using * access
		/// @code
		cout << *spStr << endl;
		/// @endcode
		
		/// using -> access
		/// @code
		cout << spStr->c_str()<<endl;
		/// @endcode
		
		/// get inner pointer
		/// @code
		string* str = spStr.get();
		cout << *str <<endl;
		/// @endcode
		
		/// not provid [] operator
		/// @code
		(*spStr)[0] = 'h';  // *spStr => string*
		cout << *spStr << endl;

		//spStr.get()[1] = 'i'; //ERROR,  pointer of string* + 1, not string + 1; 
		
		shared_ptr<string*> spStrArray(new string*[2]);
		spStrArray.get()[1] = new string("xxxxxxx");
		cout << *(spStrArray.get()[1]) << endl;
		/// @endcode

	}

	/**
	 * @brief   使用自定义deleter
	 *
	 */
	void deleterSharedPtr()
	{
		cout << "#######################"<<__func__<<"######################"<<endl;
		/// 使用lambda作为deleter
		/// @code
		shared_ptr<string> spLambdaStr (new string("lambda as deleter"), [](string* p){cout << "delete: " << *p << endl; delete p;});
		/// @endcode
		
		/// 使用函数作为deleter
		/// @code
		shared_ptr<string> spFuncStr (new string("func as deleter"), functionDeleter);
		/// @endcode
		
		/// 使用类作为deleter
		/// @code
		shared_ptr<string> spClassObjStr (new string("class obj as deleter"), SharedPtrStringObjectDeleter("delete:"));
		/// @endcode
		
		/// shared_ptr默认的deleter无法处理数据,对应数组需要提供自定义的deleter
		/// @code
		shared_ptr<int> spIntArray{new int[10], [](int* p){
													cout << "delete int array"<< endl;
													delete [] p;	
												}};
		/// @endcode
		for(int i = 0; i < 10; i++)
		{
			int* p = spIntArray.get();
			p[i] = i;
			cout << spIntArray.get()[i] << endl;
		}
	}	
};

int main(int argc, char *argv[])
{
	SharedPtrDemo demo;
	demo.createSharedPtr();	
	demo.usingSharedPtr();
	demo.deleterSharedPtr();
	return 0;
}
