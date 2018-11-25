#pragma once
#include <algorithm>
#include <iterator>
#include <numeric>

template <typename inputIT>
double moyenne( inputIT begin, inputIT end )
{
    double nb_element         = std::distance( begin, end );
    double somme_all_valences = std::accumulate( begin, end, 0 );

    return somme_all_valences / nb_element;
}

/** \pre trié entre begin et end.
 */
template <typename inputIT>
double mediane_sorted( inputIT begin, inputIT end )
{
    if ( begin == end )
        return 0.;
    int nb_element = std::distance( begin, end );

    if ( nb_element % 2 == 1 )
    {
        auto iter = begin;
        std::advance( iter, ( nb_element + 1 ) / 2 - 1 );
        return *iter;
    }
    else
    {
        auto lower = begin;
        std::advance( lower, nb_element / 2 - 1 );
        auto upper = std::next( lower );

        return ( *lower + *upper ) / 2.;
    }
}

/** \pre trié entre begin et end.
 */
template <typename inputIT>
int min_sorted( inputIT begin, inputIT end )
{
    auto last = end - 1;
    return std::min( *begin, *last );
}

/** \pre trié entre begin et end.
 */
template <typename inputIT>
int max_sorted( inputIT begin, inputIT end )
{
    auto last = end - 1;
    return std::max( *begin, *last );
}
