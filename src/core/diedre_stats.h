#pragma once
#include "meshutilities.h"
#include "stats_utils.h"

#include <algorithm>
#include <functional>
#include <vector>

template <typename MeshType>
class DiedreStats
{
public:
    explicit DiedreStats( MeshType const& meshView )
        : meshView_{meshView}
    {
        computeDiedreAngles_();
    }

    // Default constructor is useless since we cannot change the
    // meshview later on (it is a reference so by definition it is const)
    DiedreStats() = delete;

    // calling the move constructor make sense here
    // since it will not cost too much
    // the default one should work out of the box
    // since we want the meshview pointer to be moved
    // (ie not the resources behind it)
    DiedreStats( DiedreStats&& ) = default;

    // but copy constructor will cost too much
    DiedreStats( DiedreStats const& ) = delete;



    float min() const { return min_; }
    float max() const { return max_; }

    float median() const { return median_; }

    float average() const { return average_; }


    auto begin() { return std::begin( anglesSorted_ ); }
    auto end() { return std::end( anglesSorted_ ); }

    auto cbegin() const { return std::cbegin( anglesSorted_ ); }
    auto cend() const { return std::cend( anglesSorted_ ); }

private:
    MeshType const& meshView_;

    void computeDiedreAngles_()
    {
        //
        anglesSorted_.reserve( meshView_.n_faces() );


        for ( auto edgeIt = meshView_.edges_begin(); edgeIt != meshView_.edges_end(); ++edgeIt )
        {
            if ( meshView_.is_boundary( *edgeIt ) )
            {
                continue;
            }

            auto nextFace = meshView_.face_handle( meshView_.halfedge_handle( *edgeIt, 0 ) );

            auto previousFace
                = meshView_.opposite_face_handle( meshView_.halfedge_handle( *edgeIt, 0 ) );


            anglesSorted_.push_back( angleBetweenFaces( meshView_, previousFace, nextFace ) );
        }

        std::transform( std::begin( anglesSorted_ ), std::end( anglesSorted_ ),
                        std::begin( anglesSorted_ ),
                        []( auto const& angle ) { return fmod( angle, M_PI ); } );

        std::sort( std::begin( anglesSorted_ ), std::end( anglesSorted_ ) );

        if ( anglesSorted_.size() == 0 )
            return;

        min_ = anglesSorted_.front();
        max_ = anglesSorted_.back();

        median_ = mediane_sorted( std::cbegin( anglesSorted_ ), std::cend( anglesSorted_ ) );

        average_ = moyenne( std::cbegin( anglesSorted_ ), std::cend( anglesSorted_ ) );
    }

    float min_{0.f};
    float max_{0.f};
    float median_{0.f};
    float average_{0.f};

    std::vector<float> anglesSorted_;
};
