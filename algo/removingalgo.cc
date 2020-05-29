#include "algostuff.h"
using namespace std;

void testRemoving()
{
    PRINT_SPLIT_LINE("remove&remove_if");
    int source[] = {2, 3, 4, 5, 6, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7};
    vector<int> vi;
    std::copy(begin(source), end(source), back_inserter(vi));
    PRINT_ELEMENTS(vi, "source:");

    vector<int>::iterator pos;
    pos = std::remove(vi.begin(), vi.end(), 4);
    PRINT_ELEMENTS(vi, "size is not changed:");
    vi.erase(pos, vi.end());
    cout << "size is changed:";
    std::copy(vi.begin(), vi.end(), 
                ostream_iterator<int>(cout, " ")
            );
    cout << endl;

    cout << "all odds:";
    std::copy(vi.begin(), std::remove_if(vi.begin(), vi.end(), [](const int& e){return e % 2 == 1;}),
                ostream_iterator<int>(cout, " ")
                );
    cout << endl;

    vi.clear();
    std::copy(begin(source), end(source), back_inserter(vi));
    PRINT_ELEMENTS(vi, "source:");
    deque<int> di;
    std::remove_copy(vi.begin(), vi.end(), back_inserter(di), 4);
    PRINT_ELEMENTS(di, "remove copy:");

    cout << "remove copy if:";
    std::remove_copy_if(di.begin(), di.end(), ostream_iterator<int>(cout ," "), [](const int& e){return e > 4;});
    cout << endl;

}

void testUnique()
{
    PRINT_SPLIT_LINE("unique");
    int source[] = {1, 4, 4, 6, 1, 2, 2, 3, 1, 6, 6, 6, 5, 7,
                    5, 4, 4};
    list<int> coll;
    std::copy(begin(source), end(source), back_inserter(coll));
    PRINT_ELEMENTS(coll, "source");

    auto pos = std::unique(coll.begin(), coll.end());
    coll.erase(pos, coll.end());
    PRINT_ELEMENTS(coll, "unique   :");

    pos = std::unique(coll.begin(), coll.end(), [](const int& e, const int& element){return e - 1 == element || e + 1 == element;});
    PRINT_ELEMENTS(coll, "unique op:");


    cout << "filter space from cin:" << endl;
    // don’t skip leading whitespaces by default
    cin.unsetf(ios::skipws);
    auto fn = [](const char& elem1, const char& elem2){ return elem1 == ' ' && elem2 == ' ';};
    std::unique_copy(istream_iterator<char>(cin), istream_iterator<char>(),
                        ostream_iterator<char>(cout),
                        fn
                    );

}


int main(int argc, char const *argv[])
{
    testRemoving();
    testUnique();
    return 0;
}
