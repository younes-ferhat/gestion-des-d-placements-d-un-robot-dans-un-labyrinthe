#ifndef ALGOMAINEDROITE_H
#define ALGOMAINEDROITE_H

#include "../headers/Robot.h"
#include "../headers/terrain.h"

class mainDroite {
private:
    Robot robotActuel;               // Robot utilisé dans le labyrinthe
    const terrain& labyrinthe;       // Référence au labyrinthe
    bool sortieTrouvee;              // Indique si le robot a trouvé la sortie

    void tournerVersDroite();
    void tournerVersGauche();
    void avancerSiPossible();
    bool positionSortieAtteinte() const;

public:
    mainDroite(const Robot& robot, const terrain& terrain);
    void executer();
    bool estSorti() const;
};

#endif // ALGOMAINEDROITE_H
