cmake_minimum_required(VERSION 3.28)
project(Algoritmos)

set(CMAKE_CXX_STANDARD 17)

add_executable(Algoritmos main.cpp
)
add_executable(Selection selectionSort.cpp)
add_executable(Insertion insertionSort.cpp)
add_executable(Merge mergeSort.cpp)
add_executable(Quick quickSort.cpp)
add_executable(listArray listArray.cpp)
