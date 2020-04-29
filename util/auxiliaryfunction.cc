#include <algorithm>
#include <iostream>
#include <utility>
#include <initializer_list>
using namespace std;

class MinMaxOperator
{
	private:
		int a = 1;
		int b = 2;
		initializer_list<int> l = {4,5,6,7,8,9,10};

	public:
		void testMin()
		{
			cout << __func__ << ":" << endl;
			const int& rMin = std::min(a, b);
			const int& rMax = std::max(a, b);
			cout << "min:" << rMin << endl;
			cout << "max:" << rMax << endl;

			// rMin = rMax + 1;
			// cout << "a:" << a << endl;
			// cout << "b:" << b << endl;

			const int& rMinCmp = std::min(a, b, [](const int& a, const int& b) { if(a < b) return a; else return b;});
			cout << "min:" << rMin << endl;
			cout << "max:" << rMax << endl;


			int rl = std::min(l);
			cout << "min:" << rl << endl;
			
			std::pair<int, int> minMaxl = std::minmax(l);
			cout << "min:" << minMaxl.first << endl;
			cout << "max:" << minMaxl.second << endl;

		}
		void testAll()
		{
			testMin();
		}
};


class MyContainer
{
	friend ostream& operator << (ostream& os, const MyContainer& mc);
	private:
		int* elems;
		int  num;
	public:
		MyContainer(int* elements, int cnt) : elems(elements), num(cnt)
	    {}

		void swap(MyContainer& mc)
		{
			std::swap(elems, mc.elems);
			std::swap(num, mc.num);
		}


};

void swap(MyContainer& mc1, MyContainer& mc2) noexcept(noexcept(mc1.swap(mc2)))
{
	mc1.swap(mc2);
}

ostream& operator <<(ostream& os, const MyContainer& mc)
{
	for(int i = 0; i < mc.num; i ++)
	{
		os << (mc.elems)[i] << " ";
	}
	return os;
};


class SupplementComOperator
{
	friend ostream& operator<<(ostream& os, const SupplementComOperator& s);
	private:
		void* n;
	public:
		SupplementComOperator(void* i) :n(i)
		{}
		bool operator==(const SupplementComOperator& s) const
		{
			if(s.n == n)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	    bool operator <(const SupplementComOperator& s) const
		{

			if(n <  s.n)
			{
				return true;
			}
			else
			{
				return false;
			}
		}	
};

ostream& operator<<(ostream& os, const SupplementComOperator& s)
{
	os << s.n;
	return os;
}

int main(int argc, char *argv[])
{
	cout << "##############################################" << endl;
	MinMaxOperator minMaxT;
	minMaxT.testAll();
	
	cout << "##############################################" << endl;

	int ai1[] = {1,2,3,4,5,6,7,8};
	int ai2[] = {8,7,6,5,4,3,2,1};
	MyContainer mc1(ai1, sizeof(ai1)/sizeof(ai1[0]));
	MyContainer mc2(ai2, sizeof(ai2)/sizeof(ai2[0]));
	std::cout << "before:" << endl;
	std::cout <<"mc1:"<< mc1 << endl;
	std::cout <<"mc2:"<<mc2 << endl;

	swap(mc1, mc2);

	std::cout << "after:" << endl;
	std::cout <<"mc1:"<< mc1 << endl;
	std::cout <<"mc2:"<<mc2 << endl;
	cout << "##############################################" << endl;

	SupplementComOperator s1((void*)ai1);
	SupplementComOperator s2((void*)&s1);
	std::cout <<"s1:"<< s1 << endl;
	std::cout <<"s2:"<< s2 << endl;
	std::cout << std::boolalpha<<endl;

	using namespace std::rel_ops;
	std::cout <<"s1 < s2:" << (s1 < s2) << endl;
	std::cout <<"s1 <= s2:" << (s1 <= s2) << endl;
	std::cout <<"s1 == s2:" << (s1 == s2) << endl;
	std::cout <<"s1 != s2:" << (s1 != s2) << endl;
	std::cout <<"s1 > s2:" << (s1 > s2) << endl;
	std::cout <<"s1 >= s2:" << (s1 >= s2) << endl;

	return 0;
}
