#include "../headers/mainDroite.h"
#include <iostream>

MainDroite::MainDroite(const Robot& robot, const terrain& terrain)
    : d_robot(robot), d_terrain(terrain), estSorti(false) {}

void MainDroite::tournerDroite() {
    d_robot.tourneDroite();
}

void MainDroite::tournerGauche() {
    d_robot.tourneGauche();
}

void MainDroite::avancer() {
    if (!d_robot.detectObstacle(d_terrain)) {
        d_robot.deplaceDevant();
    }
}

void MainDroite::resoudre() {
    std::cout << "Début de la résolution du labyrinthe avec l'algorithme de la main droite." << std::endl;

    while (!estSorti) {
        // Vérifie si le robot est arrivé à la case d'arrivée
        /*if (d_robot == d_terrain.getCaseArrivee()) {
            estSorti = true;
            std::cout << "Le robot a trouvé la sortie !" << std::endl;
            return;
        }*/

        // Suivre la main droite
        tournerDroite(); // Essayer de tourner à droite
        if (!d_robot.detectObstacle(d_terrain)) {
            avancer();  // Avancer si possible
        } else {
            tournerGauche(); // Si bloqué, revenir à la direction initiale
            if (!d_robot.detectObstacle(d_terrain)) {
                avancer();  // Avancer si possible
            } else {
                tournerGauche(); // Si toujours bloqué, tourner à gauche
            }
        }
    }
}

bool MainDroite::sortieAtteinte() const {
    return estSorti;
}
