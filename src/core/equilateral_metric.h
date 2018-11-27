#pragma once

#include "meshutilities.h"

#include <OpenMesh/Core/Geometry/Vector11T.hh>
#include <OpenMesh/Core/Mesh/Traits.hh>
#include <OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>

#include <algorithm>
#include <functional>
#include <iterator>

template <typename MeshType, typename FaceHandle>
float computeEquilateralMetric( MeshType const& mesh, FaceHandle const& faceHandle )
{
    auto minmax = minmaxAngleInTriangle( mesh, faceHandle );
    return minmax.second - minmax.first;
}

template <typename MeshType, typename FaceIt, typename OutIt>
OutIt computeEquilateralMetricElement( MeshType const& mesh, FaceIt&& inBeginIt, FaceIt&& inEndIt,
                                       OutIt&& outBeginIt )
{
    //

    return std::transform( inBeginIt, inEndIt, outBeginIt, [&mesh]( auto const& faceHandle ) {
        return computeEquilateralMetric( mesh, faceHandle );
    } );
}
