#pragma once

#include <iterator>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>

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

template< class InputIt, class Size, class UnaryFunc >
std::pair<InputIt, UnaryFunc> my_for_each_n( InputIt first, Size n, UnaryFunc f )
{
    for (; n > 0; n--, first++)
        f(*first);
    return {first, f};
}