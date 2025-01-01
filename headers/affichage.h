#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include "terrain.h"
#include "Robot.h"

// Classe abstraite Affichage
// Classe abstraite Affichage
class Affichage {
public:
    virtual ~Affichage() = default;


    void maj(const terrain &Terrain, const Robot &robot);
    virtual void afficherTerrain(const terrain &Terrain) =0;

    virtual void afficherRobot(const Robot& robot) = 0;
    virtual void effacerRobot(const Point& anciennePosition) = 0;
};
#endif  // AFFICHAGE_H
