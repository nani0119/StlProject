#include <iostream>
#include <locale>

using namespace std;


void testLocal()
{
    // global
    locale l1 = std::locale();
    cout << "local().name():" << l1.name()<<endl;

    // native
    locale l2 = std::locale("");
    cout << "local().name():" << l2.name()<<endl;

    locale l3 = std::locale(l1);
    cout << "local().name():" << l3.name()<<endl;

    locale l4 = std::locale("zh_CN.utf8");
    cout << "local().name():" << l4.name()<<endl;

    locale l5 = std::locale(l1, l4, locale::numeric);
    cout << "local().name():" << l5.name()<<endl;

    locale l6 = std::locale(l1, &(std::use_facet<std::numpunct<char>>(l4)));
    cout << "local().name():" << l6.name()<<endl;

    locale l7;
    l7.combine<std::numpunct<char>>(l4);
    cout << "local().name():" << l7.name()<<endl;

    cout << std::boolalpha << (l1 == locale::classic()) << endl;

    if(std::has_facet<std::moneypunct<char>>(std::locale()))
    {
        cout << true << endl;
    }

    cout.imbue(l1);
    cin.imbue(l4);
    string s;
    cout << "输入字符串："<< endl;
    cin >> s;
    cout << s << endl;
}

int main(int argc, char const *argv[])
{
    testLocal();
    return 0;
}
