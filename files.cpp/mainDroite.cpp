#include "../headers/mainDroite.h"
#include <iostream>

mainDroite::mainDroite(const Robot& robot, const terrain &Terrain)
    : algorithmeSortie{robot,Terrain}
{}



void mainDroite::resoudre( Affichage &affichage) {


    while (!estSortie()) {

        d_robot.tourneDroite(d_terrain);
        if (!d_robot.detectObstacleDevant(d_terrain)) {
            d_robot.deplaceDevant(d_terrain);
            affichage.maj(d_terrain,d_robot);
            
        } else {
            d_robot.tourneGauche(d_terrain);
           affichage.maj(d_terrain,d_robot);
              if (!d_robot.detectObstacleDevant(d_terrain)) {
               d_robot.deplaceDevant(d_terrain);
              affichage.maj(d_terrain,d_robot);
            } else {
                d_robot.tourneGauche(d_terrain);
                affichage.maj(d_terrain,d_robot);
            }
        }
    }
}

