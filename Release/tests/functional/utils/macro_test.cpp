/***
 * Copyright (C) Microsoft. All rights reserved.
 * Licensed under the MIT license. See LICENSE.txt file in the project root for full license information.
 *
 * =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
 *
 * macro_test.cpp
 *
 * Tests cases for macro name conflicts.
 *
 * =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
 ****/
#include "stdafx.h"

#include "cpprest/http_client.h"
#include "cpprest/http_msg.h"
#include "cpprest/json.h"
#include "cpprest/uri_builder.h"

// Other headers, such as curl.h, use __has_declspec_attribute(dllimport), which Clang 14 and later reject
// if dllimport is defined as nothing
#if defined(__has_declspec_attribute)
#if __has_declspec_attribute(dllimport)
#endif
#endif

namespace tests
{
namespace functional
{
namespace utils_tests
{
template<typename U>
void macro_U_Test()
{
    (void)U();
}

SUITE(macro_test)
{
    TEST(U_test) { macro_U_Test<int>(); }
}
} // namespace utils_tests
} // namespace functional
} // namespace tests
