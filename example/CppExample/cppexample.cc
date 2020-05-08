#include <iostream>
#include <exception>
#include "util_exception.h"
using namespace std;

int main(int argc, char *argv[])
{
	cout << __cplusplus<<endl;
	try
	{
		throw logic_error("a logic error");
	}

	catch(...)
	{
		processException();
	}
    cout << "hello world"<<endl;
	return 0;
}
