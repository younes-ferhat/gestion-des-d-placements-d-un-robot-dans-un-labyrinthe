#ifndef ROBOT_H
#define ROBOT_H

#include <string>
#include <iostream>
#include <vector>
#include "Point.h"
#include "../headers/terrain.h"
class Robot {
public:
    enum Direction { NORD, EST, SUD, OUEST };

private:
    Point d_position;           // Position actuelle du robot 
    Direction d_direction;      // Direction actuelle du robot
    std::vector<Robot*> d_observateurs;  // Liste des observateurs du robot

public:
    Robot(Point startPosition, Direction startDirection);

    // getters de la position et la direction 
    Point getPosition() const;
    Direction getDirection() const;


    // Détection d'obstacles
    bool detectObstacleDevant(const terrain& Terrain);
    bool detectObstacleGauche(const terrain& Terrain) const;
    bool detectObstacleDroite(const terrain& Terrain) const;

    //Ajout des observateurs
    void ajouterObservateur(Robot* observateur);
     
    // Déplacement vers l'avant
    void deplaceDevant();

    // Tourner à gauche (90°)
    void tourneGauche();

    // Tourner à droite (90°)
    void tourneDroite();

    // Demi-tour (180°)
    void demiTour();

    // Notifier les observateurs des mouvements des robot
    void notifyMovement(const std::string& action); 
};

#endif
