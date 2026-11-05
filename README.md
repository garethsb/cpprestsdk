# C++ REST SDK, Long-Term Support

> [!NOTE]
> Microsoft has archived [microsoft/cpprestsdk](https://github.com/microsoft/cpprestsdk). This fork, maintained by the [cpprest-lts](https://github.com/cpprest-lts) organization, takes security fixes, fixes for major bugs, and changes needed to build with current compilers and dependencies. It does not plan new features or API changes. [Issue #15](https://github.com/cpprest-lts/cpprestsdk/issues/15) describes the scope and the plans.


## Welcome!

The C++ REST SDK is a Microsoft project for cloud-based client-server communication in native code using a modern asynchronous C++ API design. This project aims to help C++ developers connect to and interact with services.  

## Getting Started

[![Build and Test](https://github.com/cpprest-lts/cpprestsdk/actions/workflows/build-test.yml/badge.svg?branch=cpprest-lts)](https://github.com/cpprest-lts/cpprestsdk/actions/workflows/build-test.yml?query=branch%3Acpprest-lts)
[![Packaged in](https://repology.org/badge/tiny-repos/cpprestsdk.svg)](https://repology.org/project/cpprestsdk/versions)
[![Latest packaged version](https://repology.org/badge/latest-versions/cpprestsdk.svg)](https://repology.org/project/cpprestsdk/versions)

With [vcpkg](https://github.com/Microsoft/vcpkg) on Windows
```
PS> vcpkg install cpprestsdk cpprestsdk:x64-windows
```
With [apt-get](https://launchpad.net/ubuntu/+source/casablanca/2.8.0-2build2) on Debian/Ubuntu
```
$ sudo apt-get install libcpprest-dev
```
With [dnf](https://apps.fedoraproject.org/packages/cpprest) on Fedora
```
$ sudo dnf install cpprest-devel
```
With [brew](https://github.com/Homebrew/homebrew-core/blob/master/Formula/cpprestsdk.rb) on OSX
```
$ brew install cpprestsdk
```
With [NuGet](https://www.nuget.org/packages/cpprestsdk.android/) on Windows for Android
```
PM> Install-Package cpprestsdk.android
```
For other platforms, install options, how to build from source, and more, take a look at our [Documentation](https://github.com/Microsoft/cpprestsdk/wiki).

Once you have the library, look at our [tutorial](https://github.com/Microsoft/cpprestsdk/wiki/Getting-Started-Tutorial) to use the http_client. It walks through how to setup a project to use the C++ Rest SDK and make a basic Http request.

To use from CMake:
```cmake
cmake_minimum_required(VERSION 3.10)
project(main)

find_package(cpprestsdk REQUIRED)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE cpprestsdk::cpprest)
```

## What's in the SDK:

*   Features - HTTP client/server, JSON, URI, asynchronous streams, WebSockets client, oAuth
*   PPL Tasks - A powerful model for composing asynchronous operations based on C++ 11 features
*   Platforms - Windows desktop, Windows Store (UWP), Linux, OS X, Unix, iOS, and Android
*   Support for [Visual Studio 2015 and 2017](https://visualstudio.microsoft.com/) with debugger visualizers

## Contribute Back!

Have you found a bug, or do you have a fix for one? Please open an [issue](https://github.com/cpprest-lts/cpprestsdk/issues) or a [pull request](https://github.com/cpprest-lts/cpprestsdk/pulls). This fork takes security fixes, fixes for major bugs, and changes needed to build with current compilers and dependencies, but not new features or API changes. [Issue #15](https://github.com/cpprest-lts/cpprestsdk/issues/15) lists the work done and planned.

Please report security vulnerabilities privately, as described in [SECURITY.md](SECURITY.md).

## Having Trouble?

We'd love to get your review score, whether good or bad, but even more than that, we want to fix your problem. If you submit your issue as a Review, we won't be able to respond to your problem and ask any follow-up questions that may be necessary. The most efficient way to do that is to open an issue in our [issue tracker](https://github.com/cpprest-lts/cpprestsdk/issues).  

### Quick Links

*   [FAQ](https://github.com/Microsoft/cpprestsdk/wiki/FAQ) (in the original project's wiki)
*   [Documentation](https://github.com/Microsoft/cpprestsdk/wiki) (in the original project's wiki)
*   [Issue Tracker](https://github.com/cpprest-lts/cpprestsdk/issues)
*   [Security Policy](SECURITY.md)

This project has adopted the [Microsoft Open Source Code of Conduct](https://opensource.microsoft.com/codeofconduct/). For more information see the [Code of Conduct FAQ](https://opensource.microsoft.com/codeofconduct/faq/) or contact [opencode@microsoft.com](mailto:opencode@microsoft.com) with any additional questions or comments.

