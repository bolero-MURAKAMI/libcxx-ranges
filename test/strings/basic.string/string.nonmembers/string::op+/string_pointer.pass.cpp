//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <string>

// template<class charT, class traits, class Allocator> 
//   basic_string<charT,traits,Allocator> 
//   operator+(const basic_string<charT,traits,Allocator>& lhs, const charT* rhs);

// template<class charT, class traits, class Allocator> 
//   basic_string<charT,traits,Allocator>&&
//   operator+(basic_string<charT,traits,Allocator>&& lhs, const charT* rhs);

#include <string>
#include <cassert>

template <class S>
void
test0(const S& lhs, const typename S::value_type* rhs, const S& x)
{
    assert(lhs + rhs == x);
}

#ifdef _LIBCPP_MOVE

template <class S>
void
test1(S&& lhs, const typename S::value_type* rhs, const S& x)
{
    assert(move(lhs) + rhs == x);
}

#endif

typedef std::string S;

int main()
{
    test0(S(""), "", S(""));
    test0(S(""), "12345", S("12345"));
    test0(S(""), "1234567890", S("1234567890"));
    test0(S(""), "12345678901234567890", S("12345678901234567890"));
    test0(S("abcde"), "", S("abcde"));
    test0(S("abcde"), "12345", S("abcde12345"));
    test0(S("abcde"), "1234567890", S("abcde1234567890"));
    test0(S("abcde"), "12345678901234567890", S("abcde12345678901234567890"));
    test0(S("abcdefghij"), "", S("abcdefghij"));
    test0(S("abcdefghij"), "12345", S("abcdefghij12345"));
    test0(S("abcdefghij"), "1234567890", S("abcdefghij1234567890"));
    test0(S("abcdefghij"), "12345678901234567890", S("abcdefghij12345678901234567890"));
    test0(S("abcdefghijklmnopqrst"), "", S("abcdefghijklmnopqrst"));
    test0(S("abcdefghijklmnopqrst"), "12345", S("abcdefghijklmnopqrst12345"));
    test0(S("abcdefghijklmnopqrst"), "1234567890", S("abcdefghijklmnopqrst1234567890"));
    test0(S("abcdefghijklmnopqrst"), "12345678901234567890", S("abcdefghijklmnopqrst12345678901234567890"));

#ifdef _LIBCPP_MOVE

    test1(S(""), "", S(""));
    test1(S(""), "12345", S("12345"));
    test1(S(""), "1234567890", S("1234567890"));
    test1(S(""), "12345678901234567890", S("12345678901234567890"));
    test1(S("abcde"), "", S("abcde"));
    test1(S("abcde"), "12345", S("abcde12345"));
    test1(S("abcde"), "1234567890", S("abcde1234567890"));
    test1(S("abcde"), "12345678901234567890", S("abcde12345678901234567890"));
    test1(S("abcdefghij"), "", S("abcdefghij"));
    test1(S("abcdefghij"), "12345", S("abcdefghij12345"));
    test1(S("abcdefghij"), "1234567890", S("abcdefghij1234567890"));
    test1(S("abcdefghij"), "12345678901234567890", S("abcdefghij12345678901234567890"));
    test1(S("abcdefghijklmnopqrst"), "", S("abcdefghijklmnopqrst"));
    test1(S("abcdefghijklmnopqrst"), "12345", S("abcdefghijklmnopqrst12345"));
    test1(S("abcdefghijklmnopqrst"), "1234567890", S("abcdefghijklmnopqrst1234567890"));
    test1(S("abcdefghijklmnopqrst"), "12345678901234567890", S("abcdefghijklmnopqrst12345678901234567890"));

#endif
}
