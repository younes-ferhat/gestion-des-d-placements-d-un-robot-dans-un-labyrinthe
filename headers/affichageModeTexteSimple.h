#ifndef AFFICHAGEMODETEXTESIMPLE_H
#define AFFICHAGEMODETEXTESIMPLE_H

#include "Affichage.h"
#include <windows.h>
#include <iostream>

// Classe dérivée AffichageModeTexteSimple
class AffichageModeTexteSimple : public Affichage
{
private:
    // void goto_xy(int x, int y);

    void afficherTerrain(const terrain &Terrain);

public:
    void goto_xy(int x, int y);
    AffichageModeTexteSimple(const terrain &Terrain, const Robot &robot);
    void afficherRobot(const Robot &robot) override;
    void effacerRobot(const Point &anciennePosition) override;
};

#endif // AFFICHAGEMODETEXTESIMPLE_H
