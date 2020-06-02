#include <iostream>
#include <bitset>

using namespace std;

void testSetsOfFlags()
{
    cout << "====================== test sets of flags========================"<< endl;
    enum Color {red, yellow, blue, green, white, black, numColors};
    bitset<numColors> usedColors;

    usedColors.set(red);
    usedColors.set(blue);
    usedColors.set(black);

    cout << "number of used colors     :" << usedColors.count() <<endl;
    cout << "bitfield of used colors   :" << usedColors <<endl;
    cout << "bitfiled of unused colors :" << ~usedColors <<endl;

    usedColors.reset(blue);

    if(usedColors[blue] == 1)
    {
        cout << "color blue is used"<< endl;
    }
    else
    {
        cout << "color blue is not used" << endl;
    }
    
    usedColors[green] = 1;
    if (usedColors[green] == 1)
    {
        cout << "color green is used"<< endl;
    }
    else
    {
        cout << "color green is not used" << endl;
    }

    cout << "color bitset:";
    if(usedColors.any())
    {
        for(int c = 0; c < numColors; c++)
        {
            cout << usedColors[(Color)c] << "  ";
        }
        cout << endl;
    }
}
#include  <limits>
void testBitSetConvert()
{
    cout << "====================== test bitset convert========================="<< endl;
    // print some numbers in binary representation
    cout << "267 as binary short: "
         << bitset<numeric_limits<unsigned short>::digits>(267)
         << endl;

    cout << "267 as binary long: "
         << bitset<numeric_limits<unsigned long>::digits>(267)
         << endl;

    cout << "10,000,000 with 24 bits: "
         << bitset<24>(1e7) << endl;
    
    // write binary representation into string
    string s = bitset<42>(12345678).to_string();
    cout << "12,345,678 with 42 bits: " << s << endl;

           s = bitset<42>(12345678).to_string('a','b');
    cout << "12,345,678 with 42 bits: " << s << endl;

    // transform binary representation into integral number
    cout << "\"1000101011\" as number: "
         << bitset<100>("1000101011").to_ullong() << endl;
    cout << "\"abbbababaa\" as number: "
         << bitset<100>("abbbababaa",string("abbbababaa").size(),'b','a').to_ullong() << endl;
}

int main(int argc, char const *argv[])
{
    testSetsOfFlags();
    testBitSetConvert();
    return 0;
}
