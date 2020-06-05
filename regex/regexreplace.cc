#include <iostream>
#include <regex>
#include <string>

using namespace std;


int main(int argc, char const *argv[])
{
    string data = "<person>\n"
                  " <first>Nico</first>\n"
                  " <last>Josuttis</last>\n"
                  "</person>\n";
    regex reg("<(.*)>(.*)</(\\1)>");

    string str;
    // $& : The matched pattern 
    // $n : The nth matched capture group
    // $` : The prefix of the matched pattern
    // $' : The suffix of the matched pattern
    // $$ : The character $
    // regex_constants::format_no_copy : don’t copy characters that don’t match
    // regex_constants::format_first_only : replace only the first match found
    
    regex_replace(back_inserter(str), 
                    data.begin(), data.end(),
                    reg,
                    "matched pattern: $& \n prefix:$` \n nth matched capture group:$0 $1 $2 $3 \n  suffix:$' \n",
                    regex_constants::format_no_copy
                );
    cout << str << endl;
    cout << "=====================================================" << endl;
    cout << regex_replace(data,reg, "$0 ===> $1 + $2 + $3\n",regex_constants::format_no_copy);
    cout << endl;

     return 0;
}
