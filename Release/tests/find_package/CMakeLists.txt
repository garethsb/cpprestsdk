# Builds a program against an installed cpprestsdk package, as another project would,
# to check that the package's CMake config brings in everything cpprest needs
cmake_minimum_required(VERSION 3.9)
project(find_package_test CXX)

find_package(cpprestsdk REQUIRED)

add_executable(find_package_test main.cpp)
target_link_libraries(find_package_test PRIVATE cpprestsdk::cpprest)
