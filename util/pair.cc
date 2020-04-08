#include <utility>
#include <iostream>
#include <tuple>
#include <functional>

using namespace std;

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


int main(int argc, char *argv[])
{
	// 获取pair中包含的值
	pair<int, float> p(1, 3.14);
        cout << "pair:p [" << p.first << "," <<p.second<<"]"<< endl;
        cout << "pair:p [" << get<0>(p) << "," << get<1>(p) << "]" << endl;

	int c;
	std::tie(c, std::ignore) = p;
	cout << c << endl;

	// 修改pair中的值
	int i = 0;
	pair<int&, int&> p6 = std::make_pair(std::ref(i), std::ref(i));
	pair<int, int> p7 (i, i);
	i++;
	p6.first++;
	p6.second++;

	cout << "p6:[" << p6.first << "," <<p6.second <<"]" <<endl; //[3,3]
	cout << "p7:[" << p7.first << "," <<p7.second <<"]" <<endl; //[0,0]

	std::get<0>(p6) = 5;
	std::get<0>(p7) = 5;
	cout << "p6:[" << p6.first << "," <<p6.second <<"]" <<endl; //[5,5]
	cout << "p7:[" << p7.first << "," <<p7.second <<"]" <<endl; //[5,0]
	
	p7.second++;
	cout << "p7:[" << p7.first << "," <<p7.second <<"]" <<endl; //[5,1]
	
	// 构造pair
	pair<int,float> p1 = make_pair(1, 3.14);

	// piecewise_construct 将tuple中的值逐个传入的构造函数中
        tuple<int, float> t (1, 3.14);
        pair<int, Foo> p3 (1, t);
        pair<int, Foo> p4 (std::piecewise_construct, make_tuple(1), t);

	// 比较
        cout <<"p == p1:" << std::boolalpha << (p==p1) << endl;
    

	// 获取pair　element 数据类型	
	typedef std::pair<int, float>  IntFloatPair;
	// IntFloatPair p5(2,3.15);
	// cout <<"p5 size:	"<< std::tuple_size<IntFloatPair>::value<<endl;
	
	std::tuple_element<0,IntFloatPair>::type pairType = 15;
	cout << pairType << endl;

	return 0;
}
