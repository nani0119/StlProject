#include <iostream>
#include <functional>

using namespace std;

class C
{
	public:
		void memfunc(int x, int y)
		{
			cout << __func__<< ":" << endl;
			cout << "x = " << x << endl;
			cout << "y = " << y << endl;
		}
};

void func(int x, int y)
{
	cout << __func__<< ":" << endl;
	cout << "x = " << x << endl;
	cout << "y = " << y << endl;
}


int main(int argc, char *argv[])
{
	C c;
	std::function<void(C&, int, int)> fc = &C::memfunc;
	fc(c, 1, 2);

	std::function<void(int, int)> fn = func;
	fn(3,4);

	auto fl = [](int x, int y)->void {\
		                              cout << __func__<<":"<<endl;\
									  cout << "x = "<< x << endl;\
									  cout << "y = "<< y << endl;\
                                   	};
	fl(5, 6);



	return 0;
}
