#include "../headers/ObservateurAffichage.h"

// Implémentation de la méthode notifier
void ObservateurAffichage::notifier(const std::string& action, const Robot& robot) {
    Point position = robot.getPosition();
    std::string directionStr;
    
    switch (robot.getDirection()) {
        case Robot::NORD: directionStr = "NORD"; break;
        case Robot::EST: directionStr = "EST"; break;
        case Robot::SUD: directionStr = "SUD"; break;
        case Robot::OUEST: directionStr = "OUEST"; break;
    }

    std::cout << "Affichage : " << action 
              << " - Position : (" << position.getX() << ", " << position.getY() << ")"
              << " - Direction : " << directionStr << "\n";
}

