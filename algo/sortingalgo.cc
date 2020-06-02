#include "algostuff.h"

using namespace std;

void testSort()
{
    PRINT_SPLIT_LINE("sort&&stable_sort");
    vector<int> source;
    INSERT_ELEMENTS(source, 1, 9);
    source.push_back(2);
    source.push_back(2);
    INSERT_ELEMENTS(source, 1, 9);
    PRINT_ELEMENTS(source,"origin       :");

    auto fn = [](const int& e1, const int& e2){if(e1%2 == 0 && e2%2==1){return true;} return false;};

    deque<int> di1;
    std::copy(source.begin(), source.end(), back_inserter(di1));
    std::sort(di1.begin(), di1.end(),fn);
    PRINT_ELEMENTS(di1, "sorted       :");
    
    deque<int> di2;
    std::copy(source.begin(), source.end(), back_inserter(di2));
    std::stable_sort(di2.begin(), di2.end(),fn);
    PRINT_ELEMENTS(di2, "stable sorted:");
}

void testPartialSort()
{
    PRINT_SPLIT_LINE("partial_sort");
    deque<int> di;
    INSERT_ELEMENTS(di,3,7);
    INSERT_ELEMENTS(di,2,6);
    INSERT_ELEMENTS(di,1,5);
    PRINT_ELEMENTS(di,"origini     :");

    auto pos = di.begin();
    std::advance(pos, 6);
    std::partial_sort(di.begin(), pos, di.end());
    PRINT_ELEMENTS(di, "partial_sort:");
}

void testPartialSortCopy()
{
    PRINT_SPLIT_LINE("partital sort copy");   
    deque<int> di;
    INSERT_ELEMENTS(di,3,7);
    INSERT_ELEMENTS(di,2,6);
    INSERT_ELEMENTS(di,1,5);
    PRINT_ELEMENTS(di, "origin:");

    vector<int> vs(di.size()/2);
    vector<int> vq(di.size());
    vector<int> vb(di.size()*2);

    std::partial_sort_copy(di.begin(), di.end(), vs.begin(), vs.end());
    std::partial_sort_copy(di.begin(), di.end(), vq.begin(), vq.end());
    std::partial_sort_copy(di.begin(), di.end(), vb.begin(), vb.end());
    PRINT_ELEMENTS(vs, "vs    :");
    PRINT_ELEMENTS(vq, "vq    :");
    PRINT_ELEMENTS(vb, "vb    :");
}

void testNthElement()
{
    PRINT_SPLIT_LINE("nth_element");
    deque<int> di;
    INSERT_ELEMENTS(di,3,7);
    INSERT_ELEMENTS(di,2,6);
    INSERT_ELEMENTS(di,1,5);
    PRINT_ELEMENTS(di, "origin     :");

    auto pos = di.begin();
    std::advance(pos,5);
    std::nth_element(di.begin(), pos, di.end());
    PRINT_ELEMENTS(di, "nth element:");

    std::sort(di.begin(), di.end());
    PRINT_ELEMENTS(di, "sorted     :");
}

void testHeap()
{
    PRINT_SPLIT_LINE("heap");
    vector<int> vi;
    INSERT_ELEMENTS(vi, 2,6);
    INSERT_ELEMENTS(vi, 1,6);
    vi.push_back(9);

    PRINT_ELEMENTS(vi, "origin   :");
    std::make_heap(vi.begin(), vi.end());
    PRINT_ELEMENTS(vi, "make heap:");

    std::pop_heap(vi.begin(), vi.end());
    PRINT_ELEMENTS(vi, "pop heap :");
    cout << "back     :" << vi.back() << endl;
    vi.pop_back();
    PRINT_ELEMENTS(vi, "pop back :");

    vi.push_back(10);
    std::push_heap(vi.begin(), vi.end());
    PRINT_ELEMENTS(vi, "push heap:");

    std::sort_heap(vi.begin(), vi.end());
    PRINT_ELEMENTS(vi, "sort heap:");
}

int main(int argc, char const *argv[])
{
    testSort();
    testPartialSort();
    testPartialSortCopy();
    testNthElement();
    testHeap();
    return 0;
}
