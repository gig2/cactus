#include "mesh.h"

MeshT Mesh::loadMesh(std::string filename){
    if(!OpenMesh::IO::read_mesh(mesh_, filename)){
        throw std::runtime_error("Mesh loading error");
    }
}