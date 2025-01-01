#include "../headers/affichageModeTexteSimple.h"
#include <windows.h>
#include <cstdlib>



AffichageModeTexteSimple::AffichageModeTexteSimple() {
 
}

void AffichageModeTexteSimple::afficherTerrain(const terrain& Terrain) {
    int hauteur = Terrain.getHauteur();
    int largeur = Terrain.getLargeur();

    for (int y = 0; y < hauteur; ++y) {
        for (int x = 0; x < largeur; ++x) {
            goto_xy(x, y);
            if (!Terrain.estAccessible(Point(x, y))) {
                std::cout << "X" ;  // Affiche 'X' pour les obstacles
            } else {
                std::cout << ".";  // Affiche '.' pour les cases libres
            }
        }

    }
}



void AffichageModeTexteSimple::afficherRobot(const Robot& robot) {
    Point position = robot.getPosition();
    goto_xy(position.getX(), position.getY());

    std::cout<<robot.getDirectionSymbole()<< std::endl;  // Affiche le robot Ã  sa position
}

void AffichageModeTexteSimple::effacerRobot(const Point& anciennePosition) {
    goto_xy(anciennePosition.getX(), anciennePosition.getY());
     std::cout<< "."<< std::endl; // Remplacer par une case libre
}
