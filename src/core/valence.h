#ifndef VALENCE_H
#define VALENCE_H

#include "mesh.h"
#include <vector>
#include <iterator>

template <typename inputIT>
double moyenne(inputIT begin, inputIT end){
    double nb_element = std::distance(begin, end);
    double somme_all_valences = std::accumulate(begin, end, 0);

    return somme_all_valences/nb_element;
}

/** \pre trié entre begin et end.
*/
template <typename inputIT>
double mediane_sorted(inputIT begin, inputIT end){
    int nb_element = std::distance(begin, end);
    auto iter = begin;
    if ( nb_element % 2 == 1 )
        return *(iter+(nb_element+1)/2);
    else
    {
        int m = nb_element / 2, med = 0;
        iter += m;
        med += *iter;
        iter++;
        med += *iter;
        return med;
    }

}

/** \pre trié entre begin et end.
*/
template <typename inputIT>
int min_sorted(inputIT begin, inputIT end){
    auto last = end-1;
    return std::min(*begin, *last);
}

/** \pre trié entre begin et end.
*/
template <typename inputIT>
int max_sorted(inputIT begin, inputIT end){
    auto last = end-1;
    return std::max(*begin, *last);
}

class Valence
{
public:
    // pour chaque sommet est associé sa valence.

    std::vector<int> valence_triee;

    auto begin(){
        return std::begin(valence_triee);
    }
    auto end(){
        return std::end(valence_triee);
    }

    auto cbegin() const{
        return std::begin(valence_triee);
    }
    auto cend() const{
        return std::end(valence_triee);
    }

    // constructeur par défaut.
    explicit Valence( const MeshT &mesh );

    int getValenceOfPoint(int pointID) const;

    // renvois la moyenne des valences des sommets du meshage.


private:
    // effectue le remplissage du vector "valence_par_points".
    void valence_init( const MeshT &mesh );

    const MeshT meshview;
};

#endif // VALENCE_H
