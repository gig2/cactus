#include "valence.h"

using namespace std;

Valence::Valence(const MeshT &mesh) {
    Valence::valence_init(mesh);
}

void Valence::valence_init(const MeshT &mesh)
{
    valence_par_points.clear();
    valence_par_points_trie.clear();
    auto vIt = mesh.vertices_begin();
    while( vIt != mesh.vertices_end() ){
        valence_par_points.push_back((int)mesh.valence(*vIt));
        vIt++;
    }

    std::copy(std::begin(valence_par_points),std::end(valence_par_points),std::back_inserter(valence_par_points_trie));
    std::sort(std::begin(valence_par_points_trie),std::end(valence_par_points_trie));
}

float Valence::moyenne_valence(){
    int total_valence = 0;
    for(int i = 0 ; i < valence_par_points.size() ; i++)
        total_valence += valence_par_points.at(i);
    return ((total_valence*1.0f) / (valence_par_points.size()*1.0f));

}

float Valence::mediane_valence(){
    int npts = valence_par_points_trie.size();
    if(npts%2 == 1)
        return valence_par_points_trie[(npts+1)/2];
    else {
       int m = npts/2;
       return ((valence_par_points_trie[m] + valence_par_points_trie[m+1])/2);
    }
}

int Valence::min_valence(){
    if(valence_par_points_trie.empty())
        throw std::runtime_error("tableau de valence vide!");
    return valence_par_points_trie.front();
}

int Valence::max_valence(){
    if(valence_par_points_trie.empty())
        throw std::runtime_error("tableau de valence vide!");
    return valence_par_points_trie.back();
}
