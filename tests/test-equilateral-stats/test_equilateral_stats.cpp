#include "cube.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include <cmath>

using testing::Eq;
using testing::FloatEq;


// So what do we need here
// first we need to check that an equilateral triangle
// will be seen as an equilateral triangle
// then we will change one angle to check that it will
// be less equilateral

// we have two main case of non equilaterality
// the pointy one : like an arrow -> one angle near to 0.
// the flat triangle: one angle near pi

//
TEST( aCube, haveIsoceleTriangulation )
{
    auto cube = constructCube();
}
