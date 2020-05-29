#include "algostuff.h"

using namespace std;

void testReverse()
{
    PRINT_SPLIT_LINE("reverse");
    vector<int> vi(9);
    std::iota(vi.begin(), vi.end(), 1);
    PRINT_ELEMENTS(vi, "source:");
    cout << "reverse copy:";
    std::reverse_copy(vi.begin(), vi.end(),
                    ostream_iterator<int>(cout, " ")
                    );

    cout << endl;
    std::reverse(vi.begin(), vi.end());
    PRINT_ELEMENTS(vi, "reverse     :");
}

void testRotating()
{
    PRINT_SPLIT_LINE("rotate&rotate_copy");
    vector<int> vi(9);
    std::iota(vi.begin(), vi.end(), 1);
    PRINT_ELEMENTS(vi,"origin:");
    vector<int>::iterator pos;
    pos = std::rotate(vi.begin(), std::next(vi.begin()), vi.end());
    if(pos == vi.end()-1)
    {
        cout << "pos == vi.end() - 1:"<< *pos << endl;   
    }
    PRINT_ELEMENTS(vi, "left rotate:");

    pos = vi.end();
    std::advance(pos, -2);
    pos = std::rotate(vi.begin(), pos, vi.end());
    PRINT_ELEMENTS(vi, "right rotate:");
    cout << "pos: " << *pos << endl;

    deque<int> di(9);
    auto pos1 = std::rotate_copy(vi.begin(), vi.begin() + 1, vi.end(), di.begin());
    PRINT_ELEMENTS(di, "left rotate copy:");
    if(pos1 == di.end())
    {
        cout << "pos1 == di.end()" << endl;
    }
}

// 从当前序列到满足升序（ｎｅｘｔ）或者降序（ｐｒｅｖ）为止
void testPermutation()
{
    PRINT_SPLIT_LINE("next_permutation&prev_permutation");

    vector<int> vi = {1,2,3};
    PRINT_ELEMENTS(vi, "origin:");
    // next_xxxxx 从当前序列开始直到满足完全升序为止
    // 所以如果想列出所有序列组合，先让容器按升序排列
    while(std::next_permutation(vi.begin(), vi.end()))
    {
        PRINT_ELEMENTS(vi);
    }
    PRINT_ELEMENTS(vi, "afterwards:");

    
    cout << "prev_permutation:"<<endl;
    PRINT_ELEMENTS(vi, "origin:");
    while(std::prev_permutation(vi.begin(), vi.end()))
    {

        PRINT_ELEMENTS(vi);
    }
    PRINT_ELEMENTS (vi, "afterwards:");
}


class MyRand
{
    public:
        std::ptrdiff_t operator()(std::ptrdiff_t max)
        {
            double tmp = static_cast<double>(rand())/static_cast<double>(RAND_MAX);
            return static_cast<ptrdiff_t>(tmp*max);
        }

};
#include <cstdlib>
#include <random>

void testShuffle()
{
    PRINT_SPLIT_LINE("shuttfle");
    vector<int> vi(9);
    std::iota(vi.begin(), vi.end(), 1);
    PRINT_ELEMENTS(vi, "origin        :");
    std::random_shuffle(vi.begin(), vi.end());
    PRINT_ELEMENTS(vi, "random_shuffle:");

    MyRand rd;
    std::random_shuffle(vi.begin(), vi.end(),rd);
    PRINT_ELEMENTS(vi, "random_shuffle:");

    // shuffle elements with default engine
    default_random_engine dre;
    std::shuffle(vi.begin(), vi.end(), dre);
    PRINT_ELEMENTS(vi,  "shuffle       :");
}

void testPartition()
{
    PRINT_SPLIT_LINE("partition");
    vector<int> vi1;
    vector<int> vi2;
    INSERT_ELEMENTS(vi1, 1, 9);
    INSERT_ELEMENTS(vi2, 1, 9);

    PRINT_ELEMENTS(vi1, "coll1:");
    PRINT_ELEMENTS(vi2, "coll2:");

    auto fn = [](const int& e){return e % 2 == 0;};
    auto pos1 = std::partition(vi1.begin(), vi1.end(), fn);
    auto pos2 = std::stable_partition(vi2.begin(), vi2.end(), fn);
    PRINT_ELEMENTS(vi1, "partition       :");
    cout << "pos:" << *pos1 << endl;
    PRINT_ELEMENTS(vi2, "stable_partition:");
    cout << "pos:" << *pos2 << endl;

    vector<int> vi3;
    INSERT_ELEMENTS(vi3,1,9);
    PRINT_ELEMENTS(vi3,"origin:");
    deque<int> di(9);
    vector<int> vit;
    vector<int> vif;
    std::partition_copy(vi3.begin(), vi3.end(), 
                                        back_inserter(vit), back_inserter(vif),
                                        fn);
    PRINT_ELEMENTS(vit, "even:");
    PRINT_ELEMENTS(vif, "odd :");

    std::partition_copy(vi3.begin(), vi3.end(),
                        back_inserter(di), front_inserter(di),
                        fn);
    PRINT_ELEMENTS(di, "partition:");

}

int main(int argc, char const *argv[])
{
    testReverse();
    testRotating();
    testPermutation();
    testShuffle();
    testPartition();
    return 0;
}