#include "algostuff.h"

using namespace std;

void testBinarySearch()
{
    PRINT_SPLIT_LINE("binary_search");
    list<int> li;
    INSERT_ELEMENTS(li, 1, 9);
    INSERT_ELEMENTS(li, 1, 9);
    li.sort();
    PRINT_ELEMENTS(li, "origin:");

    if(std::binary_search(li.begin(), li.end(), 7))
    {
        cout << "7 was found in list" << endl;
    }

    //func: the value returned indicates whether the first argument is considered to go before the second
    if(std::binary_search(li.begin(), li.end(), 7, [](const int& e1, const int& e2){cout << e1 << " : " << e2 << endl; return e1 < e2;}))    
    {
        cout << "found" << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
}

void testIncludes()
{
    PRINT_SPLIT_LINE("includes");
    list<int> li;
    INSERT_ELEMENTS(li, 1, 9);
    li.sort();
    PRINT_ELEMENTS(li, "origin:");

    vector<int> vi = {7, 3};

    std::sort(vi.begin(), vi.end());
    PRINT_ELEMENTS(vi, "sub range:");

    bool ret = std::includes(li.begin(), li.end(), vi.begin(), vi.end());
    if(ret)
    {
        cout << "vi is found in li" << endl;
    }
    else
    {
        cout << "vi is not found in li" << endl;
    }    
}

void testBounds()
{
    PRINT_SPLIT_LINE("bounds");
    list<int> li;
    INSERT_ELEMENTS(li, 1, 9);
    INSERT_ELEMENTS(li, 1, 9);
    li.sort();
    li.erase(std::find(li.begin(), li.end(), 5));
    li.erase(std::find(li.begin(), li.end(), 5));
    PRINT_ELEMENTS(li, "origin:");

    list<int>::iterator lowwer_pos = std::lower_bound(li.begin(), li.end(), 5);
    cout << "lowwer bound:distance:" << std::distance(li.begin(), lowwer_pos) + 1<< " value: " << *lowwer_pos << endl;
    

    list<int>::iterator upper_pos = std::upper_bound(li.begin(), li.end(), 7);
    cout << "upper bound:distance:" << std::distance(li.begin(), upper_pos) + 1<< " value: " << *upper_pos << endl;


    pair<decltype(lowwer_pos), decltype(upper_pos)> pair_pos = std::equal_range(li.begin(), li.end(), 5);
    cout << "distance for 5  [" <<  distance(li.begin(), pair_pos.first) + 1 << ", " <<  distance(li.begin(), pair_pos.second) + 1 << "]" << endl;
    cout << "value: "  << *pair_pos.first << "," << *pair_pos.second << endl;

    
    pair_pos = std::equal_range(li.begin(), li.end(), 7);
    cout << "distance for 7  [" <<  distance(li.begin(), pair_pos.first) + 1 << ", " <<  distance(li.begin(), pair_pos.second) + 1 << "]" << endl;
    cout << "value: "  << *pair_pos.first << "," << *pair_pos.second << endl;
}

void testMerge()
{
    PRINT_SPLIT_LINE("merge");
    vector<int> vi;
    INSERT_ELEMENTS(vi, 1, 5);

    deque<int> di;
    INSERT_ELEMENTS(di, 4, 8);

    cout << "merge:";
    std::merge(vi.begin(), vi.end(),
                di.begin(), di.end(),
                    ostream_iterator<int>(cout, " ")
                    );
    cout << endl;
}

void testSetOperation()
{
    PRINT_SPLIT_LINE("set_xxxxxx");

    vector<int> c1 = { 1, 2, 2, 4, 6, 7, 7, 9 };
    deque<int>  c2 = { 2, 2, 2, 3, 6, 6, 8, 9 };

    PRINT_ELEMENTS(c1, "c1                         :");
    PRINT_ELEMENTS(c2, "c2                         :");

    cout << "merge                      :";
    std::merge(c1.begin(), c1.end(),
                c2.begin(), c2.end(),
                   ostream_iterator<int>(cout, " "));
    cout << endl;

    cout << "set_union                  :";
    std::set_union(c1.begin(), c1.end(),
                    c2.begin(), c2.end(),
                        ostream_iterator<int>(cout, " ")
                        );
    cout << endl;

    cout << "set_inersection            :";
    std::set_intersection(c1.begin(), c1.end(),
                            c2.begin(), c2.end(),
                            ostream_iterator<int>(cout, " ")
                            );
    cout << endl;

    cout << "set_difference             :";
    std::set_difference(c1.begin(), c1.end(),
                            c2.begin(), c2.end(),
                            ostream_iterator<int>(cout, " ")
                            );
    cout << endl;

    cout << "set_symmetric_difference   :";
    std::set_symmetric_difference(c1.begin(), c1.end(),
                                    c2.begin(), c2.end(),
                                        ostream_iterator<int>(cout, " ")
                                );
    cout << endl;
}


void testInplaceMerge()
{
    PRINT_SPLIT_LINE("inplace_merge:");
    vector<int> vi;
    INSERT_ELEMENTS(vi, 1, 7);
    INSERT_ELEMENTS(vi, 1, 9);
    PRINT_ELEMENTS(vi, "origin       :");

    auto pos = std::find(vi.begin(), vi.end(), 7);
    std::advance(pos, 1);
    std::inplace_merge(vi.begin(), pos, vi.end());
    PRINT_ELEMENTS(vi,"inplace_merge:");

}
int main(int argc, char const *argv[])
{
    testBinarySearch(); 
    testIncludes();
    testBounds();
    testMerge();
    testSetOperation();
    testInplaceMerge();
    return 0;
}
