#ifndef VALENCE_H
#define VALENCE_H

#include "mesh.h"

#include "stats_utils.h"

#include <iterator>
#include <vector>


class Valence
{
public:
    // pour chaque sommet est associé sa valence.

    std::vector<int> valence_triee;

    auto begin() { return std::begin( valence_triee ); }
    auto end() { return std::end( valence_triee ); }

    auto cbegin() const { return std::begin( valence_triee ); }
    auto cend() const { return std::end( valence_triee ); }

    // constructeur par défaut.
    explicit Valence( const MeshT &mesh );

    // renvois la moyenne des valences des sommets du meshage.


private:
    // effectue le remplissage du vector "valence_par_points".
    void valence_init( const MeshT &mesh );
};

#endif // VALENCE_H
