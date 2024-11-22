#ifndef MAINDROITE_H
#define MAINDROITE_H

#include "../headers/Robot.h"
#include "../headers/Terrain.h"

class MainDroite {
private:
    Robot d_robot;            // Robot utilisé pour le labyrinthe
    const Terrain& d_terrain; // Référence au terrain
    bool estSorti;            // Indique si le robot est sorti

    void tournerDroite();     // Gérer la rotation à droite
    void tournerGauche();     // Gérer la rotation à gauche
    void avancer();           // Déplacer le robot en avant

public:
    MainDroite(const Robot& robot, const Terrain& terrain);
    void resoudre();          // Algorithme de la main droite
    bool sortieAtteinte() const; // Vérifie si la sortie est atteinte
};

#endif
