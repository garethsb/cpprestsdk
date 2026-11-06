/***
 * Copyright (C) Microsoft. All rights reserved.
 * Licensed under the MIT license. See LICENSE.txt file in the project root for full license information.
 *
 * =+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+
 *
 * httpt_test_utilities.h -- This is the "one-stop-shop" header for including http test dependencies
 *
 * =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-
 ****/

#pragma once

#include "http_asserts.h"
#include "http_test_utilities_public.h"
#include "test_http_client.h"
#include "test_http_server.h"
#include "test_server_utilities.h"

// Test properties that ignore a test when the library uses the Asio HTTP client or listener, on any platform.
// The test runner cannot tell which implementations the library uses.
#if defined(CPPREST_FORCE_HTTP_CLIENT_ASIO)
#define IGNORE_IF_HTTP_CLIENT_ASIO "Ignore"
#else
#define IGNORE_IF_HTTP_CLIENT_ASIO "Ignore:None"
#endif
#if defined(CPPREST_FORCE_HTTP_LISTENER_ASIO)
#define IGNORE_IF_HTTP_LISTENER_ASIO "Ignore"
#else
#define IGNORE_IF_HTTP_LISTENER_ASIO "Ignore:None"
#endif
