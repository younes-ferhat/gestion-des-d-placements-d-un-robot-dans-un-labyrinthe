#ifndef ROBOT_H
#define ROBOT_H

#include <string>
#include <iostream>
#include "Point.h"
#include "Terrain.h"

class Robot {
public:
    enum Direction { NORD, EST, SUD, OUEST };

private:
    Point d_position;           // Position actuelle du robot (utilisation de Point)
    Direction d_direction;      // Direction actuelle du robot

public:
    Robot(Point startPosition, Direction startDirection);

    // Déplacement vers l'avant
    void deplaceDevant();

    // Tourner à gauche (90°)
    void tourneGauche();

    // Tourner à droite (90°)
    void tourneDroite();

    // Demi-tour (180°)
    void demiTour();

    // Détection d'obstacle
    bool detectObstacle(const Terrain& terrain);

    // Méthode pour afficher les déplacements
    void notifyMovement(const std::string& action);
};

#endif
