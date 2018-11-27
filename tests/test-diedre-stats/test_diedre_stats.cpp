#include "cube.h"
#include "diedre_stats.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include <cmath>

using testing::Eq;
using testing::FloatEq;

TEST( aCube, stats )
{
    auto cube = constructCube();

    auto diedreStats = DiedreStats<decltype( cube )>{cube};

    auto modulusPi = []( float angle ) { return static_cast<float>( std::fmod( angle, M_PI ) ); };

    EXPECT_THAT( modulusPi( diedreStats.min() ), FloatEq( modulusPi( 0.f ) ) );
    EXPECT_THAT( modulusPi( diedreStats.max() ), FloatEq( modulusPi( M_PI / 2.f ) ) );
}
