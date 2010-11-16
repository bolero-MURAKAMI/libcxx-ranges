//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// type_traits

// has_trivial_default_constructor

#include <type_traits>

template <class T>
void test_has_trivial_default_constructor()
{
    static_assert( std::has_trivial_default_constructor<T>::value, "");
    static_assert( std::has_trivial_default_constructor<const T>::value, "");
    static_assert( std::has_trivial_default_constructor<volatile T>::value, "");
    static_assert( std::has_trivial_default_constructor<const volatile T>::value, "");
}

template <class T>
void test_has_not_trivial_default_constructor()
{
    static_assert(!std::has_trivial_default_constructor<T>::value, "");
    static_assert(!std::has_trivial_default_constructor<const T>::value, "");
    static_assert(!std::has_trivial_default_constructor<volatile T>::value, "");
    static_assert(!std::has_trivial_default_constructor<const volatile T>::value, "");
}

class Empty
{
};

class NotEmpty
{
    virtual ~NotEmpty();
};

union Union {};

struct bit_zero
{
    int :  0;
};

class Abstract
{
    virtual ~Abstract() = 0;
};

struct A
{
    A();
};

int main()
{
    test_has_not_trivial_default_constructor<void>();
    test_has_not_trivial_default_constructor<int&>();
    test_has_not_trivial_default_constructor<A>();
    test_has_not_trivial_default_constructor<Abstract>();
    test_has_not_trivial_default_constructor<NotEmpty>();
    test_has_not_trivial_default_constructor<char[]>();

    test_has_trivial_default_constructor<Union>();
    test_has_trivial_default_constructor<Empty>();
    test_has_trivial_default_constructor<int>();
    test_has_trivial_default_constructor<double>();
    test_has_trivial_default_constructor<int*>();
    test_has_trivial_default_constructor<const int*>();
    test_has_trivial_default_constructor<char[3]>();
    test_has_trivial_default_constructor<bit_zero>();
}
