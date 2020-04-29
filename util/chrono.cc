#include <iostream>
#include <ratio>
#include <chrono>
#include <type_traits>
#include "util_chrono_duration.h"
#include "util_type_traits.h"
using namespace std;


struct DurationTest
{
	void testDuration()
	{
		cout << "########################################################"<<endl;
		std::chrono::microseconds ms1(20);
		cout <<"ms1:"<< ms1 << endl;



		std::chrono::seconds s1(20);
		// duration == val + unit
		// unit == ratio<>
		std::chrono::duration<std::chrono::seconds::rep, std::ratio<1,1>> s2(20);
		// std::chrono::duration<long, std::ratio<1,1>> s2(20);
		// checkTraitsType<std::chrono::seconds::rep>();
		cout <<"s1:"<< s1<<endl;
		cout <<"s2:"<< s2<<endl;

		cout << std::boolalpha;
		cout << "s1 is the same as s2:" << std::is_same<decltype(s1), decltype(s2)>::value << endl;

		std::chrono::microseconds ms2 = ms1 + s2;
		cout <<"ms2:"<< ms2 <<endl;
		cout <<"s1 - ms2 = " << (s1 -ms2) << endl;

		cout << "ms1 * 3 = " << (ms1 * 3) << endl;

		cout << "ms2 % std::chrono::seconds(1) = " << (ms1 % std::chrono::seconds(1)) << endl;

		cout << "std::duration_cast<std::chrono::seconds>(ms2) = " << std::chrono::duration_cast<std::chrono::seconds>(ms2) << endl;


		// convert time to HH MM SS
		std::chrono::milliseconds msec(17255042);

		std::chrono::hours hh = std::chrono::duration_cast<std::chrono::hours>(msec);
		cout << "hh:" << hh.count()<<endl;
		
		std::chrono::minutes mm = std::chrono::duration_cast<std::chrono::minutes>(msec % std::chrono::hours(1));
		cout << "mm:" << mm.count()<<endl;
		std::chrono::seconds ss = std::chrono::duration_cast<std::chrono::seconds>(msec % std::chrono::minutes(1));
		cout << "ss:" << ss.count()<<endl;
		std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>(msec % std::chrono::seconds(1));
		cout << "ms:" << ms.count()<<endl;

	}
};

int main(int argc, char *argv[])
{
	DurationTest dt;
	dt.testDuration();
	
	return 0;
}
