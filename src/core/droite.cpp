#include "droite.h"

Droite::Droite(PointT ptA, PointT ptB)
{
    set_vecteur_directeur(ptA, ptB);
    pt_ = ptA;
}

void Droite::set_vecteur_directeur(PointT ptA, PointT ptB){
    vx_ = ptA.x - ptB.x;
    vy_ = ptA.y - ptB.y;
    vz_ = ptA.z - ptB.z;
}

bool Droite::point_dans_droite(PointT p){
    //On obtient t en résolvant l'équation p.x = pt_.x + vx_ * t
    int t = p.x - pt_.x / vx_;
    int y = pt_.y + vy_ * t;
    int z = pt_.z + vz_ * t;
    if(y != p.y || z!= p.z){
        return false;
    }
    return true;
}

float Droite::distance_point_droite(PointT p){
    if(point_dans_droite(p)){
        return 0.0;
    }
    return 1.0;
}
