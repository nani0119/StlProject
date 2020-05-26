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

void testFindEnd()
{

	PRINT_SPLIT_LINE("find_end");

	deque<int> di;
	list<int> li;
	INSERT_ELEMENTS(di,1,7);
	INSERT_ELEMENTS(di,1,7);
	INSERT_ELEMENTS(li,3,6);

	PRINT_ELEMENTS(di, "range:");
	PRINT_ELEMENTS(li, "subrange:");

	deque<int>::iterator end(di.end());
	auto pos = std::find_end(di.begin(), di.end(),
							  li.begin(), li.end()
					);
	while(pos != end)
	{
		cout << "subrange found starting with element "
			<< distance(di.begin(),pos) + 1
			<< endl;
		end = pos;

	    pos =std::find_end(di.begin(), end,
							  li.begin(), li.end()
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

void testAdjacentFind()
{

	PRINT_SPLIT_LINE("adjacent_find");

	deque<int> di = {1,2,3,4,4,7,8,9,18};

	PRINT_ELEMENTS(di, "range:");

	deque<int>::iterator pos;
	pos = std::adjacent_find(di.begin(), di.end());

	if (pos != di.end()) 
	{
		cout << "first two elements with equal value have position "
			<< distance(di.begin(),pos) + 1
			<< endl;
    }
	pos = std::adjacent_find(di.begin(), di.end(),
								[](const int& elem, const int& nextElem)
								{
									return 2*elem == nextElem;
								}	
							);

	if (pos != di.end()) 
	{
		cout << "first two elements with second value twice the "
			<< distance(di.begin(),pos) + 1
			<< endl;
    }
}

void testEqual()
{

	PRINT_SPLIT_LINE("equal");
	vector<int> vi;
	list<int> li;

	INSERT_ELEMENTS(vi, 1, 7);
	INSERT_ELEMENTS(li, 3, 9);

	PRINT_ELEMENTS(vi, "coll1:");
	PRINT_ELEMENTS(li, "coll2:");

	if(std::equal(vi.begin(), vi.end(), li.begin()))
	{
		cout << "coll1 == coll2" << endl;
	}
	else
	{
		cout << "coll1 != coll2" << endl;
	}
	
	auto fn = [](const int& e1, const int& e2)
				{
					return e1%2 == e2%2;
				};
	if(std::equal(vi.begin(), vi.end(), li.begin(),fn))
	{
		cout << "coll1 == coll2" << endl;
	}
	else
	{
		cout << "coll1 != coll2" << endl;
	}
}

void testPermutation()
{

	PRINT_SPLIT_LINE("is_permutation");
	vector<int> vi = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	list<int>   li = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	deque<int>  di = { 12, 13, 19, 18, 17, 16, 15, 14, 11 };

	PRINT_ELEMENTS(vi, "coll1: ");
	PRINT_ELEMENTS(li, "coll2: ");
	PRINT_ELEMENTS(di, "coll3: ");

	if(std::is_permutation(vi.begin(), vi.end(), li.begin()))
	{
		cout << "coll1 and coll2 have equal elements" << endl;
	}
	else
	{
		cout << "coll1 and coll2 don’t have equal elements" << endl;
	}

	auto fn = [](const int& e1, const int& e2)
				{
					//cout << e1 << "  :  " << e2 << endl << "----------------"<<endl;
					return e1%2 == e2%2;
				};
	
	if(std::is_permutation(vi.begin(), vi.end(), di.begin(),fn))
	{
		cout << "numbers of even and odd elements match" << endl;
	}
	else
	{
		cout << "numbers of even and odd elements don’t match" << endl;
	}
}

void testMismatch()
{
	PRINT_SPLIT_LINE("mismatch");
	vector<int> vi = { 1, 2, 3, 4, 5, 6 };
	list<int> li = { 1, 2, 4, 8, 16, 3 };

	PRINT_ELEMENTS(vi, "coll1:");
	PRINT_ELEMENTS(li, "coll2:");

	vector<int>::iterator vit;
	list<int>::iterator lit;

	std::tie(vit, lit) = std::mismatch(vi.begin(), vi.end(), li.begin());
	if(vit != vi.end())
	{
		cout << "first mismatch: "
			 << *vit << " and "
			 << *lit << endl;
	}

	std::pair<vector<int>::iterator, list<int>::iterator> value = std::mismatch(vi.begin(), vi.end(),
																	li.begin(),
																	std::less_equal<int>()
																	);
    if (value.first != vi.end())
	{
		cout << "not less-or-equal: "
			 << *value.first << " and "
			 << *value.second << endl;
	}
	
}

void testLexicographicalCompare()
{

	PRINT_SPLIT_LINE("lexicographical_compare");
	vector<int> vi;
	list<int> li;

	INSERT_ELEMENTS(vi, 1, 9);
	INSERT_ELEMENTS(li, 2, 10);

	PRINT_ELEMENTS(vi, "coll1:");
	PRINT_ELEMENTS(li, "coll2:");

	//note: us less<int>, so return true
	if(std::lexicographical_compare(vi.begin(), vi.end(), li.begin(), li.end()))
	{
		cout << "coll1 < coll2"<<endl;
	}

}

void testIsSorted()
{

	PRINT_SPLIT_LINE("lexicographical_compare");
	vector<int> vi;
	INSERT_ELEMENTS(vi, 1, 8);
	vi.push_back(7);

	PRINT_ELEMENTS(vi, "coll:");

	if(std::is_sorted(vi.begin(), vi.end()))
	{
		cout << "coll is sorted"<< endl;
	}
	else
	{
		cout << "coll is not sorted" << endl;
		auto it = std::is_sorted_until(vi.begin(), vi.end());
		cout << "unsort position:" << *it << endl;
	}
	auto fn = [](const int& e1 , const int& e2){ return e1 + 3 < e2;};
	if(std::is_sorted(vi.begin(), vi.end(), fn))
	{
		cout << "coll is sorted"<< endl;
	}
	else
	{
		cout << "coll is not sorted" << endl;
		auto it = std::is_sorted_until(vi.begin(), vi.end(), fn);
		cout << "unsort position:" << *it << endl;
	}
}

void testIsPartitioned()
{
	PRINT_SPLIT_LINE("is_partitioned");
	vector<int> vi;
	INSERT_ELEMENTS(vi, 1, 10);
	PRINT_ELEMENTS(vi, "coll1:");

	auto fn = [](const int& e, const int& c){return  e < c;};
	auto bfn = std::bind(fn, std::placeholders::_1, 5);

	if(std::is_partitioned(vi.begin(), vi.end(), bfn))
	{
		cout << "coll is partitioned,";
		auto it = std::partition_point(vi.begin(), vi.end(), bfn);
		cout << "   position:" << *it << endl;
	}

	vi.push_back(3);
	PRINT_ELEMENTS(vi, "coll2:");
	if(std::is_partitioned(vi.begin(), vi.end(), bfn))
	{

	}
	else
	{
		cout << "coll is not partitioned" << endl;
	}
}

void testIsHeap()
{
	PRINT_SPLIT_LINE("is_partitioned");
	vector<int> vi;
	INSERT_ELEMENTS(vi, 1, 10);
	PRINT_ELEMENTS(vi, "coll1:");

	auto fn = [](const int& e1, const int & e2) {return e1 % 2 == 1 && e2 % 2 == 0;};

	// heap from more ones to less ones 
	if(std::is_heap(vi.crbegin(), vi.crend()))
	{
		cout << "coll is heap" << endl;
	}

	if(std::is_heap(vi.begin(), vi.end(), fn))
	{

	}
	else
	{
		cout << "coll is not head,";
		auto it = std::is_heap_until(vi.begin(), vi.end(), fn);
		cout << "position: " << *it << endl;
	}
	
}

void testAllAnyNone()
{
	PRINT_SPLIT_LINE("is_partitioned");
	vector<int> vi;
	INSERT_ELEMENTS(vi, 1, 10);
	PRINT_ELEMENTS(vi, "coll1:");

	auto fn = [](const int& e, const int& i){ return e > i;};

	using namespace std::placeholders;
	if(std::all_of(vi.begin(), vi.end(), std::bind(fn, _1, 0)))
	{
		cout << "all of numbers is greater than 0" << endl;
	}

	if(std::any_of(vi.begin(), vi.end(), std::bind(fn, _1, 9)))
	{
		cout << "any of numbers is greater than 9" << endl;
	}

	if(std::none_of(vi.begin(), vi.end(), std::bind(fn, _1, 10)))
	{
		cout << "none of numbers is greater than 10" << endl;
	}
}

int main(int argc, char *argv[])
{
	testCount();
	testMinMax();
	testFind();
	testSearchN();
	testSearch();
	testFindFirstOf();
	testFindEnd();
	testAdjacentFind();
	testEqual();
	testPermutation();
	testMismatch();
	testLexicographicalCompare();	
	testIsSorted();
	testIsPartitioned();
	testIsHeap();
	testAllAnyNone();	
	return 0;
}
