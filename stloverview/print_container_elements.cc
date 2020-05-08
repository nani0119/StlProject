#include <vector>
#include <iterator>
#include "util_print_elements.h"

using namespace std;

int main(int argc, char *argv[])
{
	std::cout << "input some numbers,quit with <Ctl-d>:"<<endl;
	// vi begin 如果缺少一个括号，编译器把vi 解释成了函数
	// https://blog.csdn.net/jq0123/article/details/1931104
    // vector<int> vi(std::istream_iterator<int>(cin), std::istream_iterator<int>());
    vector<int> vi((std::istream_iterator<int>(cin)), std::istream_iterator<int>());
	
	// istream_iterator<int> b(cin);
	// istream_iterator<int> e;
	// vector<int> vi(b, e);

	PRINT_ELEMENTS(vi, "all elements:");
	return 0;
}
