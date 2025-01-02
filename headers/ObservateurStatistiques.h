#ifndef OBSERVATEUR_STATISTIQUES_H
#define OBSERVATEUR_STATISTIQUES_H

#include "../headers/ObservateurRobot.h"
#include <iostream>

class ObservateurStatistiques : public ObservateurRobot {
private:
    int compteurDeplacements = 0;  // Compteur de déplacements du robot

public:
    void notifier(const std::string& action, const Robot& robot) override;
    int getCompteurDeplacements() const;  // Méthode pour obtenir le compteur
};

#endif