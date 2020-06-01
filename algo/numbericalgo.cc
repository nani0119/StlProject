#include "algostuff.h"
using namespace std;


void testAccumulate()
{
    PRINT_SPLIT_LINE("accumulate");
    vector<int> vi;
    INSERT_ELEMENTS(vi, 1, 9);
    
    cout << "accumulate from 1 to 9, sum :" << std::accumulate(vi.begin(), vi.end(), 0) << endl;

    auto fn = [](const int& sum, const int& e){ \
                    int tmp = sum; \
                    if(e % 2 == 1) \
                    {  \
                        tmp += e; \
                    } \
                    return tmp; \
               };

    // initval += initval op elem
    cout << "accmulate form 1 to 9 for odds, sum:" << std::accumulate(vi.begin(), vi.end(), 0, fn)<< endl;
}


void testInnerPruduct()
{
    PRINT_SPLIT_LINE("inner_product");
    vector<int> vi;
    INSERT_ELEMENTS(vi, 1, 4);
    list<int> li;
    INSERT_ELEMENTS(li, 1, 4);

    cout << "from 1 to 4,product:" ;
    // initval = initval + a1*b1 + a2*b2 + ...  
    cout << std::inner_product(vi.begin(), vi.end(),
                                li.begin(),
                                0
                                );
    cout << endl;

    //initval =+ initval op1( a1 op2 b1) op1 (a2 op2 b2) ......
    cout << "from 1 to 4 whith op1 and op2:";
    cout << std::inner_product(vi.begin(), vi.end(),
                                li.begin(),
                                0,
                                std::multiplies<int>(),  // op1
                                std::plus<int>()  // op2
                               );
    cout << endl;

}

void testPartialSum()
{
    PRINT_SPLIT_LINE("partial sum");
    vector<int> vi;
    INSERT_ELEMENTS(vi, 1, 6);
    // a1, a1+a2, a1+a2+a3, ... ...
    cout << "partial sum:";
    std::partial_sum(vi.begin(), vi.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    // a1 ,a1 op a2, a1 op a2 op a3, ... ...
    cout << "partial sum with op:";
    std::partial_sum(vi.begin(), vi.end(), ostream_iterator<int>(cout, " "), std::multiplies<int>());
    cout << endl;
}


void testAdjacentDifference()
{
    PRINT_SPLIT_LINE("adjacent_diffence");
    vector<int> vi;
    INSERT_ELEMENTS(vi, 1, 6);

    cout << "adjacent difference:";
    // a1, a2-a1, a3-a2, a4-a3, ... ...
    std::adjacent_difference(vi.begin(), vi.end(), ostream_iterator<int>(cout, "  "));
    cout << endl;

    cout << "adjacent difference with op:";
    // a1, a1 op a2, a2 op a3, ... ... 
    std::adjacent_difference(vi.begin(), vi.end(), ostream_iterator<int>(cout, " "), std::plus<int>());
    cout << endl;

        cout << "adjacent difference with multiplies:";
    // a1, a1 op a2, a2 op a3, ... ... 
    std::adjacent_difference(vi.begin(), vi.end(), ostream_iterator<int>(cout, " "), std::multiplies<int>());
    cout << endl;
}

void testConvertRelativeValue2AbsoluteValue()
{
    vector<int> coll = { 17, -3, 22, 13, 13, -9 };
    PRINT_ELEMENTS(coll,"coll: ");

    // convert into relative values
    adjacent_difference(coll.cbegin(), coll.cend(), // source
                        coll.begin());              // destination
    PRINT_ELEMENTS(coll, "relative: ");

    // convert into absolute values
    partial_sum(coll.cbegin(), coll.cend(), // source
                coll.begin());              // destination
    PRINT_ELEMENTS(coll, "absolute: ");
}
int main(int argc, char const *argv[])
{
    testAccumulate();
    testInnerPruduct();
    testPartialSum();
    testAdjacentDifference();
    testConvertRelativeValue2AbsoluteValue();
    return 0;
}

