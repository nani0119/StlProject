#include <iostream>
#include <ostream>
#include <istream>
#include <fstream>

#include <sstream>
#include <memory>
#include <type_traits>
using namespace std;

// You can tie a stream to an output stream.the buffer of the output stream is flushed before each input or output of the other stream
void testTie()
{
}


void testUseSameOutRDBuf()
{
    ostream hexout(cout.rdbuf());
    hexout.setf (ios::hex, ios::basefield);
    hexout.setf (ios::showbase);

    // switch between decimal and hexadecimal output
    hexout << "hexout: " << 177 << " ";
    cout << "cout: " << 177 << " ";
    hexout << "hexout: " << -49 << " ";
    cout << "cout: " << -49 << " ";
    hexout << endl;
}

void redirect(ostream& strm)
{
    // save output buffer of the stream
    // - use unique pointer with deleter that ensures to restore
    // the original output buffer at the end of the function

    auto del = [&](streambuf* p) \
        { \
            cout << "restore stream buf" << endl; \
            strm.rdbuf(p); \
        };
    std::unique_ptr<streambuf, decltype(del)> originStreamBuf(strm.rdbuf(),del);

    // redirect ouput into the file redirect.txt
    ofstream file("redirect.txt");
    strm.rdbuf (file.rdbuf());
    file << "one row for the file" << endl;
    strm << "one row for the stream" << endl;
} // closes file AND its buffer automatically

void testRedirect()
{
    cout << "the first row" << endl;
    redirect(cout);
    cout << "the last row" << endl;
}

void testReadingWriting()
{
    filebuf buffer;
    istream input(&buffer);
    ostream output(&buffer);

    buffer.open ("example.dat", ios::in | ios::out | ios::trunc);

    for (int i=1; i<=4; i++) {
        // write one line to file
        output << i << ". line" << endl;

        input.seekg(0);
        // at the same time output to screen
        cout << input.rdbuf();
        cout << "===========================" << endl;
    }
}


int main(int argc, char const *argv[])
{
    testTie();
    testUseSameOutRDBuf();
    testRedirect();
    testReadingWriting();
    return 0;
}
