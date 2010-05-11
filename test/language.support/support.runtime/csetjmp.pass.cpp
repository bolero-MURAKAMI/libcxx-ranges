//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// test <csetjmp>

#include <csetjmp>
#include <type_traits>

#ifndef setjmp
#error setjmp not defined
#endif

int main()
{
    std::jmp_buf jb;
    static_assert((std::is_same<__typeof__(std::longjmp(jb, 0)), void>::value),
                  "std::is_same<__typeof__(std::longjmp(jb, 0)), void>::value");
}
