#include <iostream>

template <typename T1, typename T2>
struct is_same_type
{
	enum { value = false };
};

template <typename T>
struct is_same_type<T, T>
{
	enum { value = true };
};

template <typename T>
struct is_const
{
	enum { value = false };
};

template <typename T>
struct is_const<const T>
{
	enum { value = true };
};

template <typename T>
struct remove_const
{
	typedef T type;
};

template <typename T>
struct remove_const<const T>
{
	typedef T type;
};

template <typename T>
struct is_ref
{
	enum { value = false };
};

template <typename T>
struct is_ref<T&>
{
	enum { value = true };
};

template <typename T>
struct remove_ref
{
	typedef T type;
};

template <typename T>
struct remove_ref<T&>
{
	typedef T type;
};

template <typename T>
struct is_volatile
{
	enum { value = false };
};

template <typename T>
struct is_volatile<volatile T>
{
	enum { value = true };
};

template <typename T>
struct remove_volatile
{
	typedef T type;
};

template <typename T>
struct remove_volatile<volatile T>
{
	typedef T type;
};

template <typename T>
struct is_int
{
	enum { value = is_same_type<int, T>::value };
};

template <typename T>
struct is_float
{
	enum { value = is_same_type<float, T>::value };
};

using std::cout;
using std::endl;

template <typename T>
void show_type()
{
	cout << __PRETTY_FUNCTION__ << endl;
}

template <bool B>
void show_bool()
{
	cout << "TRUE" << endl;
}

template <>
void show_bool<false>()
{
	cout << "FALSE" << endl;
}

int main(int argc, char **argv)
{
	show_bool<is_const<int>::value>();
	show_bool<is_const<const int>::value>();
	show_type<remove_const<int>::type>();
	show_type<remove_const<const int>::type>();

	show_bool<is_ref<int>::value>();
	show_bool<is_ref<int&>::value>();
	show_type<remove_ref<int&>::type>();
	show_type<remove_ref<int>::type>();
	
	show_bool<is_volatile<int>::value>();
	show_bool<is_volatile<volatile int>::value>();
	show_type<remove_volatile<volatile int>::type>();
	show_type<remove_volatile<int>::type>();
	
	show_bool<is_int<int>::value>();
	show_bool<is_int<float>::value>();
	show_bool<is_float<int>::value>();
	show_bool<is_float<float>::value>();
	

	typedef float __FLOAT__;
	show_bool<is_float<float>::value>();
	show_bool<is_float<__FLOAT__>::value>();
	
	show_bool<is_same_type<__FLOAT__, float>::value>();
	show_bool<is_same_type<__FLOAT__, int>::value>();
	
	return 0;
}