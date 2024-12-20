#ifndef ROBOT_H
#define ROBOT_H

#include <string>
#include <iostream>
#include "Point.h"
#include"C:\Users\amine\Desktop\Projet_lab\gestion-des-d-placements-d-un-robot-dans-un-labyrinthe\headers\terrain.h"

class Robot {
public:
    enum Direction { NORD, EST, SUD, OUEST };

private:
    Point d_position;           // Position actuelle du robot (utilisation de Point)
    Direction d_direction;      // Direction actuelle du robot

public:
    Robot(Point startPosition, Direction startDirection);
    // getters de la position et la direction 
    Point getPosition() const;
    Direction getDirection() const;


    // detecter obstacle a gauche et a droite
    bool detectObstacleGauche(const terrain& Terrain) const;
    bool detectObstacleDroite(const terrain& Terrain) const;
    // dessin du robot selon sa position
    void dessinerRobot(const terrain& Terrain) const;




    // Déplacement vers l'avant
    void deplaceDevant();

    // Tourner à gauche (90°)
    void tourneGauche();

    // Tourner à droite (90°)
    void tourneDroite();

    // Demi-tour (180°)
    void demiTour();

    // Détection d'obstacle
    bool detectObstacle(const terrain& Terrain);

    // Méthode pour afficher les déplacements
    void notifyMovement(const std::string& action);
};

#endif
