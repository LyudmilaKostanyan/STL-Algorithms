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

    template< class InputIt, class ForwardIt >
    InputIt find_first_of( InputIt first, InputIt last, ForwardIt s_first, ForwardIt s_last )
    {
        for (;s_first != s_last; s_first++)
        {
            auto it = mila::find(first, last, *s_first);
            if (it != last)
                return it;
        }
        return last;
    }

    template< class InputIt, class ForwardIt, class BinaryPred >
    InputIt find_first_of( InputIt first, InputIt last, ForwardIt s_first, ForwardIt s_last, BinaryPred p )
    {
        for (;s_first != s_last; s_first++)
            for (; first != last; first++)
                if (p(*first, *s_first))
                    return first;
        return last;
    }

    
    template< class ForwardIt1, class ForwardIt2 >
    ForwardIt1 search( ForwardIt1 first, ForwardIt1 last, ForwardIt2 s_first, ForwardIt2 s_last )
    {
        ForwardIt1 s_it;
        ForwardIt1 start;
        for (auto it = first; it != last; it++)
        {
            start = it;
            for (s_it = s_first; s_it != s_last; s_it++)
            {
                if (*it != *s_it)
                {
                    s_it = s_first;
                    break;
                }
                it++;
            }
            if (s_it == s_last)
            return start;
        }
        return last;
    }
    
    template< class ForwardIt1, class ForwardIt2, class BinaryPred >
    ForwardIt1 search( ForwardIt1 first, ForwardIt1 last, ForwardIt2 s_first, ForwardIt2 s_last, BinaryPred p )
    {
        ForwardIt1 s_it;
        ForwardIt1 start;
        for (auto it = first; it != last; it++)
        {
            start = it;
            for (s_it = s_first; s_it != s_last; s_it++)
            {
                if (!p(*it, *s_it))
                {
                    s_it = s_first;
                    break;
                }
                it++;
            }
            if (s_it == s_last)
            return start;
        }
        return last;
    }
    
    template< class ForwardIt1, class ForwardIt2 >
    ForwardIt1 find_end( ForwardIt1 first, ForwardIt1 last, ForwardIt2 s_first, ForwardIt2 s_last )
    {
        for (auto it = last; it != first; it--)
            for (;s_first != s_last; s_first++)
                if (*s_first == *it)
                    return it;
        return last;
    }
    
    template< class ForwardIt1, class ForwardIt2, class BinaryPred >
    ForwardIt1 find_end( ForwardIt1 first, ForwardIt1 last, ForwardIt2 s_first, ForwardIt2 s_last, BinaryPred p )
    {
        for (auto it = last; it != first; it--)
            for (;s_first != s_last; s_first++)
                if (p(*s_first,*it))
                    return it;
        return last;
    }
}
