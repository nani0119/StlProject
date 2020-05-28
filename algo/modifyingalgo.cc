#include "algostuff.h"

using namespace std;

int testCopy()
{
    PRINT_SPLIT_LINE("copy");
    vector<int> vi;
    INSERT_ELEMENTS(vi, 2, 9);
    PRINT_ELEMENTS(vi, "source           :");

    list<int> li(vi.size(), 0);
    li.push_front(1);
    li.push_front(1);
    PRINT_ELEMENTS(li, "dest-orgi        :");
    std::copy(vi.begin(), vi.end(), li.begin());
    PRINT_ELEMENTS(li, "dest-copy        :");

    std::fill(li.begin(), li.end(), 0);
    *(li.begin()) = 1;
    *(std::next(li.begin())) = 1;
    PRINT_ELEMENTS(li, "dest-orgi        :");
    std::copy_backward(vi.begin(), vi.end(), li.end());
    PRINT_ELEMENTS(li, "des-copy-backward:");

    cout <<            "dest-copy-if     :";
    std::copy_if(vi.begin(), vi.end(),
                    ostream_iterator<int>(cout, " "),
                    [](const int& e) {return e%2 == 0;}
                    );
    cout << endl; 
    cout <<            "dest-copy-n      :";
    std::copy_n(vi.begin(), 
                    vi.size(),
                    ostream_iterator<int>(cout, " ")
                );
    cout << endl;
    return 0;
}

void testMove()
{
    PRINT_SPLIT_LINE("move");
    vector<int> vi;
    INSERT_ELEMENTS(vi, 1 ,9);
    list<int> li;
    li.resize(vi.size());
    PRINT_ELEMENTS(vi, "coll:");
    std::move_backward(vi.begin(), vi.end(), li.end());
    std::move(li.begin(), li.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
}

void testTransform()
{
    PRINT_SPLIT_LINE("transform");
    deque<int> di;
    INSERT_ELEMENTS(di, 1, 9);
    PRINT_ELEMENTS(di, "origin   : ");

    std::transform(di.begin(), di.end(),
                    di.begin(),
                    bind(plus<int>(),std::placeholders::_1, 1)
                    );
    PRINT_ELEMENTS(di, "transform: ");

    std::transform(di.begin(), di.end(),
                    di.begin(),
                    di.begin(),
                    std::multiplies<int>()
                   );
    PRINT_ELEMENTS(di, "transform: ");
}

void testSwapRange()
{
    PRINT_SPLIT_LINE("swap_ranges");
    vector<int> vi;
    deque<int> di;
    INSERT_ELEMENTS(vi, 1, 9);
    INSERT_ELEMENTS(di, 11, 22);

    PRINT_ELEMENTS(vi, "source:");
    PRINT_ELEMENTS(di, "dest:");
    
    deque<int>::iterator pos;
    pos = std::swap_ranges(vi.begin(), vi.end(),
                            di.begin());
    PRINT_ELEMENTS(vi, "new source:");
    PRINT_ELEMENTS(di, "new dest:");

    if(pos != di.end())
    {
        cout << "first element after swap ranges:" << *pos << endl;
    }

    std::swap_ranges(di.begin(), di.begin()+3,
                        di.rbegin());
    PRINT_ELEMENTS(di, "swap head and tail:");

}
#include <cstdlib>
void testAssignNewValue()
{
    PRINT_SPLIT_LINE("fill&generate&iota");
    std::fill_n(ostream_iterator<float>(cout, " "), 5, 7.7);
    cout << endl;

    vector<int> vi(10);
    std::fill(vi.begin(), vi.end(), 6);
    PRINT_ELEMENTS(vi);

    deque<int> di(10);
    std::generate(di.begin(),di.end(), []() ->int {return rand();});
    PRINT_ELEMENTS(di);

    std::generate_n(ostream_iterator<int>(cout, " "), 10, rand);
    cout << endl;
    
    std::iota(di.begin(), di.end(), -1);
    PRINT_ELEMENTS(di);
}

void testReplace()
{
    PRINT_SPLIT_LINE("replace");
    vector<int> vi;
    INSERT_ELEMENTS(vi, 2, 7);
    INSERT_ELEMENTS(vi, 4, 10);
    PRINT_ELEMENTS(vi, "origin:");
    std::replace(vi.begin(), vi.end(), 6, 8);
    PRINT_ELEMENTS(vi, "replace:");

    std::replace_if(
        vi.begin(), vi.end(),
        [](const int &e) -> bool { return e % 2 == 0; },
        0);
    PRINT_ELEMENTS(vi, "replace_if:");

    std::iota(vi.begin(), vi.end(), 1);
    PRINT_ELEMENTS(vi, "origin:");
    std::replace_copy(vi.begin(), vi.end(),
                      ostream_iterator<int>(cout, " "),
                      3,
                      0);
    cout << endl;
    PRINT_ELEMENTS(vi, "source:");

    cout << "replace_copy_if:";

    std::replace_copy_if(
        vi.begin(), vi.end(), ostream_iterator<int>(cout, " "),
        [](const int &e) { return e % 2 == 1; },
        0);
    cout << endl;
}
int main(int argc, char const *argv[])
{
    testCopy();
    testMove();
    testTransform();
    testSwapRange();
    testAssignNewValue();
    testReplace();
    return 0;
}
