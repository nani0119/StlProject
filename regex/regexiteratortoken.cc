#include <iostream>
#include <string>
#include <regex>

using namespace std;


int main(int argc, char const *argv[])
{
    string data = "<person>\n"
                  " <first>Nico</first>\n"
                  " <last>Josuttis</last>\n"
                  "</person>\n";

    regex reg("<(.*)>(.*)</(\\1)>");

    sregex_token_iterator pos (data.cbegin(), data.cend(), reg, {0,1,2,3}); // 0: m[0] ,1: m[1], 2: m[2], 3: m[3]
    sregex_token_iterator end;
    for(; pos != end; ++pos)
    {
        cout << "match: " << pos->str() << endl;
    }
    cout << "===================================================================" << endl;
    string names = "nico, jim, helmut, paul, tim, john paul, rita";
    regex sep("[ \t\n]*[,;.][ \t\n]*"); // separated by , ; or . and spaces
    sregex_token_iterator beg (names.cbegin(), names.cend(), sep, -1);  //sub_match

    sregex_token_iterator e;
    for(; beg != e; ++beg)
    {
        cout << "name : " << beg->str() << endl;
    }
    return 0;
}
