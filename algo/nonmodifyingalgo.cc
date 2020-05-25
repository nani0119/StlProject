#include "algostuff.h"

using namespace std;

void testCount()
{
	PRINT_SPLIT_LINE("count&&count_if");	
	vector<int> vi;
	INSERT_ELEMENTS(vi, 1, 9);
	PRINT_ELEMENTS(vi,"vector:");

	std::iterator_traits<vector<int>::iterator>::difference_type num;
    num = std::count(vi.begin(), vi.end(), 4);
	cout << "number of elements equal to 4:         " << num << endl;	

	num = std::count_if(vi.begin(), vi.end(), [](std::iterator_traits<vector<int>::iterator>::value_type i)
												{
													return i > 4;
												}
					   );
	cout << "number of elements greater than 4:     " << num << endl;

	num = std::count_if(vi.begin(), vi.end(),
						std::bind(std::logical_not<bool>(),
									std::bind(std::modulus<int>(), std::placeholders::_1, 2))
						);

	cout << "number of elements with even value:    " << num << endl;

}

#include <cstdlib>
void testMinMax()
{
	PRINT_SPLIT_LINE("min&&max");

	vector<int> vi;
	INSERT_ELEMENTS(vi, 2, 6);
	INSERT_ELEMENTS(vi, -3, 6);

	PRINT_ELEMENTS(vi,"vector:");


	vector<int>::iterator minIt;
	vector<int>::iterator maxIt;
	std::pair<decltype(minIt), decltype(maxIt)> minMaxItPair;

	minIt = std::min_element(vi.begin(), vi.end());
	maxIt = std::max_element(vi.begin(), vi.end());
	minMaxItPair = std::minmax_element(vi.begin(), vi.end(),
									[](const int& e1, const int& e2)
										{
											return std::abs(e1) < std::abs(e2);
										}
								);

	cout << "minimum:        " << *minIt << endl;
	cout << "maximum:        " << *maxIt <<"        distance: " << std::distance(vi.begin(), maxIt) << endl;
	cout << "min-max:"<< endl;
	cout << "-min:           " << *(minMaxItPair.first) << endl;
	cout << "-max:           " << *(minMaxItPair.second) <<"        distance: " << std::distance(vi.begin(), minMaxItPair.second) <<endl;
}

void testFind()
{
	PRINT_SPLIT_LINE("find&&find_if&&find_if_not");

	list<int> li;
	INSERT_ELEMENTS(li, 1, 9);
	INSERT_ELEMENTS(li, 1, 9);

	PRINT_ELEMENTS(li, "list:");

	list<int>::iterator pos1;
	list<int>::iterator pos2;
	pos1 = std::find(li.begin(), li.end(), 4);
	if(pos1 != li.end())
	{
		pos2 = std::find(std::next(pos1), li.end(), 4);
	}
	cout << "between 4 and 4:           ";

	if(pos1 != li.end() && pos2 != li.end())
	{
		std::copy(pos1, std::next(pos2),
				  	std::ostream_iterator<int>(cout," ")
				  );
	}
	cout << endl;

	auto pos = std::find_if(li.begin(), li.end(), 
								std::bind(std::greater<int>(), std::placeholders::_1, 5)
							);
	cout << "greater than 5:            " << *pos << "  distance:" << std::distance(li.begin(), pos) << endl;


	pos = std::find_if_not(li.begin(), li.end(),
							[=](const int& i )
							{
								return i < *pos; 
							}
			);
	cout << "not greater than 5:        " << *pos << "  distance:" << std::distance(li.begin(), pos) << endl;
	cout << endl;
	
}

void testSearchN()
{

	PRINT_SPLIT_LINE("search_n");

	deque<int> di = {1,3,2,3,3,7,7,8,8,3,3,3,3,6,8,8,8,9,0};
	PRINT_ELEMENTS(di, "deque:");

	deque<int>::iterator pos;
	pos = std::search_n(di.begin(), di.end(), 4, 3);
	if(pos != di.end())
	{
		cout << "first four consecutive 3 ,start postion:        " << std::distance(di.begin(), pos) + 1 << endl;
	}

	pos = std::search_n(di.begin(), di.end(), 3, 8,
						[](const int& i, int value)
						{
							cout << value << endl;
							return i % 2 == 0;
						}
			);
	if(pos != di.end())
	{
		cout << "first three consecutive even, start postion:    " << std::distance(di.begin(), pos) + 1 << endl;
	}
}

void testSearch()
{
	
	PRINT_SPLIT_LINE("search");

	deque<int> di;
	list<int> li;
	INSERT_ELEMENTS(di,1,7);
	INSERT_ELEMENTS(di,1,7);
	INSERT_ELEMENTS(li,3,6);

	PRINT_ELEMENTS(di, "range:");
	PRINT_ELEMENTS(li, "subrange:");

	deque<int>::iterator pos;
	pos = std::search(di.begin(), di.end(),
					  li.begin(), li.end());
	while(pos != di.end())
	{
		cout << "subcoll found starting with element "
			<< distance(di.begin(),pos) + 1
			<< endl;
		++pos;
		pos = std::search(pos, di.end(),
					li.begin(), li.end());
	}

	PRINT_SPLIT_LINE("search(op)");
	bool checkEvenArgs[3] = { true, false, true };
	cout <<std::boolalpha <<"check pattern: " << "even odd even"<< endl;


	auto fn =  [](const int& e, bool even)
					  {
							if(even)
							{
								return e % 2 == 0;
							}
							else
							{
								return e % 2 == 1;
							}
					  };
	pos = std::search(di.begin(), di.end(),
					  checkEvenArgs, checkEvenArgs+3,
					  fn
				  );

	while(pos != di.end())
	{
		cout << "subcoll found starting with element "
			<< distance(di.begin(),pos) + 1
			<< endl;
		++pos;
		pos = std::search(pos, di.end(),
				checkEvenArgs, checkEvenArgs+3,
				fn
			);
	}

}

void testFindFirstOf()
{

	PRINT_SPLIT_LINE("find_first_of");

	deque<int> di;
	list<int> li = {3,6};
	INSERT_ELEMENTS(di,1,7);
	INSERT_ELEMENTS(di,1,7);

	PRINT_ELEMENTS(di, "range:");
	PRINT_ELEMENTS(li, "subrange:");

	deque<int>::iterator pos;
	pos = std::find_first_of(di.begin(), di.end(),
			li.begin(), li.end());

	cout << "first element of searchcoll in coll is element "
		<< distance(di.begin(),pos) + 1
		<< endl;

	auto rpos = find_first_of (di.rbegin(), di.rend(), // range
			li.begin(), // beginning of search set
			li.end()); // end of search set

	cout << "last element of searchcoll in coll is element "
		<< distance(di.begin(),rpos.base())
		<< endl;
}

int main(int argc, char *argv[])
{
	testCount();
	testMinMax();
	testFind();
	testSearchN();
	testSearch();
	testFindFirstOf();
	return 0;
}
