//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <algorithm>

// template<class RandomAccessIterator, class UniformRandomNumberGenerator>
//     void shuffle(RandomAccessIterator first, RandomAccessIterator last,
//                  UniformRandomNumberGenerator& g);

#include <algorithm-range>
#include <random-range>
#include <cassert>

int main()
{
    int ia[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int ia1[] = {2, 7, 1, 4, 3, 6, 5, 10, 9, 8};
    int ia2[] = {1, 8, 3, 4, 6, 9, 5, 7, 2, 10};
    const unsigned sa = sizeof(ia)/sizeof(ia[0]);
    std::minstd_rand g;
    std::shuffle(std::make_iter_range(ia, ia+sa), g);
    assert(std::equal(std::make_iter_range(ia, ia+sa), std::make_single_iter_range(ia1)));
    std::shuffle(std::make_iter_range(ia, ia+sa), g);
    assert(std::equal(std::make_iter_range(ia, ia+sa), std::make_single_iter_range(ia2)));
}
