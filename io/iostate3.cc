#include <iostream>

using namespace std;


void testIOState()
{
    int i = 0;
    cout << "input numbers:" << endl;
    while (cin >> i)
    {
        if (!cin == false)
        {
            cout << "input is good" << endl;
        }
    }

    if(!cin)
    {
        throw std::ios::failure("input error");
    }
}

int main(int argc, char const *argv[])
{
    try{
        testIOState();
    }
    catch (const ios::failure &error)
    {
        cerr << "I/O exception: " << error.what() << endl;
    }
    return 0;
}
