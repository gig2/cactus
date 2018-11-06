#pragma once

template <typename MeshType>
auto numberOfFaces( MeshType const& mesh )
{
    return mesh.n_faces();
}
