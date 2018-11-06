//
#include "meshutilities.h"

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include <OpenMesh/Core/Mesh/Traits.hh>
#include <OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>

using MeshT = OpenMesh::TriMesh_ArrayKernelT<OpenMesh::DefaultTraits>;

using testing::Eq;

TEST( anEmptyMesh, haveNoFaces )
{
    //
    MeshT mesh;
    auto numFaces = numberOfFaces( mesh );

    EXPECT_THAT( numFaces, Eq( 0u ) );
}

int main( int argc, char **argv )
{
    ::testing::InitGoogleTest( &argc, argv );

    return RUN_ALL_TESTS();
}
