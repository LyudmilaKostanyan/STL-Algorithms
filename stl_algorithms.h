#pragma once

#include <iterator>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>

namespace mila{
    template< class InputIt, class UnaryFunc >
    UnaryFunc for_each( InputIt first, InputIt last, UnaryFunc f )
    {
        while (first != last)
        {
            f(*first);
            first++;
        }
        return f;
    }

    template< class InputIt, class Size, class UnaryFunc >
    std::pair<InputIt, UnaryFunc> for_each_n( InputIt first, Size n, UnaryFunc f )
    {
        for (; n > 0; n--, first++)
            f(*first);
        return {first, f};
    }

    template< class InputIt, class T >
    InputIt find( InputIt first, InputIt last, const T& value )
    {
        for (; first != last; first++)
            if (*first == value)
                return first;
        return last;
    }

    template< class InputIt, class UnaryPred >
    InputIt find_if( InputIt first, InputIt last, UnaryPred p )
    {
        for (; first != last; first++)
            if (p(*first))
                return first;
        return last;
    }

    template< class InputIt, class UnaryPred >
    InputIt find_if_not( InputIt first, InputIt last, UnaryPred q )
    {
        for (; first != last; first++)
            if (!q(*first))
                return first;
        return last;
    }

    template< class InputIt, class UnaryPred >
    bool all_of( InputIt first, InputIt last, UnaryPred p )
    {
        if (mila::find_if_not(first, last, p) == last)
            return true;
        return false;
    }

    template< class InputIt, class UnaryPred >
    bool any_of( InputIt first, InputIt last, UnaryPred p )
    {
        if (mila::find_if(first, last, p) != last)
            return true;
        return false;
    }

    template< class InputIt, class UnaryPred >
    bool none_of( InputIt first, InputIt last, UnaryPred p )
    {
        if (mila::find_if(first, last, p) == last)
            return true;
        return false;
    }
}