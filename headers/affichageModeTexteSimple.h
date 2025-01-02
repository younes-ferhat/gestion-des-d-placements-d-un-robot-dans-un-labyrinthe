#ifndef AFFICHAGEMODETEXTESIMPLE_H
#define AFFICHAGEMODETEXTESIMPLE_H

#include "affichage.h"
#include <windows.h>
#include <iostream>

// Classe dérivée AffichageModeTexteSimple
class AffichageModeTexteSimple : public Affichage
{
public:
     
    AffichageModeTexteSimple();
    
    void afficherTerrain(const terrain &Terrain) override;
    void afficherRobot(const Robot &robot) override;
    void effacerRobot(const Point &anciennePosition) override;
    char getDirectionSymbole(const Robot &robot) const override;
};

#endif // AFFICHAGEMODETEXTESIMPLE_H
