#include <iostream>

using namespace std;


void testIOState()
{
    int i = 0;
    cout << "input a number:" << endl;
    while(1)
    {
        cin >> i;
        if(cin.good())
        {
            cout << "input good" << endl;
            continue;
        }

        if(cin.fail())
        {
            cout << "input fail" << endl;
        }

        if(cin.eof())
        {
            cout << "input eof"<< endl;
            break;
        }


        if(cin.bad())
        {
            cout << "input bad" << endl;
        }
        cin.clear();
        cin.ignore();
    }    
}


int main(int argc, char const *argv[])
{
    testIOState();
    return 0;
}
