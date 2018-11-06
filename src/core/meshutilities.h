#pragma once

#include "mesh.h"

template <typename MeshType>
std::size_t numberOfFaces( MeshType const& mesh )
{
    return mesh.n_faces();
}
