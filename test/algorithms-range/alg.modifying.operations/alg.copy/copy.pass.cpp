//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is dual licensed under the MIT and the University of Illinois Open
// Source Licenses. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <algorithm>

// template<InputIterator InIter, OutputIterator<auto, InIter::reference> OutIter>
//   OutIter
//   copy(InIter first, InIter last, OutIter result);

#include <algorithm-range>
#include <cassert>

#include "test_iterators.h"
#include "test_ranges.h"

template <class InRange, class OutRange>
void
test()
{
    const unsigned N = 1000;
    int ia[N];
    for (unsigned i = 0; i < N; ++i)
        ia[i] = i;
    int ib[N] = {0};

    InRange irg(std::make_iter_range(ia, ia+N));
    OutRange org(std::make_single_iter_range(ib));
     
    OutRange r = std::copy(irg, org);
    assert(base(r).base() == ib+N);
    for (unsigned i = 0; i < N; ++i)
        assert(ia[i] == ib[i]);
}

int main()
{
    test<input_range<std::iter_range<const int*> >, output_range<std::single_iter_range<int*> > >();
    test<input_range<std::iter_range<const int*> >, input_range<std::single_iter_range<int*> > >();
    test<input_range<std::iter_range<const int*> >, forward_range<std::single_iter_range<int*> > >();
    test<input_range<std::iter_range<const int*> >, bidirectional_range<std::single_iter_range<int*> > >();
    test<input_range<std::iter_range<const int*> >, random_access_range<std::single_iter_range<int*> > >();

    test<forward_range<std::iter_range<const int*> >, output_range<std::single_iter_range<int*> > >();
    test<forward_range<std::iter_range<const int*> >, input_range<std::single_iter_range<int*> > >();
    test<forward_range<std::iter_range<const int*> >, forward_range<std::single_iter_range<int*> > >();
    test<forward_range<std::iter_range<const int*> >, bidirectional_range<std::single_iter_range<int*> > >();
    test<forward_range<std::iter_range<const int*> >, random_access_range<std::single_iter_range<int*> >  >();

    test<bidirectional_range<std::iter_range<const int*> >, output_range<std::single_iter_range<int*> > >();
    test<bidirectional_range<std::iter_range<const int*> >, input_range<std::single_iter_range<int*> > >();
    test<bidirectional_range<std::iter_range<const int*> >, forward_range<std::single_iter_range<int*> > >();
    test<bidirectional_range<std::iter_range<const int*> >, bidirectional_range<std::single_iter_range<int*> > >();
    test<bidirectional_range<std::iter_range<const int*> >, random_access_range<std::single_iter_range<int*> >  >();

    test<random_access_range<std::iter_range<int*> >, output_range<std::single_iter_range<int*> > >();
    test<random_access_range<std::iter_range<int*> >, input_range<std::single_iter_range<int*> > >();
    test<random_access_range<std::iter_range<int*> >, forward_range<std::single_iter_range<int*> > >();
    test<random_access_range<std::iter_range<int*> >, bidirectional_range<std::single_iter_range<int*> > >();
    test<random_access_range<std::iter_range<int*> >, random_access_range<std::single_iter_range<int*> >  >();
}
