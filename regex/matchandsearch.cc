#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
    regex reg1("<(.*)>.*</\\1>");

    string s1 = "<tag>value</tag>";
    string s2 = "XML tag: " + s1;

    // "match" is match the whole string 
    bool found = std::regex_match(s1, reg1);
    if(found)
    {
        cout << "match the string \""<<s1 << "\"" << endl;
    }  

    found = std::regex_match(s2,reg1);
    if(!found)
    {
        cout << "not match the string \""<<s2 << "\"" << endl;
    }


    // "search" is not match the whole string, partially match 
    found = std::regex_search(s1, reg1);
    if(found)
    {
        cout << "serached the string \""<<s1 << "\"" << endl;
    }

    found = std::regex_search(s2, reg1);
    if(found)
    {
        cout << "serached the string \""<<s2 << "\"" << endl;
    }
    return 0;
}

