#ifndef REGEXSTUFF_H
#define REGEXSTUFF_H

#include <string>
#include <iostream>
#include <regex>

using namespace std;

template <typename T>
std::string regexCode(T code)
{
    switch (code)
    {
    case std::regex_constants::error_collate:
        return "error_collate: "
               "regex has invalid collating element name";
    case std::regex_constants::error_ctype:
        return "error_ctype: "
               "regex has invalid character class name";
    case std::regex_constants::error_escape:
        return "error_escape: "
               "regex has invalid escaped char. or trailing escape";
    case std::regex_constants::error_backref:
        return "error_backref: "
               "regex has invalid back reference";
    case std::regex_constants::error_brack:
        return "error_brack: "
               "regex has mismatched ’[’ and ’]’";
    case std::regex_constants::error_paren:
        return "error_paren: "
               "regex has mismatched ’(’ and ’)’";
    case std::regex_constants::error_brace:
        return "error_brace: "
               "regex has mismatched ’{’ and ’}’";
    case std::regex_constants::error_badbrace:
        return "error_badbrace: "
               "regex has invalid range in {} expression";
    case std::regex_constants::error_range:
        return "error_range: "
               "regex has invalid character range, such as ’[b-a]’";
    case std::regex_constants::error_space:
        return "error_space: "
               "insufficient memory to convert regex into finite state";
    case std::regex_constants::error_badrepeat:
        return "error_badrepeat: "
               "one of *?+{ not preceded by valid regex";
    case std::regex_constants::error_complexity:
        return "error_complexity: "
               "complexity of match against regex over pre-set level";
    case std::regex_constants::error_stack:
        return "error_stack: "
               "insufficient memory to determine regex match";
    }
    return "unknown/non-standard regex error code";
}

class Regex:public regex
{
    private:
        string pattern;
    public:
        Regex():regex(), pattern()
        {
        }
        Regex(const string& pattern): regex(pattern),pattern(pattern)
        {
        }
        string str()
        {
            return pattern;
        }
        void swap(Regex& r)
        {
            std::swap(pattern, r.pattern);
            regex::swap(r);
        }
        Regex& operator=(Regex& r)
        {
            pattern = r.pattern;
            regex::operator=(r);
            return *this;
        }
};

void printDataAndReg(const string& data, Regex& reg)
{
    cout << string(80, '=') << endl;
    cout << "data   : " << endl
         << data << endl;
    cout << "pattern: " << endl
         << reg.str() << endl;
}
void printMatchResult(const string& data, const smatch& m)
{
    cout << string(80,'+') << endl;
    cout << "m.empty()       : " << std::boolalpha << m.empty() << endl;
    cout << "m.size()        : " << m.size() << endl;
    cout << "m.str()         : " << m.str() << endl;
    cout << "m.position()    : " << m.position() << endl;
    cout << "m.length()      : " << m.length() << endl;
    cout << "m.prefix().str(): " << m.prefix().str() << endl;
    cout << "prefix range    : [" << std::distance(data.cbegin(), m.prefix().first) << "," << std::distance(data.cbegin(), m.prefix().second) << ")" << endl;
    cout << "m.suffix().str(): " << m.suffix().str() << endl;
    cout << "suffix range    : [" << std::distance(data.cbegin(), m.suffix().first) << "," << std::distance(data.cbegin(), m.suffix().second) << ")" << endl;
    cout << endl;
    for (int i = 0; i < m.size(); i++)
    {
        string s = "--";
        if (i != 0)
        {
            s = "----";
        }
        
        cout << s << "m[" << i << "].str()    : " << m[i].str() << endl;
        cout << s << "m.str(" << i << ")      : " << m.str(i) << endl;
        cout << s << "m.position(" << i << ") : " << m.position(i) << endl;
        cout << s << "m.length(" << i <<")    : " << m.length(i) << endl;
        cout << endl;
    }
    cout << endl;
    cout << "matches:" << endl;
    for (smatch::iterator pos = m.begin(); pos != m.end(); ++pos)
    {
        string s = "--";
        if (pos != m.begin())
        {
            s = "----";
        }

        cout << s << "string   : " << *pos << endl;
        cout << s << "position : [" << std::distance(data.cbegin(), pos->first) << "," << std::distance(data.cbegin(), pos->second) << ")" << endl;
        cout << s << "length   : " << pos->length() << endl;
        cout << endl;
    }
}

#endif