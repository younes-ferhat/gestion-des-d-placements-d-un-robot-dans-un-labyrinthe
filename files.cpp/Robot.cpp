#include "../headers/Robot.h"
#include "../headers/terrain.h"

Robot::Robot(Point startPosition, Direction startDirection)
    : d_position{startPosition}, d_direction{startDirection} {}

Point Robot:: getPosition() const{
    return d_position;
}
Robot::Direction Robot:: getDirection() const {
    return d_direction;
}

void Robot::deplaceDevant(const terrain& Terrain) {
    if (detectObstacleDevant(Terrain)) {
        std::cout << "Obstacle détecté, déplacement annulé !\n";
        return;
    }
    else{
    switch (d_direction) {
        case NORD: d_position.move(0, -1); break;
        case EST: d_position.move(1, 0); break;
        case SUD: d_position.move(0, 1); break;
        case OUEST: d_position.move(-1, 0); break;
    }
    notifyMovement("avancé");
    }
}

void Robot::tourneGauche(const terrain& Terrain) {
    if (detectObstacleGauche(Terrain)) {
        std::cout << "Impossible de tourner à gauche, obstacle détecté.\n";
    }
    else{
    d_direction = static_cast<Direction>((d_direction + 3) % 4);
    notifyMovement("tourné à gauche");
    }
}

void Robot::tourneDroite(const terrain& Terrain) {
    if (detectObstacleDroite(Terrain)) {
        std::cout << "Impossible de tourner à droite, obstacle détecté.\n";
    }
    d_direction = static_cast<Direction>((d_direction + 1) % 4);
    notifyMovement("tourné à droite");
}

void Robot::demiTour() {
    d_direction = static_cast<Direction>((d_direction + 2) % 4); // Inversion de direction
    notifyMovement("fait un demi-tour");
}

bool Robot::detectObstacleDevant(const terrain& Terrain) {
    Point nextPosition = d_position; // Copie de la position actuelle
    switch (d_direction) {
        case NORD: nextPosition.move(0, -1); break;
        case EST: nextPosition.move(1, 0); break;
        case SUD: nextPosition.move(0, 1); break;
        case OUEST: nextPosition.move(-1, 0); break;
    }
    std::cout<< nextPosition.getX() << nextPosition.getY() <<" \n";
    return !Terrain.estAccessible(nextPosition);
}

bool Robot::detectObstacleGauche(const terrain& Terrain) const {
    // Calculer la position à gauche du robot en fonction de sa direction actuelle
    Point positionGauche = d_position;
    switch (d_direction) {
        case NORD: positionGauche.move(-1, 0); break; // Vers l'ouest
        case EST:  positionGauche.move(0, -1); break; // Vers le nord
        case SUD:  positionGauche.move(1, 0); break;  // Vers l'est
        case OUEST: positionGauche.move(0, 1); break; // Vers le sud
    }

    // Vérifier si la position est accessible
    return !Terrain.estAccessible(positionGauche);
}
bool Robot::detectObstacleDroite(const terrain& Terrain) const {
    // Calculer la position à droite du robot en fonction de sa direction actuelle
    Point positionDroite = d_position;
    switch (d_direction) {
        case NORD: positionDroite.move(1, 0); break;  // Vers l'est
        case EST:  positionDroite.move(0, 1); break;  // Vers le sud
        case SUD:  positionDroite.move(-1, 0); break; // Vers l'ouest
        case OUEST: positionDroite.move(0, -1); break; // Vers le nord
    }

    // Vérifier si la position est accessible
    return !Terrain.estAccessible(positionDroite);
}


void Robot::ajouterObservateur(Robot* observateur) {
    d_observateurs.push_back(observateur);
}


void Robot::notifyMovement(const std::string& action) {
    std::cout << "Robot principal - Action : " << action 
              << " - Position : (" << d_position.getX() 
              << ", " << d_position.getY() << ")\n";

    for (auto* obs : d_observateurs) {
        // L'observateur est informé
        std::cout << "Observateur notifié : " << action 
                  << " - Position actuelle de l'observateur : ("
                  << obs->getPosition().getX() << ", "
                  << obs->getPosition().getY() << ")\n";
    }
}


