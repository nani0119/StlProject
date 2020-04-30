#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <string>

using namespace std;

struct S
{
	char c1;
	char c2;
	int  i1;
	char a1[5];
	long l1;
	int  i2;
	void f()
	{

	}
	long l2;
	char a2[0];
};


void func()
{
	cout << __func__<<":" << "oops" << endl;
}

void test()
{
	S s;
	cout << "c1 offset :"  <<offsetof(S, c1)<<endl;
	cout << "c2 offset :"  <<offsetof(S, c2)<<endl;
	cout << "i1 offset :"  <<offsetof(S, i1)<<endl;
	cout << "a1[5] offset :"  <<offsetof(S, a1)<<endl;
	cout << "l1 offset :"  <<offsetof(S, l1)<<endl;
	cout << "i2 offset :"  <<offsetof(S, i2)<<endl;
	cout << "l2 offset :"  <<offsetof(S, l2)<<endl;
	cout << "a2[0] offset :"  <<offsetof(S, a2)<<endl;
	cout << "sizeof(S) :"  <<sizeof(S)<<endl;
	// std::terminate();
	// std::abort();
	exit(EXIT_FAILURE);	
	
}
int main(int argc, char *argv[])
{
	std::atexit(func);
	std::atexit([](){cout<<"lamda:oops"<<endl;});
	test();
	cout << "not here" << endl;
}
