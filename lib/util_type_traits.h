#ifndef UTIL_TRAITS_H
#define UTIL_TRAITS_H
#include <iostream>
#include <type_traits>
#include <typeinfo>
#include <string>

template <typename T>
void checkTraitsType()
{
	std::cout << "##############################################################" << std::endl;
	std::string name = typeid(T).name();
	std::cout << std::boolalpha<<std::endl;
    std::cout << "type name:                      " << name << std::endl;	
	std::cout << "is_void<T>:                     " << std::is_void<T>::value << std::endl;
	std::cout << "is_integral<T>:                 " << std::is_integral<T>::value << std::endl;
	std::cout << "is_floating_point<T>:           " << std::is_floating_point<T>::value << std::endl;
	std::cout << "is_arithmetic<T>:               " << std::is_arithmetic<T>::value << std::endl;
	std::cout << "is_signed<T>:                   " << std::is_signed<T>::value << std::endl;
	std::cout << "is_unsigned<T>:                 " << std::is_unsigned<T>::value << std::endl;
	std::cout << "is_const<T>:                    " << std::is_const<T>::value << std::endl;
	std::cout << "is_volatile<T>:                 " << std::is_volatile<T>::value << std::endl;
	std::cout << "is_array<T>:                    " << std::is_array<T>::value << std::endl;
	std::cout << "is_enum<T>:                     " << std::is_enum<T>::value << std::endl;
	std::cout << "is_union<T>:                    " << std::is_union<T>::value << std::endl;
	std::cout << "is_class<T>:                    " << std::is_class<T>::value << std::endl;
	std::cout << "is_function<T>:                 " << std::is_function<T>::value << std::endl;
	std::cout << "is_reference<T>:                " << std::is_reference<T>::value << std::endl;
	std::cout << "is_lvalue_reference<T>:         " << std::is_lvalue_reference<T>::value << std::endl;
	std::cout << "is_rvalue_reference<T>:         " << std::is_rvalue_reference<T>::value << std::endl;
	std::cout << "is_pointer<T>:                  " << std::is_pointer<T>::value << std::endl;
	std::cout << "is_member_pointer<T>:           " << std::is_member_pointer<T>::value << std::endl;
	std::cout << "is_member_object_pointer<T>:    " << std::is_member_object_pointer<T>::value << std::endl;
	std::cout << "is_member_function_pointer<T>:  " << std::is_member_function_pointer<T>::value << std::endl;
	std::cout << "is_fundamental<T>:              " << std::is_fundamental<T>::value << std::endl;
	std::cout << "is_scalar<T>:                   " << std::is_scalar<T>::value << std::endl;
	std::cout << "is_object<T>:                   " << std::is_object<T>::value << std::endl;
	std::cout << "is_compound<T>:                 " << std::is_compound<T>::value << std::endl;
	std::cout << "is_trivial<T>:                  " << std::is_trivial<T>::value << std::endl;
	std::cout << "is_trivially_copyable<T>:       " << std::is_trivially_copyable<T>::value << std::endl;
	std::cout << "is_standard_layout<T>:          " << std::is_standard_layout<T>::value << std::endl;
	std::cout << "is_pod<T>:                      " << std::is_pod<T>::value << std::endl;
	std::cout << "is_literal_type<T>:             " << std::is_literal_type<T>::value << std::endl;

	
}

template <typename T>
void checkClassTraitsType()
{

	std::cout << "##############################################################" << std::endl;
	std::string name = typeid(T).name();
	std::cout << std::boolalpha<<std::endl;
    std::cout << "type name:                             " << name << std::endl;	
	std::cout << "is_empty<T>:                           " << std::is_empty<T>::value << std::endl;
	std::cout << "is_polymorphic<T>:                     " << std::is_polymorphic<T>::value << std::endl;
	std::cout << "is_abstract<T>:                        " << std::is_abstract<T>::value << std::endl;
	std::cout << "has_virtual_destructor<T>:             " << std::has_virtual_destructor<T>::value << std::endl;
	std::cout << "is_default_constructible<T>:           " << std::is_default_constructible<T>::value << std::endl;
	std::cout << "is_copy_constructible<T>:              " << std::is_copy_constructible<T>::value << std::endl;
	std::cout << "is_move_constructible<T>:              " << std::is_move_constructible<T>::value << std::endl;
	std::cout << "is_copy_assignable<T>:                 " << std::is_copy_assignable<T>::value << std::endl;
	std::cout << "is_move_assignable<T>:                 " << std::is_move_assignable<T>::value << std::endl;
	std::cout << "is_destructible<T>:                    " << std::is_destructible<T>::value << std::endl;
	std::cout << "is_trivially_default_constructible<T>: " << std::is_trivially_default_constructible<T>::value << std::endl;
	std::cout << "is_trivially_copy_constructible<T>:    " << std::is_trivially_copy_constructible<T>::value << std::endl;
	std::cout << "is_trivially_move_constructible<T>:    " << std::is_trivially_move_constructible<T>::value << std::endl;
	std::cout << "is_trivially_copy_assignable<T>:       " << std::is_trivially_copy_assignable<T>::value << std::endl;
	std::cout << "is_trivially_move_assignable<T>:       " << std::is_trivially_move_assignable<T>::value << std::endl;
	std::cout << "is_trivially_destructible<T>:          " << std::is_trivially_destructible<T>::value << std::endl;
	std::cout << "is_nothrow_default_constructible<T>:   " << std::is_nothrow_default_constructible<T>::value << std::endl;
	std::cout << "is_nothrow_copy_constructible<T>:      " << std::is_nothrow_copy_constructible<T>::value << std::endl;
	std::cout << "is_nothrow_move_constructible<T>:      " << std::is_nothrow_move_constructible<T>::value << std::endl;
	std::cout << "is_nothrow_copy_assignable<T>:         " << std::is_nothrow_copy_assignable<T>::value << std::endl;
	std::cout << "is_nothrow_move_assignable<T>:         " << std::is_nothrow_move_assignable<T>::value << std::endl;
	std::cout << "is_nothrow_destructible<T>:            " << std::is_nothrow_destructible<T>::value << std::endl;

}

template <typename T1 ,typename T2>
void checkRelationTraitsType()
{

	std::cout << "##############################################################" << std::endl;
	std::cout << std::boolalpha<<std::endl;
	std::cout << "is_same<T1, T2>:                        " << std::is_same<T1, T2>::value << std::endl;
	std::cout << "is_base_of<T1, T2>:                     " << std::is_base_of<T1, T2>::value << std::endl;
	std::cout << "is_convertible<T1, T2>:                 " << std::is_convertible<T1, T2>::value << std::endl;
	std::cout << "is_assignable<T1, T2>:                  " << std::is_assignable<T1, T2>::value << std::endl;
	std::cout << "is_trivially_assignable<T1, T2>:        " << std::is_trivially_assignable<T1, T2>::value << std::endl;
	std::cout << "is_nothrow_assignable<T1, T2>:          " << std::is_nothrow_assignable<T1, T2>::value << std::endl;

}

template <typename T, typename... Args>
void checkInitTraitsType()
{

	std::cout << "##############################################################" << std::endl;
	std::cout << std::boolalpha<<std::endl;
	std::cout << "is_constructible<T, Args...>:           " << std::is_constructible<T, Args...>::value << std::endl;
	std::cout << "is_trivially_constructible<T, Args...>: " << std::is_trivially_constructible<T, Args...>::value << std::endl;
	std::cout << "is_nothrow_constructible<T, Args...>:   " << std::is_nothrow_constructible<T, Args...>::value << std::endl;
}

template <typename T, typename Alloc>
void checkAllocTraitsType()
{
	std::cout << "##############################################################" << std::endl;
	std::cout << std::boolalpha<<std::endl;
	std::cout << "uses_allocator<T, Alloc>:               " << std::uses_allocator<T, Alloc>::value << std::endl;
}

#endif /* ifndef UTIL_TRAITS_H */
