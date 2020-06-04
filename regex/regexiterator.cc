#include <iostream>
#include <string>
#include <regex>
#include <algorithm>
#include <functional>
#include "regexstuff.h"

using namespace std;

void testIteator()
{
    string data =
        "<person>\n"
        " <first>Nico</first>\n"
        " <last>Josuttis</last>\n"
        "</person>\n";

    Regex reg("<(.*)>(.*)</(\\1)>");

    sregex_iterator pos(data.cbegin(), data.cend(), reg);
    sregex_iterator end;
    cout << std::boolalpha;
    printDataAndReg(data,reg);
    // pos: pointer of smatch
    for(;pos != end; ++pos)
    {
        smatch m = *pos;
        printMatchResult(data, *pos);
    }

    cout << string(80, '=') << endl;
    sregex_iterator beg(data.cbegin(), data.cend(), reg);
    auto printResult = std::bind(printMatchResult, std::ref(data), std::placeholders::_1);

    printDataAndReg(data,reg);
    std::for_each(beg, end, printResult);
}
int main(int argc, char const *argv[])
{
    testIteator();
    return 0;
}
