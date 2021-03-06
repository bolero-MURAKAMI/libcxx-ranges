//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <algorithm>

// template<InputIterator Iter1, InputIterator Iter2>
//   requires HasEqualTo<Iter1::value_type, Iter2::value_type>
//   bool
//   equal(Iter1 first1, Iter1 last1, Iter2 first2);

#include <algorithm-range>
#include <cassert>

#include "test_ranges.h"
#include "test_iterators.h"

int main()
{
    int ia[] = {0, 1, 2, 3, 4, 5};
    const unsigned s = sizeof(ia)/sizeof(ia[0]);
    int ib[s] = {0, 1, 2, 5, 4, 5};
    assert(std::equal(make_input_range(std::make_iter_range(
                          input_iterator<const int*>(ia),
                          input_iterator<const int*>(ia+s))),
                      make_input_range(std::make_single_iter_range(
			  input_iterator<const int*>(ia)))));
    assert(!std::equal(make_input_range(std::make_iter_range(
                           input_iterator<const int*>(ia),
                           input_iterator<const int*>(ia+s))),
                       make_input_range(std::make_single_iter_range(
			   input_iterator<const int*>(ib)))));
}
