#include <ratio>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
	cout << "##############################################" << endl;
	typedef std::ratio<5,3> FiveThirds;
	cout << FiveThirds::num <<"/" << FiveThirds::den << endl;

	cout << std::ratio<10, 6>::num << "/" << std::ratio<10,6>::den << endl;
	cout << std::boolalpha;


	cout << "5/3 == 10/6:"<< std::ratio_equal<FiveThirds,std::ratio<10,6>>::value<<endl; 

	std::ratio_add<FiveThirds, std::ratio<10,6>>::type ratioAdd;
	cout<<"5/3+10/6 = " << ratioAdd.num << "/" << ratioAdd.den << endl;

	cout << "5/3 - 10/6 = " << std::ratio_subtract<FiveThirds, std::ratio<10,6>>::num << "/" << std::ratio_subtract<FiveThirds, std::ratio<10,6>>::den << endl;

	typedef std::ratio_subtract<std::ratio<5>, std::ratio<3>>::type FiveSubThree;
	cout<< "5/1 - 3/1 = " << FiveSubThree::num <<"/" <<FiveSubThree::den << endl;
	
	return 0;
}
