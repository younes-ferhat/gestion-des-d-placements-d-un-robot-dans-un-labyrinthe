#ifndef AFFICHAGEMODETEXTESIMPLE_H
#define AFFICHAGEMODETEXTESIMPLE_H

#include "affichage.h"
#include <windows.h>
#include <iostream>

// Classe dérivée AffichageModeTexteSimple
class AffichageModeTexteSimple : public Affichage
{
private:


public:
    void goto_xy(int x, int y);
     void afficherTerrain(const terrain &Terrain) override;

    AffichageModeTexteSimple(const terrain &Terrain, const Robot &robot);
    void afficherRobot(const Robot &robot) override;
    void effacerRobot(const Point &anciennePosition) override;
};


#endif // AFFICHAGEMODETEXTESIMPLE_H
