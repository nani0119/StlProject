#include <memory>
#include <vector>
#include <iostream>
#include "util_type_traits.h"
using namespace std;

class MyClass
{
	public:
		MyClass():data(0)
		{
		}
		int getData()
		{
			return data;
		}
		int data;
};

void testCheckTraitsType()
{
	checkTraitsType<int>();
	checkTraitsType<void>();
	checkTraitsType<int[]>();
	checkTraitsType<MyClass>();
	checkTraitsType<decltype(&MyClass::getData)>();
	checkTraitsType<decltype(&MyClass::data)>();
}

void testCheckClassTraitsType()
{
	checkClassTraitsType<MyClass>();
}

void testCheckRelationTraitsType()
{
	checkRelationTraitsType<MyClass, MyClass>();
}

void testCheckInitTraitsType()
{
	checkInitTraitsType<MyClass, float, int>();
}

void testCheckAllocTraitsType()
{
	checkAllocTraitsType<MyClass, std::allocator<int>>();
	checkAllocTraitsType<std::vector<int>, std::allocator<int>>();
}

void testModifyTraitsType()
{
	typedef int Int;
	cout << "######################################################################" << endl;
	cout << __func__<<":" << endl;
	checkTraitsType<std::add_const<Int>::type>();
	checkTraitsType<std::add_volatile<Int>::type>();
	checkTraitsType<std::add_cv<Int>::type>();

	typedef const int CInt;
	typedef volatile int VInt;
	typedef const volatile int CVInt;
	checkTraitsType<std::remove_const<CInt>::type>();
	checkTraitsType<std::remove_volatile<VInt>::type>();
	checkTraitsType<std::remove_cv<CVInt>::type>();

	typedef unsigned int UInt;
	checkTraitsType<std::make_unsigned<Int>::type>();
	checkTraitsType<std::make_signed<UInt>::type>();

	typedef int& RInt;
	checkTraitsType<std::remove_reference<RInt>>();

	checkTraitsType<std::add_lvalue_reference<Int>::type>();
	checkTraitsType<std::add_rvalue_reference<Int>::type>();

	typedef int*  PInt;
	checkTraitsType<std::remove_pointer<PInt>::type>();

	checkTraitsType<std::add_pointer<Int>::type>();
}

void testArrayDimension()
{
	cout << "######################################################################" << endl;

	cout << __func__<<":" << endl;
	cout << std::rank<int>::value << endl;      // 0
	cout << std::rank<int[]>::value << endl;    // 1
	cout << std::rank<int[5]>::value << endl;   // 1
	cout << std::rank<int[][7]>::value << endl; // 2

	cout << std::extent<int>::value << endl;        // 0
	cout << std::extent<int[]>::value << endl;      // 0
	cout << std::extent<int[5]>::value << endl;     // 5
	cout << std::extent<int[][7],1>::value << endl; // 7

	typedef std::remove_extent<int>::type A;                // int
    typedef std::remove_extent<int[24]>::type B;            // int
    typedef std::remove_extent<int[24][60]>::type C;        // int[60]
    typedef std::remove_extent<int[][60]>::type D;          // int[60]
    typedef std::remove_all_extents<int[][60]>::type E;     // int
    typedef std::remove_all_extents<const int[10]>::type F; //const int

	cout << std::boolalpha<<endl;
    std::cout << "A: " << std::is_same<int,A>::value << std::endl;
    std::cout << "B: " << std::is_same<int,B>::value << std::endl;
    std::cout << "C: " << std::is_same<int[60],C>::value << std::endl;
    std::cout << "D: " << std::is_same<int[60],D>::value << std::endl;
    std::cout << "E: " << std::is_same<int,E>::value << std::endl;
    std::cout << "F: " << std::is_same<const int,F>::value << std::endl;
}


void testEnumUnderlyingType()
{
	cout << "######################################################################" << endl;
	cout << __func__<<":" << endl;
	cout << std::boolalpha<<endl;

	enum A: int {a,b,c};
	enum B  {x,y,z};
	enum class C  {cx,cy,cz};
	typedef std::underlying_type<A>::type AUnderlying;
	typedef std::underlying_type<B>::type BUnderlying;
	typedef std::underlying_type<C>::type CUnderlying;
	cout << "A: " << std::is_same<int, AUnderlying>::value << endl;
	cout << "B: " << std::is_same<short, BUnderlying>::value << endl;
	cout << "C: " << std::is_same<int, CUnderlying>::value << endl;
}

void testDecayTraitsType()
{
	cout << "######################################################################" << endl;
	cout << __func__<<":" << endl;
	cout << std::boolalpha<<endl;

	int* pi;

	typedef std::decay<int>::type       AUnderlying;
	typedef std::decay<int&>::type      BUnderlying;
	typedef std::decay<int&&>::type     CUnderlying;
	typedef std::decay<int[2]>::type    DUnderlying;
	typedef std::decay<const int>::type EUnderlying;
	cout << "A: " << std::is_same<int, AUnderlying>::value << endl;
	cout << "B: " << std::is_same<int, BUnderlying>::value << endl;
	cout << "C: " << std::is_same<int, CUnderlying>::value << endl;
	cout << "D: " << std::is_same<int*, DUnderlying>::value << endl;
	cout << "E: " << std::is_same<int, EUnderlying>::value << endl;
}

void testConditionTraitsType()
{
	cout << "######################################################################" << endl;
	cout << __func__<<":" << endl;
	cout << std::boolalpha<<endl;
	typedef int Int;
	typedef std::enable_if<std::is_pointer<float*>::value, Int>::type Type; 
	cout << "enable_if: "<<std::is_same<Int, Type >::value<<endl;

	typedef bool Bool;
	typedef std::conditional<std::is_pointer<int>::value, Int, Bool>::type FType;
	cout << "conditional: "<<std::is_same<Int, FType >::value<<endl;
}

void testCommonTypeTraitsType()
{
	typedef std::common_type<int, float, double, long>::type Type;
	
	cout << "######################################################################" << endl;
	cout << __func__<<":" << endl;
	cout << std::boolalpha<<endl;
	cout << "common_type: "<<std::is_same<double, Type >::value<<endl;
}

double func(double& v)
{
	return v;
}

void testResultOfTraitsType()
{
	int i;
	float f;
	typedef  int(&fn_ref)(int);
	typedef  float(*fn_pointer)(float);
	typedef std::result_of<fn_ref(int)>::type Int;
	typedef std::result_of<fn_pointer(float)>::type Float;
	typedef std::result_of<decltype(func)&(double&)>::type Double;

	cout << "######################################################################" << endl;
	cout << __func__<<":" << endl;
	cout << std::boolalpha<<endl;
	cout << "Int:   "<<std::is_same<int, Int >::value<<endl;
	cout << "Float: "<<std::is_same<float, Float >::value<<endl;
	cout << "Double:"<<std::is_same<double, Double >::value<<endl;
}

int main(int argc, char *argv[])
{
	testCheckTraitsType();
    testCheckClassTraitsType();
    testCheckRelationTraitsType();
    testCheckInitTraitsType();
    testCheckAllocTraitsType();

    testModifyTraitsType();
    testArrayDimension();
    testEnumUnderlyingType();
    testDecayTraitsType();
    testConditionTraitsType();
    testCommonTypeTraitsType();
    testResultOfTraitsType();
	return 0;
}
