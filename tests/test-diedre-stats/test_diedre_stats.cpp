#include "cube.h"
#include "diedre_stats.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using testing::Eq;
using testing::FloatEq;

TEST( aCube, stats )
{
    auto cube = constructCube();

    auto diedreStats = DiedreStats<decltype( cube )>{cube};

    EXPECT_THAT( diedreStats.min(), FloatEq( 0.f ) );
    EXPECT_THAT( diedreStats.max(), FloatEq( M_PI ) );
}
