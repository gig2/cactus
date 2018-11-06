#ifndef DROITE_H
#define DROITE_H


class Droite
{
private:
    //Vecteur directeur de la droite.
    int vx_,vy_,vz_;
    //On garde les coordonnées d'un point (fragment de la représentation paramétrique d'une droite)
    PointT pt_;
public:
    Droite();
    void set_vecteur_directeur(PointT ptA, PointT ptB);
    bool point_dans_droite(PointT p);
    float distance_point_droite(PointT p);
};

#endif // DROITE_H
