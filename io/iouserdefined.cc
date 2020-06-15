#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <string>
#include <exception>

using namespace std;

class Fraction
{
public:
    Fraction(): n(0), d(1)
    {}

    Fraction(int n, int d): n(n), d(d)
    {
        if(d == 0)
        {
            throw logic_error("denominator is zero");
        }
    }

    int numerator() const
    {
        return n;
    }
    int denominator() const
    {
        return d;
    }
private:
    int n;
    int d;
};

template <typename charT, typename traits>
inline std::basic_ostringstream<charT, traits>& 
operator <<(std::basic_ostream<charT, traits>& strm, 
                    std::basic_ostream<charT, traits>& (*op)(std::basic_ostream<charT, traits>&)
               )
{
    return (*op)(strm);
}

static const int __faction_space_index = std::ios_base::xalloc();

template <typename charT, typename traits>
std::basic_ostream<charT, traits>& factionspace(std::basic_ostream<charT, traits>& strm)
{
    strm.iword(__faction_space_index) = true;
    return strm;
}


template <typename charT, typename traits>
std::basic_ostream<charT, traits>& nofactionspace(std::basic_ostream<charT, traits>& strm)
{
    strm.iword(__faction_space_index) = false;
    return strm;
}

static const int __faction_presuffix_index = std::ios_base::xalloc();
class presuffix
{
    private:
        string fix;
    public:
        presuffix(): fix("")
        {}
        
        presuffix(const string& fix): fix(fix)
        {}

        ~presuffix()
        {
            cout << "DEBUG:fix--" << fix << "--destory presuffix object" << endl;
        }
        
        template <typename charT, typename traits>
        std::basic_ostream<charT, traits>& operator()(std::basic_ostream<charT, traits>& strm) const
        {
            strm.pword(__faction_presuffix_index) =  const_cast<char*>(fix.c_str());
            return strm;
        }

        template <typename charT, typename traits>
        friend std::basic_ostream<charT, traits>& operator<<(std::basic_ostream<charT, traits>& strm, const presuffix& op)
        {
            return op(strm);
            // strm.pword(__faction_presuffix_index) =  const_cast<char*>(op.fix.c_str());
            // return strm;

        }

};



template <typename charT, typename traits>
inline std::basic_ostream<charT, traits>& operator <<(std::basic_ostream<charT, traits>& strm, const Fraction& f)
{
    // 避免　　strm << setw(8) << 1/8, 输出异常－－－>　1        / 8 而不是　　　　　　　1/8,setw设置的值到下一次输出时失效
    std::basic_ostringstream<charT,traits> s;
    s.copyfmt(strm);
    s.width(0);

    if(strm.pword(__faction_presuffix_index) != 0)
    {
        s << static_cast<const char*>(strm.pword(__faction_presuffix_index));
    }
    if(strm.iword(__faction_space_index))
    {

        s<< f.numerator() << " / " << f.denominator();
    }
    else
    {
        s<< f.numerator() << '/' << f.denominator();
    }
    
    if(strm.pword(__faction_presuffix_index) != 0)
    {
        s << static_cast<const char*>(strm.pword(__faction_presuffix_index));
    }

    strm << s.str();
    return strm;

}


template <typename charT, typename traits>
inline std::basic_istream<charT, traits>&
operator >>(std::basic_istream<charT, traits>& strm, Fraction& f)
{
    int n, d;
    strm >> n;
    if(strm.peek() == '/')
    {
        strm.ignore();
        strm >> d;
    }
    else
    {
        d = 1;
    }

    if(d == 0)
    {
        strm.setstate(std::ios::failbit);
        return strm;
    }
    
    if(strm)
    {
        f = Fraction(n,d);
    }
    return strm;
} 

void testUserDefineOperator()
{
    Fraction vat(19,100);
    cout<<"VAT: \"" << std::left << std::setw(10) << std::setfill('-') << vat << '"' << endl;

    Fraction v(1,100);
    Fraction v2(2,100);
    cout << factionspace << v << endl << v2 << endl << nofactionspace << v << endl;

   {
        Fraction v3(3, 100);
        cout << presuffix("x") << v3 <<endl;
   }

    presuffix* p = new presuffix("|");
    cout << *p << v2 << endl;
    delete p;
    cout << v2 << endl;
    cout << presuffix()<<endl;
}

void testInputOperator()
{
    Fraction v1;
    cin >> v1;
    cout << v1 << endl;
}


void event_callback(std::ios::event e, std::ios_base& strm, int arg)
{
  switch (e)
  {
    case strm.copyfmt_event:
      std::cout << "copyfmt_event\n"; break;
    case strm.imbue_event:
      std::cout << "imbue_event\n"; break;
    case strm.erase_event:
      std::cout << "erase_event\n"; break;
  }
  std::cout <<"arg:"<< arg << endl;
  cout << "----------------------------" << endl;
}

void testEventCallback()
{
    stringstream ss;
    ss.register_callback(event_callback, 0);
    ss.register_callback(event_callback, 1);
    // ss << "aaaaaa" << endl;
    // ss.imbue (std::cout.getloc());
    // cout << ss.str() << endl;

    fstream fs;
    fs.copyfmt(ss);
}

int main(int argc, char const *argv[])
{
    testUserDefineOperator();
    cout << "===================input fraction===========" << endl;
    testInputOperator(); 
    testEventCallback();
    return 0;
}
