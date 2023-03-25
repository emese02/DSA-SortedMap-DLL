cmake_minimum_required(VERSION 3.21)
project(ProjectSortedMapDLL)

set(CMAKE_CXX_STANDARD 14)

add_executable(ProjectSortedMapDLL App.cpp SortedMap.cpp SMIterator.cpp ShortTest.cpp ExtendedTest.cpp)
