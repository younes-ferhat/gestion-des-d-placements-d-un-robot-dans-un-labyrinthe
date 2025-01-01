#include "../headers/mainDroite.h"
#include <iostream>

mainDroite::mainDroite(const Robot& robot, const terrain &Terrain)
    : algorithmeSortie{robot,Terrain}
{}



void mainDroite::resoudre() {
    std::cout << "Début de la résolution du labyrinthe avec l'algorithme de la main droite." << std::endl;

    while (!estSortie()) {
      
        d_robot.tourneDroite();
        if (!d_robot.detectObstacle(d_terrain)) {
            d_robot.deplaceDevant();
        } else {
            d_robot.tourneGauche();
              if (!d_robot.detectObstacle(d_terrain)) {
               d_robot.deplaceDevant();
            } else {
                d_robot.tourneGauche();
            }
        }
    }
}

