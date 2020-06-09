#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;


void testIOFormatting()
{
    //boolalpha
    cout << std::boolalpha <<"boolalpha: "<< true << std::noboolalpha<<endl;

    // width and fill 
    cout <<"the current field width:" <<cout.width() << endl;
    cout <<"the current fill character:" <<cout.fill() << endl;
    cout.width(6);
    cout.fill('_');
    cout <<"the current field width:" <<cout.width() << endl;
    cout <<"the current fill character:" <<cout.fill() << endl;
    
    // after any formatted I/O operation is performed, the default field width is restored
    // The values of the fill character and the adjustment remain unchanged until they are modified explicitly
    cout <<left;
    cout <<setw(8)<< -42 << "\t" << setw(8)<<setfill('-')<< 0.12 << "\t" << "Q" << "\t" <<'Q' << endl;
    cout<<internal;
    cout <<setw(8)<< -42 << "\t" << setw(8)<<setfill('-')<< 0.12 << "\t" << "Q" << "\t" <<'Q' << endl;
    cout <<right;
    cout <<setw(8)<< -42 << "\t" << setw(8)<<setfill('-')<< 0.12 << "\t" << "Q" << "\t" <<'Q' << endl;
    cout << setfill(' ');
#if 0
    cout << "at most 2 chars can be read,using setw(3)" << endl;
    char buffer[8];
    // read, at most, 2 characters:
    cin >> setw(3) >> buffer;
    cout << "buffer:" << buffer<<endl;
#endif
    // positive and uppercase
    cout << std::showpos;
    cout << std::uppercase;
    cout << 12345678.9 << endl;
    cout << -12345678.9 << endl;
    cout << std::noshowpos;
    cout << std::nouppercase;

    // numeric base and showbase 

    cout << std::dec << 32 <<  "\t" << std::oct << 32 << "\t" << std::hex << 32 << endl;
    cout <<std::showbase <<std::dec << 32 <<  "\t" << std::oct << 32 << "\t" << std::hex << 32 << endl;
    cout << std::noshowbase << std::dec<<endl;

    // floating-point
    // The default precision is six decimal places
    cout << std::showpoint;
    cout << "setprecision(2):" << setprecision(2)<<endl;
    cout <<"normal      : "<< 421.0 << "\t" << 0.0123456789 << endl;
    cout <<"fixed       : " << std::fixed << 421.0 << "\t" << 0.0123456789 << endl;
    cout <<"scientific  : " << std::scientific << 421.0 << "\t" << 0.0123456789 << endl;
    cout <<"hexfloat    : " << std::hexfloat << 421.0 << "\t" << 0.0123456789 << endl;
    cout <<"defaultfloat: " << std::hexfloat << 421.0 << "\t" << 0.0123456789 << endl;
    cout << "===============================================================" << endl;
    cout << "setprecision(6):" << setprecision(6) << endl;
    cout <<"normal      : "<< 421.0 << "\t" << 0.0123456789 << endl;
    cout <<"fixed       : " << std::fixed << 421.0 << "\t" << 0.0123456789 << endl;
    cout <<"scientific  : " << std::scientific << 421.0 << "\t" << 0.0123456789 << endl;
    cout <<"hexfloat    : " << std::hexfloat << 421.0 << "\t" << 0.0123456789 << endl;
    cout <<"defaultfloat: " << std::hexfloat << 421.0 << "\t" << 0.0123456789 << endl;

    cout << std::noshowpoint;


    string s;
    cout << "noskipws"<<endl;
    cin >> std::noskipws;
    cin >> s;
    cout << s << endl;
    // Flushes the output buffer after each write operation
    cout << std::unitbuf;
    
    cin.ignore(std::numeric_limits<std::streamsize>::max(),cin.widen('\n'));
    
    cin >> std::skipws;
    // Flushes the output buffer after each write operation
    cout << std::unitbuf;
}

int main(int argc, char const *argv[])
{
    testIOFormatting();
    return 0;
}
