#include <iostream>
#include <sstream>
#include <locale>
#include <iterator>
#include <iomanip>

using namespace std;


void numpuncCat(locale& l)
{

    cout << string(80,'-') << endl;
    cout << "locale name                    : " << l.name() << endl;
    cout.imbue(l);

    const numpunct<char>& np = use_facet<numpunct<char>>(l);
    cout << "np.decimal_point()             :" << np.decimal_point() << endl;
    cout << "np.thousands_sep()             :" << np.thousands_sep() << endl;
    cout << "np.grouping()                  :" << np.grouping() << endl;
    cout << "np.truename()                  :" << np.truename() << endl;
    cout << "np.falsename()                 :" << np.falsename() << endl;

    const num_put<char>& nput = use_facet<num_put<char>>(l);
    cout << "formatting of 123456789        :";
    nput.put(cout, cout, ' ', static_cast<long>(1234567890));
    cout << endl;

    cin.imbue(l);
    long num = 0;
    std::ios_base::iostate err;
    stringstream ss;
    ss << "9,876,543,210";
    const num_get<char>& nget = use_facet<num_get<char>>(l);
    nget.get(istreambuf_iterator<char>(ss), istreambuf_iterator<char>(),
             cin,
             err,
             num);

    if((err&std::ios::goodbit) == std::ios::goodbit)
    {
        cout <<"parse input number "<< ss.str() << "  :"<< num << endl;
    }
    else
    {
        cout << "input error" << endl;
    }

}

void testNumpunctCat()
{
    cout << __func__ <<":"<< endl;
    // default
    locale l1 = locale();
    locale l2 = locale("zh_CN.utf8");

    numpuncCat(l1);
    numpuncCat(l2);
}
// output operator for pos_format() and neg_format():
ostream &operator<<(ostream &strm, moneypunct<char>::pattern p)
{
    for (int i = 0; i < 4; ++i)
    {
        auto f = p.field[i];
        strm << (f == money_base::none ? "none" : 
                    f == money_base::space ? "space" : 
                    f == money_base::symbol ? "symbol" : 
                    f == money_base::sign ? "sign" :
                    f == money_base::value ? "value" : "???") 
             << " ";
    }
    return strm;
}

template <bool intl>
void monetaryCat(locale& l)
{
    cout << string(80,'-') << endl;
    cout << "locale name                    : " << l.name() << endl;
    cout.imbue(l);
    const std::moneypunct<char, intl>& mp = std::use_facet<moneypunct<char, intl>>(l);

    cout << "mp.decimal_point(): " << mp.decimal_point() << endl;
    cout << "mp.thousands_sep(): " << mp.thousands_sep() << endl;
    cout << "mp.grouping(i): ";

    for (int i=0; i<mp.grouping().size(); ++i) {
        cout << static_cast<int>(mp.grouping()[i]) << " ";
    }
    cout << endl;
    cout << "mp.curr_symbol(): " << mp.curr_symbol() << endl;
    cout << "mp.positive_sign(): " << mp.positive_sign() << endl;
    cout << "mp.negative_sign(): " << mp.negative_sign() << endl;
    cout << "mp.frac_digits(): " << mp.frac_digits() << endl;
    cout << "mp.pos_format(): " << mp.pos_format() << endl;
    cout << "mp.neg_format(): " << mp.neg_format() << endl;
    
    cout << std::showbase;
    cout << "12345.6789:";
    const money_put<char>& mpput = use_facet<money_put<char> >(l);
    // 货币单位最小值：分
    mpput.put (cout, intl, cout, ' ', 1234567890.54);
    cout << endl;

    std::ios_base::iostate err;
    string money;
    const money_get<char>& mpget = use_facet<money_get<char>>(l);
    stringstream ss;
    ss << "98765.4321";
    mpget.get(istreambuf_iterator<char>(ss), istreambuf_iterator<char>(),
                intl,
                cin,
                err,
                money);  
    cout << "parse money :";
    cout << money << endl;
}

void testMonetaryPunctuation()
{
    cout << __func__ <<":"<< endl;
    locale l1("en_US.utf8");
    locale l2 = locale("zh_CN.utf8");
 
    monetaryCat<false>(l1);

    monetaryCat<false>(l2);
    monetaryCat<true>(l2);
}

template <bool intl=false>
void testMoneyManipulator()
{
    locale l("zh_CN.utf8");
    cin.imbue(l);
    cout.imbue(l);
    cout << std::showbase;

    long double val;
    if(intl)
    {
        cout << "input monetary value using i18n sym: ";
    }
    else
    {

        cout << "input monetary value using local sym: ";
    }
    cin >> get_money(val,intl);
    if (cin)
    {
        // write monetary value (use local symbol)
        cout << put_money(val, intl) << endl;
    }
    else
    {
        cerr << "invalid format" << endl;
    }
}

int main(int argc, char const *argv[])
{
    //testNumpunctCat();
    testMonetaryPunctuation();
    testMoneyManipulator();
    testMoneyManipulator<true>();
    return 0;
}
