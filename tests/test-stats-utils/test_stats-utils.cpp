#include "valence.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include <algorithm>
#include <functional>

using testing::DoubleEq;

TEST( aMedianOfOneElement, isThisElement )
{
    std::vector<int> valence{10};

    std::sort( std::begin( valence ), std::end( valence ) );

    auto actualMediane = mediane_sorted( std::begin( valence ), std::end( valence ) );

    EXPECT_THAT( actualMediane, DoubleEq( 10. ) );
}
TEST( aMedianOfTwoElement, isTheMiddlePoint )
{
    std::vector<int> valence{10, 20};

    std::sort( std::begin( valence ), std::end( valence ) );

    auto actualMediane = mediane_sorted( std::begin( valence ), std::end( valence ) );

    EXPECT_THAT( actualMediane, DoubleEq( 15. ) );
}
TEST( aMedianOfThreeElement, isTheSecondValue )
{
    std::vector<int> valence{10, 20, 30};

    std::sort( std::begin( valence ), std::end( valence ) );

    auto actualMediane = mediane_sorted( std::begin( valence ), std::end( valence ) );

    EXPECT_THAT( actualMediane, DoubleEq( 20. ) );
}
TEST( aMedianOfFourElement, isMiddlePointOfSecondAndThirdValue )
{
    std::vector<int> valence{10, 20, 30, 40};

    std::sort( std::begin( valence ), std::end( valence ) );

    auto actualMediane = mediane_sorted( std::begin( valence ), std::end( valence ) );

    EXPECT_THAT( actualMediane, DoubleEq( 25. ) );
}
