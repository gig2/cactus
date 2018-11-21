#pragma once
#include "meshutilities.h"

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

    float min() { return min_; }
    float max() { return max_; }

    float median() { return median_; }

    float average() { return average_; }


private:
    MeshType const& meshView_;

    void computeDiedreAngles_()
    {
        //
        anglesSorted_.reserve( meshView_.n_faces() );
        for ( auto faceIt = meshView_.faces_begin(); faceIt != meshView_.faces_end(); ++faceIt )
        {
            auto nextFace = std::next( faceIt );
            if ( nextFace == meshView_.faces_end() )
            {
                nextFace = meshView_.faces_begin();
            }

            anglesSorted_.push_back( angleBetweenFaces( meshView_, *faceIt, *nextFace ) );
        }

        std::sort( std::begin( anglesSorted_ ), std::end( anglesSorted_ ) );

        if ( anglesSorted_.size() == 0 )
            return;

        min_ = anglesSorted_.front();
        max_ = anglesSorted_.back();

        if ( anglesSorted_.size() % 2 == 1 )
        {
            auto const index = ( anglesSorted_.size() + 1 ) / 2 - 1;
            median_          = anglesSorted_[ index ];
        }
        else
        {
            auto const lower = anglesSorted_.size() / 2 - 1;
            auto const upper = lower + 1;
            median_          = ( anglesSorted_[ lower ] + anglesSorted_[ upper ] ) / 2.f;
        }

        auto const sumAngles
            = std::accumulate( std::begin( anglesSorted_ ), std::end( anglesSorted_ ), 0.f );

        average_ = sumAngles / anglesSorted_.size();
    }

    float min_{0.f};
    float max_{0.f};
    float median_{0.f};
    float average_{0.f};

    std::vector<float> anglesSorted_;
};
