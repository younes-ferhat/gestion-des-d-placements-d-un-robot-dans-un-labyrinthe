#ifndef OBSERVATEUR_AFFICHAGE_H
#define OBSERVATEUR_AFFICHAGE_H

#include "ObservateurRobot.h"
#include <iostream>

// Déclaration de la classe ObservateurAffichage
class ObservateurAffichage : public ObservateurRobot {
public:
    void notifier(const std::string& action, const Robot& robot) override;
};

#endif
