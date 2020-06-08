#include <iostream>
#include <string>

using namespace std;


void  testIOState()
{
    int i = 0;
    std::ios::iostate state;
    cout << "input a int,input 9 for quit "<< endl;
    while (i != 9)
    {
        cin >> i;
        cout << "i = " << i << endl;

        state = cin.rdstate();

        if(state == std::ios::goodbit)
        {
            continue;
        }

        if (state & std::ios::failbit)
        {
            cout << "cin stream failbit is set" << endl;
            cin.clear(state&~std::ios::failbit);
        }

        if (state & std::ios::eofbit)
        {
            cout << "cin stream eofbit is set" << endl;
            // clear eofbit, notic that clear(state) is that clear all bits and set the state
            cin.clear(state&~std::ios::eofbit);
            break;
        }
        if (state & std::ios::badbit)
        {
            cout << "cin stream badbit is set" << endl;
            cin.clear(state&~std::ios::badbit);
        }
        // ignore the last error char, or next time is still error
        cin.ignore();
    }
}

int main(int argc, char const *argv[])
{
    testIOState();
    return 0;
}
