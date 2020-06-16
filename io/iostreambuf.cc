#include <iostream>
#include <string>
#include <streambuf>
#include <iterator>
#include <locale>
#include <cstdio>

using namespace std;

void testStreamBufferInterface()
{
    char ch;
    auto coutStreamBuf = cout.rdbuf();
    streambuf* cinStreamBuf = cin.rdbuf();

    coutStreamBuf->sputc('C');
    cout << endl;

    cout << "======================input==================" << endl;
    cout << "sgetc()   :" << endl;
    cinStreamBuf->sgetc();
    cin >> ch;
    cout << ch << endl;
    cinStreamBuf->sputbackc('X');
    cinStreamBuf->sputbackc('Y');
    cin >> ch;
    cout << ch << endl;
    cin >> ch;
    cout << ch << endl;
    cin >> ch;
    cout << ch << endl;
}

void testStreamBufIterator()
{
    istreambuf_iterator<char> in(cin);
    istreambuf_iterator<char> end;
    ostreambuf_iterator<char> out(cout);
    while(in != end)
    {
        *out = *in;
        ++out;
        ++in;
    }
}

#if 1
template <typename charT, typename traits=std::char_traits<charT>>
class basic_outbuf:public std::basic_streambuf<charT, traits>
{
    protected:
        virtual typename traits::int_type overflow(typename traits::int_type c)
        {
            //cout << __func__ << ":" << static_cast<char>(c) <<endl;
            if(!traits::eq_int_type(c, traits::eof()))
            {
                c = use_facet < ctype<charT> >(this->getloc()).toupper(c);
                char cc = std::use_facet<std::ctype<charT>>(this->getloc()).narrow(c, '?');
                if(std::putchar(cc) == EOF)
                {
                    return traits::eof();
                }
            }
            return traits::not_eof(c);
        }
};
typedef basic_outbuf<char> outbuf;
typedef basic_outbuf<wchar_t> woutbuf;
#else

class outbuf : public std::streambuf
{
protected:
    // central output function
    // - print characters in uppercase mode
    virtual int_type overflow(int_type c)
    {
        //cout << __func__ << " :" << static_cast<char>(c) << endl;
        if (c != EOF)
        {
            // convert lowercase to uppercase
            c = use_facet < ctype<char> >(this->getloc()).toupper(c);	
            // and write the character to the standard output
            if (std::putchar(c) == EOF)
            {
                return EOF;
            }
        }
        return c;
    }
};

#endif

void testUserDefinedStreamBuf()
{
    outbuf ob;
    std::ostream out(&ob);
    out << "hexadecimal: " << std::hex << 31 << std::endl;
    // cout.rdbuf(&ob);
    // cout << "hexadecimal: " << std::hex << 31 << std::endl;
}

int main(int argc, char const *argv[])
{
    // testStreamBufferInterface();
    // testStreamBufIterator();
    testUserDefinedStreamBuf();
    return 0;
}
