//===----------------------------------------------------------------------===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//

// <system_error>

// class error_code

// const error_category& category() const;

#include <system_error>
#include <cassert>

int main()
{
    const std::error_code ec(6, std::generic_category());
    assert(ec.category() == std::generic_category());
}
