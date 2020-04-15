#include "util_numeric_limit_info.h"

using namespace std;

int main(int argc, char *argv[])
{
	NumericLimitInfo<int>::getNumericInfo();

	NumericLimitInfo<float>::getNumericInfo();

	NumericLimitInfo<double>::getNumericInfo();

	NumericLimitInfo<bool>::getNumericInfo();

	NumericLimitInfo<string>::getNumericInfo();

	return 0;
}
