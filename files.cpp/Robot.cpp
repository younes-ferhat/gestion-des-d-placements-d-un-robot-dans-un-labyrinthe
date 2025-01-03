#include "../headers/Robot.h"
#include "../headers/ObservateurRobot.h"

Robot::Robot(Point startPosition, Direction startDirection)
    : d_position{startPosition}, d_direction{startDirection},d_observateurs {} {}

Point Robot:: getPosition() const{
    return d_position;
}
Robot::Direction Robot:: getDirection() const {
    return d_direction;
}
Point Robot::getNextPosition(Direction direction) const {
    Point nextPosition = d_position;
    switch (direction) {
        case NORD: nextPosition.move(0, -1); break;
        case EST: nextPosition.move(1, 0); break;
        case SUD: nextPosition.move(0, 1); break;
        case OUEST: nextPosition.move(-1, 0); break;
    }
    return nextPosition;
}

// Méthode pour obtenir la direction à gauche
Robot::Direction Robot::getLeftDirection(Direction currentDirection) const {
    return static_cast<Direction>((currentDirection + 3) % 4);
}

// Méthode pour obtenir la direction à droite
Robot::Direction Robot::getRightDirection(Direction currentDirection) const {
    return static_cast<Direction>((currentDirection + 1) % 4);
}
bool Robot::detectObstacleDevant(const terrain& Terrain) const {
    Point nextPosition = getNextPosition(d_direction);
    return !Terrain.estAccessible(nextPosition);
}

// Vérification des obstacles à gauche
bool Robot::detectObstacleGauche(const terrain& Terrain) const {
    Point positionGauche = getNextPosition(getLeftDirection(d_direction));
    return !Terrain.estAccessible(positionGauche);
}

// Vérification des obstacles à droite
bool Robot::detectObstacleDroite(const terrain& Terrain) const {
    Point positionDroite = getNextPosition(getRightDirection(d_direction));
    return !Terrain.estAccessible(positionDroite);
}

void Robot::ajouterObservateur(std::shared_ptr<ObservateurRobot> observateur) {
    d_observateurs.push_back(observateur);
}
void Robot::notifierObservateurs(const std::string& action) {
    if (d_observateurs.empty()) {
    std::cerr << "Aucun observateur n'est enregistré pour le robot !" << std::endl;
}
   for (auto &observateur : d_observateurs) {
        observateur->notifier(action,*this);  // Passe une référence au robot
    }
}

void Robot::deplaceDevant(const terrain& Terrain) {
   
    switch (d_direction) {
        case NORD: d_position.move(0, -1); break;
        case EST: d_position.move(1, 0); break;
        case SUD: d_position.move(0, 1); break;
        case OUEST: d_position.move(-1, 0); break;
    }
    notifierObservateurs("avancé");
    
}

void Robot::tourneGauche(const terrain& Terrain) 
 {
    d_direction = getLeftDirection(d_direction);
    notifierObservateurs("tourné à gauche");
    
}

void Robot::tourneDroite(const terrain& Terrain) {
  
    d_direction = getRightDirection(d_direction);
    notifierObservateurs("tourné à droite");
}

void Robot::demiTour() {
    d_direction = static_cast<Direction>((d_direction + 2) % 4); // Inversion de direction
    notifierObservateurs("fait un demi-tour");
}







