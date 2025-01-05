#ifndef ALGOMAINEDROITE_H
#define ALGOMAINEDROITE_H

#include "../headers/Robot.h"
#include "../headers/terrain.h"
#include "./algorithmeSortie.h"
class mainDroite : public algorithmeSortie {

public:
    mainDroite(const Robot& robot, const terrain& Terrain);
     void resoudre( Affichage &affichage) override;

};

#endif // ALGOMAINEDROITE_H
