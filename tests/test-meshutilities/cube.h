#pragma once

#include <OpenMesh/Core/Mesh/Traits.hh>
#include <OpenMesh/Core/Mesh/TriMesh_ArrayKernelT.hh>

#include <array>


using MeshT = OpenMesh::TriMesh_ArrayKernelT<OpenMesh::DefaultTraits>;

MeshT constructCube();
