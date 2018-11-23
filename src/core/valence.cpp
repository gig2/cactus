#include "valence.h"

using namespace std;

Valence::Valence( const MeshT &mesh )
{
    Valence::valence_init( mesh );
}

void Valence::valence_init( const MeshT &mesh )
{
    auto vIt = mesh.vertices_begin();
    while ( vIt != mesh.vertices_end() )
    {
        valence_triee.push_back( (int)mesh.valence( *vIt ) );
        vIt++;
    }

    std::sort( std::begin( valence_triee ), std::end( valence_triee ) );
}
