#ifndef VALENCE_H
#define VALENCE_H

#include <vector>
#include "mesh.h"

class Valence
{
public:
    // pour chaque sommet est associé sa valence.
    std::vector<int> valence_par_points;
    std::vector<int> valence_par_points_trie;

    // constructeur par défaut.
    explicit Valence(const MeshT &mesh);

    // effectue le remplissage du vector "valence_par_points".
    void valence_init(const MeshT &mesh);

    // renvois la moyenne des valences des sommets du meshage.
    float moyenne_valence();

    float mediane_valence();

    int min_valence();

    int max_valence();

};

#endif // VALENCE_H
