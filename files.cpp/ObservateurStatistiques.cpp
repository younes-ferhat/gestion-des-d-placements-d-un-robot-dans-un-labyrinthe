#include "../headers/ObservateurStatistiques.h"
#include"../headers/Robot.h"
#include <iostream>

void ObservateurStatistiques::notifier(const std::string& action, const Robot& robot) {
    compteurDeplacements++;

    Point position = robot.getPosition();
    std::string directionStr;

    switch (robot.getDirection()) {
        case Robot::NORD: directionStr = "NORD"; break;
        case Robot::EST: directionStr = "EST"; break;
        case Robot::SUD: directionStr = "SUD"; break;
        case Robot::OUEST: directionStr = "OUEST"; break;
    }

    std::cout << "Statistiques : " << action 
              << " - Déplacement n°" << compteurDeplacements
              << " - Position : (" << position.getX() << ", " << position.getY() << ")"
              << " - Direction : " << directionStr << "\n";
}

int ObservateurStatistiques::getCompteurDeplacements() const {
    return compteurDeplacements;
}
void ObservateurStatistiques::afficherStatistiquesFinales() const {
    std::cout << "\n--- Statistiques Finales ---\n";
    std::cout << "Nombre total de déplacements : " << compteurDeplacements << std::endl;
}

