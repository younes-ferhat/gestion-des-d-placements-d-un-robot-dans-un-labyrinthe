#ifndef AFFICHAGE_H
#define AFFICHAGE_H

#include "terrain.h"
#include "Robot.h"
#include <windows.h>
// Classe de Base Affichage

class Affichage {
public:
    virtual ~Affichage() = default;

    void goto_xy(int x, int y);
    void maj(const terrain &Terrain, const Robot &robot);
    virtual void afficherTerrain(const terrain &Terrain) =0;

    virtual void afficherRobot(const Robot& robot) = 0;
    virtual void effacerRobot(const Point& anciennePosition) = 0;
};
#endif  // AFFICHAGE_H
