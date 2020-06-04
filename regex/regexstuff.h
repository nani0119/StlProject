#ifndef REGEXSTUFF_H
#define REGEXSTUFF_H

#include <string>
#include <iostream>
#include <regex>

using namespace std;
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