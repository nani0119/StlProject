#include <iostream>
#include <regex>
#include <string>
#include "regexstuff.h"

using namespace std;


// <(.*)>(.*)<(/\\1)>
// XML tag:        <tag-name>the value</tag-name>.............
//                 \--m[1]--\--m[2]---\--m[3]---\
// \----prefix---\ \---------m[0]---------------\\--suffix----\

void testMatchResult(const string& data, Regex& reg)
{
    smatch m;
    string::const_iterator pos = data.cbegin();
    string::const_iterator end = data.cend();
    printDataAndReg(data, reg);
    for(int i = 1; regex_search(pos, end, m, reg); pos = m.suffix().first, i++)
    {
        cout << string(39, '+');
        cout << " " << i << " ";
        cout << string(39, '+') << endl;
        printMatchResult(data, m);
    }
}


int main(int argc, char const *argv[])
{
    //string data = "<tag-name>the value</tag-name>";

    string data = "<person>"
                   "<first>Nico</first>"
                   "<middle>Bill</middle>"
                   "<last>Josuttis</last>"
                  "</person>";

    Regex reg("<(.*)>([^>]*)</(\\1)>");
    testMatchResult(data, reg);
    return 0;
}
