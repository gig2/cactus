#include "cube.h"
#include "meshutilities.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

using namespace testing;

TEST( aCube, haveDiedreAngleEqualsToPi )
{
    auto cube = constructCube();


    float expectedAngle = M_PI / 2.0;

    float maxError = 1.e-5;

    for ( auto faceIt = cube.faces_begin(); faceIt != cube.faces_end(); ++faceIt )
    {
        auto nextFace = std::next( faceIt );
        if ( nextFace != cube.faces_end() )
        {
            auto angle = angleBetweenFaces( cube, *faceIt, *nextFace );

            EXPECT_THAT( angle,
                         AnyOf( FloatNear( expectedAngle, maxError ), FloatNear( 0.f, maxError ),
                                FloatNear( static_cast<float>( M_PI ), maxError ) ) );
        }
    }
}
