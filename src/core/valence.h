#ifndef VALENCE_H
#define VALENCE_H

#include "mesh.h"
#include <vector>

class Valence
{
public:
    // pour chaque sommet est associé sa valence.
    std::vector<int> valence_par_points;
    std::vector<int> valence_par_points_trie;

    // constructeur par défaut.
    explicit Valence( const MeshT &mesh );

    // renvois la moyenne des valences des sommets du meshage.
    float moyenne_valence() const;

    float mediane_valence() const;

    int min_valence() const;

    int max_valence() const;

private:
    // effectue le remplissage du vector "valence_par_points".
    void valence_init( const MeshT &mesh );
};

#endif // VALENCE_H
