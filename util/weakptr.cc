#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <functional>

using namespace std;

/**
 * @brief weak_ptr使用方法
 */
class Person
{
	public:
		string name;
        shared_ptr<Person> mother;
		shared_ptr<Person> father;
		/// weak_ptr 用来解决shared_ptr的循环依赖问题，不会增加对象的引用计数
		/// @code
		vector<weak_ptr<Person>> kids;
		/// @endcode
		
		Person(const string& n, shared_ptr<Person> m = nullptr, shared_ptr<Person> f = nullptr)
			: name(n), mother(m), father(f)
		{}

	    ~Person()
		{
			cout << "delete " << name << endl;
		}

		/**
		 * @brief   initFamily
		 *
		 * @param   name  孩子姓名
		 * @return 返回说明
		 * 		@retval kid 实例
		 */
		static shared_ptr<Person> initFamily(const string& name)
		{
			shared_ptr<Person> mom (new Person(name + "'s mom"));
			shared_ptr<Person> dad (new Person(name + "'s dad"));
			shared_ptr<Person> kid (new Person(name, mom, dad));
			kid->mother->kids.push_back(kid);
			kid->father->kids.push_back(kid);
			return kid;
		}
};

int main(int argc, char *argv[])
{
	shared_ptr <Person> p = Person::initFamily("nico");

	cout << "nico’s family exists" << endl;
	cout << "- nico is shared " << p.use_count() << " times" << endl;
	
	/// 使用weak_ptr的lock() 访问其内保存的对象指针
	/// @code
	cout << "- name of 1st kid of nico’s mom: "<< p->mother->kids[0].lock()->name << endl;
	/// @endcode
	
	/// 使用expired() 判断其内保存的对象是否已经被释放
	///　@code
	cout << std::boolalpha <<endl;
    cout <<	"expired:" << p->mother->kids[0].expired() << endl;
	///  @endcode
	
	/// 使用use_count()判断引用计数, 0 表示对象已被释放
	///　@code
	cout << "use count:" << p->mother->kids[0].use_count() << endl;
	///  @endcode
	
	/// 创建与shared_ptr转换
	/// @code
	shared_ptr<Person> Jim (new Person("Jim"));
	
	weak_ptr<Person> j = Jim;
	cout << "Jim use count:" << Jim.use_count() << endl; // 1
	cout << "Jim use count:" << j.use_count() << endl; // 1

	shared_ptr<Person> pj (j);   // 如果j 弱引用的对象被释放，转换为shared_ptr则抛出bad_weak_ptr异常

	cout<<"================================================================"<<endl;

	int* ni = new int(5);

	auto del = [](int* p){cout << "delete:" << *p << endl; delete p;};
	shared_ptr<int> pi (new int(3), del);

	decltype(del)* deleter = std::get_deleter<decltype(del)>(pi);

	if(deleter != nullptr)
	{
		cout << "deleter is not nullptr" << endl;;
	}
	else
	{
		cout << "deleter is a nullptr"<< endl;
	}

	
	return 0;
}
