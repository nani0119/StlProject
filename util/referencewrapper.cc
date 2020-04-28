#include <iostream>
#include <functional>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	int i = 10;

	/// ref() ---> reference_wrapper<>
	std::reference_wrapper<int> ri = std::ref(i);

	i++;

	cout << "i = " << i << endl;
	cout << "ri = " << ri << endl;


	int j = 100;
	
	// vector<int&> vri;  /// error, container can not include reference
	vector<std::reference_wrapper<int>> vri;
	vri.push_back(std::ref(j));
	vri.push_back(ri);

	j++;
	i++;

	cout << "vri:" ;
	for(auto it = vri.begin(); it != vri.end(); it++)
	{
		cout << it->get() <<" " ;
	}
	cout << endl;
	return 0;
}
