#include <iostream>

using namespace std;

void testIOStateException()
{
    cout <<__func__ <<"+++++++++++++++++++++++++"<< endl;
    int i;

    // store the old state
    std::ios::iostate oldExceptions = cin.exceptions();

    cin.exceptions(std::ios::failbit|std::ios::badbit);

    cout << "input numbers:" << endl;
    try
    {
        while (cin >> i)
        {
            cout << "num:" << i << endl;
        }
    }
    catch(const ios::failure& e)
    {
        cout << "I/O exception:" << e.what()<< endl;
        if(cin.eof())
        {
            cout << "EOF" << endl;
            return;
        }

        cin.exceptions(oldExceptions);

    }
}

int main(int argc, char const *argv[])
{
    testIOStateException();
    return 0;
}
