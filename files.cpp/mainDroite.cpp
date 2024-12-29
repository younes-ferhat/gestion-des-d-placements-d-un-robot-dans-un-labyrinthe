#include "../headers/mainDroite.h"
#include <iostream>

mainDroite::mainDroite(const Robot& robot, const terrain& terrain)
    : robotActuel(robot), labyrinthe(terrain), sortieTrouvee(false) {}

void mainDroite::tournerVersDroite() {
    robotActuel.tourneDroite();
}

void mainDroite::tournerVersGauche() {
    robotActuel.tourneGauche();
}

void mainDroite::avancerSiPossible() {
    if (!robotActuel.detectObstacle(labyrinthe)) {
        robotActuel.deplaceDevant();
    }
}

bool mainDroite::positionSortieAtteinte() const {
    return robotActuel.getPosition() == labyrinthe.getCaseArrivee();
}

void mainDroite::executer() {
    std::cout << "Début de la résolution du labyrinthe avec l'algorithme de la main droite." << std::endl;

    while (!sortieTrouvee) {
        if (positionSortieAtteinte()) {
            sortieTrouvee = true;
            std::cout << "Le robot a trouvé la sortie !" << std::endl;
            return;
        }

        tournerVersDroite();
        if (!robotActuel.detectObstacle(labyrinthe)) {
            avancerSiPossible();
        } else {
            tournerVersGauche();
            if (!robotActuel.detectObstacle(labyrinthe)) {
                avancerSiPossible();
            } else {
                tournerVersGauche();
            }
        }
    }
}

bool mainDroite::estSorti() const {
    return sortieTrouvee;
}
