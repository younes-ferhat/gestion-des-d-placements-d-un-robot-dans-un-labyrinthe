#ifndef ROBOT_H
#define ROBOT_H

#include <string>
#include <iostream>
#include <vector>
#include "Point.h"
#include "ObservateurRobot.h"
#include "terrain.h"
class Robot {
public:
    enum Direction { NORD, EST, SUD, OUEST };

private:
    Point d_position;           // Position actuelle du robot 
    Direction d_direction;      // Direction actuelle du robot
    std::vector<ObservateurRobot*> d_observateurs;  // Liste des observateurs
     // Méthodes pour obtenir la direction suivante
    Point getNextPosition(Direction direction) const;
    Direction getLeftDirection(Direction currentDirection) const;
    Direction getRightDirection(Direction currentDirection) const;

public:
    Robot(Point startPosition, Direction startDirection);

    // getters de la position et la direction 
    Point getPosition() const;
    Direction getDirection() const;


    // Détection d'obstacles
    bool detectObstacleDevant(const terrain& Terrain)const;
    bool detectObstacleGauche(const terrain& Terrain) const;
    bool detectObstacleDroite(const terrain& Terrain) const;

    // Méthodes de gestion des observateurs
    void ajouterObservateur(ObservateurRobot* observateur);
    void notifierObservateurs(const std::string& action);

     
    // Déplacement vers l'avant
    void deplaceDevant(const terrain& Terrain);

    // Tourner à gauche (90°)
    void tourneGauche(const terrain& Terrain);

    // Tourner à droite (90°)
    void tourneDroite(const terrain& Terrain);

    // Demi-tour (180°)
    void demiTour();

};

#endif
