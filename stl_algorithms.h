#pragma once

#include <iterator>
#include <vector>
#include <iostream>

template< class InputIt, class UnaryFunc >
UnaryFunc my_for_each( InputIt first, InputIt last, UnaryFunc f )
{
    while (first != last)
    {
        f(*first);
        first++;
    }
    return f;
}