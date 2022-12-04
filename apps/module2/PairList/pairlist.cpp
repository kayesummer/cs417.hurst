//
// File:   main.cpp
// Author: <Your Glorious Instructor>
// Purpose:
// Demo building a list structure using C++ tuples.
//
// Reference: https://gist.github.com/mattbierner/6145505
//
#include <iostream>
#include <tuple>

#include "tuple_ops.h"

template<typename T>
void print_tuple(const T& x)
{
    std::cout <<  "Head:" << Head(x) << " Remaining:" << std::tuple_size<T>::value - 1 << std::endl;
}

int main(int argc, const char* argv[])
{
    auto list = Combine(6, Combine(std::string("hello world!"), Combine(5.53f, empty)));
    auto list2 = Combine(322, Combine(list, Combine("abc", empty)));

    print_tuple(list);              // size=3, head=6
    print_tuple(Tail(list));         // size=2, head="hello world!",
    print_tuple(Tail(Tail(list)));    // size=1, head=5.53f
    auto x = Tail(Tail(Tail(list)));    // empty tuple.
    std::cout << std::tuple_size<decltype(x)>::value << std::endl;

    print_tuple(list2);                // size=3, head=322
    Tail(list2);                        // size=2, head=list,
    print_tuple(Head(Tail(list2)));      // size=3, head=6,
    print_tuple(Tail(Head(Tail(list2)))); // size=2, head="hello world!",
    print_tuple(Tail(Tail(list2)));      // size=1, head="abc",
}