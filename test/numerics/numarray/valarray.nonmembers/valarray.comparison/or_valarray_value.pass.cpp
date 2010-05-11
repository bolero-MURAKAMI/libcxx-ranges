//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <valarray>

// template<class T> class valarray;

// template<class T>
//   valarray<bool>
//   operator||(const valarray<T>& x, const T& y);

#include <valarray>
#include <cassert>

int main()
{
    {
        typedef int T;
        T a1[] = {1,  2,  3,  4,  0};
        bool a3[] = {true,  true,  true,  true,  true};
        const unsigned N = sizeof(a1)/sizeof(a1[0]);
        std::valarray<T> v1(a1, N);
        std::valarray<bool> v3 = v1 || 5;
        assert(v1.size() == v3.size());
        for (int i = 0; i < v1.size(); ++i)
            assert(v3[i] == a3[i]);
    }
    {
        typedef int T;
        T a1[] = {1,  2,  3,  4,  0};
        bool a3[] = {true,  true,  true,  true,  false};
        const unsigned N = sizeof(a1)/sizeof(a1[0]);
        std::valarray<T> v1(a1, N);
        std::valarray<bool> v3 = v1 || 0;
        assert(v1.size() == v3.size());
        for (int i = 0; i < v1.size(); ++i)
            assert(v3[i] == a3[i]);
    }
}
